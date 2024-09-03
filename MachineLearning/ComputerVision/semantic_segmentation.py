import torch
import matplotlib.pyplot as plt
import torch.nn as nn
from tqdm.auto import tqdm as notebook_tqdm
from torchvision.datasets import VOCSegmentation
from torch.utils.data import DataLoader, random_split
from torchvision import transforms
import torch.optim as optim
import torch.optim.lr_scheduler as lr_scheduler
from PIL import Image
import numpy as np
import torchvision.transforms.functional as TF
import torch.nn.functional as F
from pathlib import Path

torch.manual_seed(1234)
torch.cuda.manual_seed(1234)

# Path to models directory
MODEL_PATH = Path("models")
MODEL_PATH.mkdir(parents=True, exist_ok=True)
MODEL_NAME = "unet_model.pt"
MODEL_SAVE_PATH = MODEL_PATH / MODEL_NAME

device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
NUM_CLASSES=21

class UNet(nn.Module):
    def __init__(self, in_channels, out_channels):
        super(UNet, self).__init__()

        def double_convolution(in_channels, out_channels):
            return nn.Sequential(
                nn.Conv2d(in_channels, out_channels, kernel_size=3, padding=1),
                nn.BatchNorm2d(out_channels),
                nn.ReLU(inplace=True),
                nn.Conv2d(out_channels, out_channels, kernel_size=3, padding=1),
                nn.BatchNorm2d(out_channels),
                nn.ReLU(inplace=True)
            )

        self.downConv1 = double_convolution(in_channels, 64)
        self.downConv2 = double_convolution(64, 128)
        self.downConv3 = double_convolution(128, 256)
        self.downConv4 = double_convolution(256, 512)
        self.downConv5 = double_convolution(512, 1024)

        self.pool = nn.MaxPool2d(kernel_size=2, stride=2)

        self.up1 = nn.ConvTranspose2d(1024, 512, kernel_size=2, stride=2)
        self.up2 = nn.ConvTranspose2d(512, 256, kernel_size=2, stride=2)
        self.up3 = nn.ConvTranspose2d(256, 128, kernel_size=2, stride=2)
        self.up4 = nn.ConvTranspose2d(128, 64, kernel_size=2, stride=2)

        self.upConv1 = double_convolution(1024, 512)
        self.upConv2 = double_convolution(512, 256)
        self.upConv3 = double_convolution(256, 128)
        self.upConv4 = double_convolution(128, 64)

        self.out = nn.Conv2d(64, out_channels, kernel_size=1)

    def forward(self, X):
        d1 = self.downConv1(X)
        p1 = self.pool(d1)

        d2 = self.downConv2(p1)
        p2 = self.pool(d2)

        d3 = self.downConv3(p2)
        p3 = self.pool(d3)

        d4 = self.downConv4(p3)
        p4 = self.pool(d4)

        d5 = self.downConv5(p4)

        u1 = self.up1(d5)
        u1 = torch.cat((u1, d4), dim=1)
        u1 = self.upConv1(u1)

        u2 = self.up2(u1)
        u2 = torch.cat((u2, d3), dim=1)
        u2 = self.upConv2(u2)

        u3 = self.up3(u2)
        u3 = torch.cat((u3, d2), dim=1)
        u3 = self.upConv3(u3)

        u4 = self.up4(u3)
        u4 = torch.cat((u4, d1), dim=1)
        u4 = self.upConv4(u4)

        out = self.out(u4)
        return out

def mIoU(prediction: torch.Tensor, target: torch.Tensor):
    IoU = torch.zeros(NUM_CLASSES, device=device, dtype=torch.float)
    pred = prediction.argmax(dim=1)

    for i in range(NUM_CLASSES):
        c_pred = pred == i
        c_target = target == i

        intersection = (c_pred & c_target).sum()
        union = (c_pred | c_target).sum()
        IoU[i] = intersection / union

    return IoU.nanmean()

class AugmentData:
    def __call__(self, image, target):
        if torch.rand(1).item() < 0.25:
            image = TF.vflip(image)
            target = TF.vflip(target)

        if torch.rand(1).item() < 0.25:
            image = TF.hflip(image)
            target = TF.hflip(target)

        # rotate = torch.rand(1).item() * 20 - 10
        # image = TF.rotate(image.unsqueeze(0), rotate).squeeze(0)
        # target = TF.rotate(target.unsqueeze(0), rotate).squeeze(0)

        return image, target

class DiceLoss(nn.Module):
    def __init__(self):
        super(DiceLoss, self).__init__()

    def forward(self, input: torch.Tensor, target: torch.Tensor, eps=1e-7):
        dice = 0.0
        for c in range(NUM_CLASSES):
            input_flat = input[:, c].reshape(-1)
            target_flat = (target == c).float().view(-1)
            intersection = (input_flat * target_flat).sum()
            dice += (2. * intersection + eps) / (input.sum() + target_flat.sum() + eps)
        return 1 - dice / NUM_CLASSES
    
class FocalLoss(nn.modules.loss._WeightedLoss):
    def __init__(self, weight=None, gamma=2, reduction='mean', ignore_index=255):
        super(FocalLoss, self).__init__(weight, reduction=reduction)
        self.gamma = gamma
        self.weight = weight
        self.ignore_index = ignore_index

    def forward(self, input, target):
        ce_loss = F.cross_entropy(input, target, reduction=self.reduction, weight=self.weight, ignore_index=self.ignore_index) 
        pt = torch.exp(-ce_loss)
        focal_loss = ((1 - pt) ** self.gamma * ce_loss).mean()
        return focal_loss

class ToTensor:
    def __call__(self, x):
        return torch.from_numpy(np.array(x))

class CustomVOCDataset(VOCSegmentation):
    def __init__(self, root, year, image_set, download, extra_transforms=None):
        super().__init__(root, year, image_set, download, None)
        self.i_transform = transforms.Compose([
            transforms.Resize((256, 256), interpolation=Image.NEAREST),
            transforms.ToTensor(),
        ])
        self.t_transform = transforms.Compose([
            transforms.Resize((256, 256), interpolation=Image.NEAREST),
            ToTensor(),
        ])
        self.extra_transforms = extra_transforms

    def __getitem__(self, index):
        image, target = super().__getitem__(index)
        image, target = self.i_transform(image), self.t_transform(target)

        if self.extra_transforms is not None:
            image, target = self.extra_transforms(image, target)
        
        return image, target
        
if __name__ == "__main__":
    BATCH_SIZE = 16
    LEARNING_RATE = 1e-4
    EXTRA_TRANSFORMS = AugmentData()
    idx = 4

    print("Loading datasets...")

    dataset = CustomVOCDataset('./data', "2012", image_set='trainval', download=True, extra_transforms=EXTRA_TRANSFORMS)
    train_size = int(0.8 * len(dataset))
    val_size = len(dataset) - train_size
    
    train_dataset, val_dataset = random_split(dataset, [train_size, val_size])

    train_dataloader = DataLoader(train_dataset, batch_size=BATCH_SIZE, shuffle=True)
    test_dataloader = DataLoader(val_dataset, batch_size=BATCH_SIZE, shuffle=False)

    print("Creating class weights for loss...")

    weight = []

    for _, target in train_dataloader:
        weight.append(target)

    for _, target in test_dataloader:
        weight.append(target)

    weight = torch.cat(weight, dim=0).to(device=device, dtype=torch.long)
    weight = weight.flatten().bincount()[:NUM_CLASSES]
    weight[0] = int(weight[0] / 10)
    weight = 1.0 / weight
    weight /= weight.sum()

    print("Instantiating model and training loop functions")

    model = UNet(3, NUM_CLASSES).to(device)
    criterion = nn.CrossEntropyLoss(ignore_index=255, weight=weight)
    optimizer = optim.Adam(model.parameters(), lr=LEARNING_RATE, weight_decay=1e-4)
    scheduler = lr_scheduler.ReduceLROnPlateau(optimizer=optimizer)

    print("Running pre-training prediction...")

    color_map = torch.tensor([
        [0, 0, 0],
        [128, 0, 0],
        [0, 128, 0],
        [128, 128, 0],
        [0, 0, 128],
        [128, 0, 128],
        [0, 128, 128],
        [128, 128, 128],
        [64, 0, 0],
        [192, 0, 0],
        [64, 128, 0],
        [192, 128, 0],
        [64, 0, 128],
        [192, 0, 128],
        [64, 128, 128],
        [192, 128, 128],
        [0, 64, 0],
        [128, 64, 0],
        [0, 64, 128],
        [128, 64, 128],
        [0, 128, 64]
    ], device=device)

    def apply_color_map(segmentation_mask, color_map):
        height, width = segmentation_mask.shape
        rgb_image = torch.zeros((height, width, 3), device=device, dtype=torch.long)

        for class_index in range(len(color_map)):
            rgb_image[segmentation_mask == class_index] = color_map[class_index]

        rgb_image[segmentation_mask == 255] = torch.tensor([0, 0, 0], device=device)
        return rgb_image

    X = next(iter(train_dataloader))

    with torch.inference_mode():
        pretrain_pred = model(X[0].to(device))

    print("Training...")

    epochs = 200
    train_loss_values = []
    test_loss_values = []
    train_acc_values = []
    test_acc_values = []
    last_train, last_test, best_train, best_test = None, None, 0, 0

    for epoch in range(epochs):
        avg_train_loss, avg_test_loss = 0, 0
        avg_train_acc, avg_test_acc = 0, 0

        model.train()

        for image, target in notebook_tqdm(train_dataloader, desc="Training", leave=False):
            image, target = image.to(device), target.to(device)
            
            optimizer.zero_grad()

            pred = model(image)
            loss = criterion(pred, target.long())
            acc = mIoU(pred, target)

            avg_train_loss += loss.item()
            avg_train_acc += acc.item()

            loss.backward()
            optimizer.step()

        model.eval()

        with torch.inference_mode():
            for image, target in notebook_tqdm(test_dataloader, desc="Testing", leave=False):
                image, target = image.to(device), target.to(device)

                pred = model(image)

                loss = criterion(pred, target.long())
                acc = mIoU(pred, target)

                avg_test_loss += loss.item()
                avg_test_acc += acc.item()

        avg_train_loss /= len(train_dataloader)
        avg_test_loss /= len(test_dataloader)
        avg_train_acc /= len(train_dataloader)
        avg_test_acc /= len(test_dataloader)

        last_train = avg_train_acc
        last_test = avg_test_acc

        if avg_test_acc > best_test:
            best_test = avg_test_acc
            best_train = avg_train_acc

        msg = f"Epoch: {epoch} | Train Loss: {avg_train_loss} | Test Loss: {avg_test_loss} | Train Accuracy: {avg_train_acc} | Test Accuracy: {avg_test_acc}"

        with open('train_log.txt', 'a') as file:
            file.write(msg + "\n")
            
        print(msg)
        scheduler.step(avg_train_loss)

        train_loss_values.append(avg_train_loss)
        test_loss_values.append(avg_test_loss)
        train_acc_values.append(avg_train_acc)
        test_acc_values.append(avg_test_acc)

    print("Plotting loss and accuracy curves...")

    plt.figure(figsize=(12, 6))
    plt.subplot(1, 2, 1)
    plt.title("Loss")
    plt.plot(range(epochs), train_loss_values, label="Train")
    plt.plot(range(epochs), test_loss_values, label="Test")
    plt.legend()
    plt.subplot(1, 2, 2)
    plt.title("Accuracy")
    plt.plot(range(epochs), train_acc_values, label="Train")
    plt.plot(range(epochs), test_acc_values, label="Test")
    plt.legend()
    plt.savefig(f'loss/loss{idx}.png')

    print("Running post-training prediction...")

    with torch.inference_mode():
        posttrain_pred = model(X[0].to(device))

    pre_prediction = apply_color_map(pretrain_pred[0].argmax(dim=0), color_map)
    post_prediction = apply_color_map(posttrain_pred[0].argmax(dim=0), color_map)
    target = apply_color_map(X[1][0].squeeze(), color_map)

    plt.figure(figsize=(20, 10))
    plt.subplot(1, 4, 1)
    plt.imshow(X[0][0].permute(1, 2, 0).squeeze().cpu().numpy())
    plt.axis('off')
    plt.title('Original')
    plt.subplot(1, 4, 2)
    plt.imshow(target.cpu().numpy())
    plt.axis('off')
    plt.title('Target')
    plt.subplot(1, 4, 3)
    plt.imshow(pre_prediction.cpu().numpy())
    plt.axis('off')
    plt.title('Prediction before Training')
    plt.subplot(1, 4, 4)
    plt.imshow(post_prediction.cpu().numpy())
    plt.axis('off')
    plt.title('Prediction after Training')
    plt.savefig(f'predictions/predictions{idx}.png')

    with open("result.txt", 'a') as file:
        file.write(f"{idx} -> {last_train=} {last_test=} {best_train=} {best_test=}\n")

    print(f"Saving model to: {MODEL_SAVE_PATH}")
    torch.save(obj=model.state_dict(), f=MODEL_SAVE_PATH)