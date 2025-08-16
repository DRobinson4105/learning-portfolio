#include "linear_regression.hpp"

class Tensor {
public:
    std::vector<double> value;
    Model* source;
    gradient_function_t gradient_function;

    Tensor(): value(std::vector<double>()), source(nullptr), gradient_function(nullptr) {}

    Tensor(std::vector<double> value): value(value), source(nullptr), gradient_function(nullptr) {}
    
    Tensor(std::vector<double> value, Model* source, gradient_function_t gradient_function):
        value(value), source(source), gradient_function(gradient_function) {}
};

class Dataset {
public:
    std::vector<double> input;
    std::vector<double> output;

    Dataset() {}

    Dataset(int start, int stop, double w, double b) {
        int n = stop - start;

        input = std::vector<double>(n);
        output = std::vector<double>(n);

        for (int i = 0; i < n; i++) {
            input[i] = i+start;
            output[i] = (i+start) * w + b;
        }
    }

    const std::pair<double, double> operator[](int index) {
        return {input[index], output[index]};
    }

    int size() {
        return input.size();
    }
};

class Model {
public:
    std::unordered_map<std::string, double> parameters;
    std::unordered_map<std::string, double> gradients;

    Model() {
        parameters["weight"] = (double)rand() / RAND_MAX;
        parameters["bias"] = (double)rand() / RAND_MAX;
    }

    Tensor operator()(std::vector<double> input) {
        std::vector<double> prediction(input.size());
        transform(input.begin(), input.end(), prediction.begin(), [this](double x) {
            return x * parameters["weight"] + parameters["bias"];
        });

        return Tensor(prediction, this, [input](std::vector<double> y_pred, std::vector<double> y_true) {
            std::unordered_map<std::string, double> grad;

            std::vector<double> diff(y_pred.size());
            transform(y_pred.begin(), y_pred.end(), y_true.begin(), diff.begin(), std::minus<>());

            grad["bias"] = accumulate(diff.begin(), diff.end(), 0.0);
            grad["weight"] = inner_product(diff.begin(), diff.end(), input.begin(), 0.0);

            grad["bias"] *= 2.0 / input.size();
            grad["weight"] *= 2.0 / input.size();

            return grad;
        });
    }
};

class MSELoss {
public:
    double operator()(Tensor y_pred, std::vector<double> y_true) {
        y_pred.source->gradients = y_pred.gradient_function(y_pred.value, y_true);

        return transform_reduce(y_pred.value.begin(), y_pred.value.end(), y_true.begin(), 0, std::plus<>(), [](double a, double b) {
            return pow(a - b, 2);
        }) / y_pred.value.size();
    }
};

class Optimizer {
    int patience, epochs;
    double lr, factor, best_loss;
    Model& model;
    Dataset dataset;

public:
    Optimizer(Model& model, Dataset dataset, double lr, double factor, int patience):
        model(model), dataset(dataset), lr(lr), factor(factor), patience(patience), epochs(0), best_loss(pow(2, 1027)) {}

    void step(double loss) {
        std::unordered_map<std::string, double> grad = model.gradients;

        for (auto [k, v] : grad) {
            model.parameters[k] -= lr * v;
        }

        if (loss < best_loss) {
            best_loss = loss;
            epochs = 0;
        } else if (loss == best_loss) {
            epochs++;
        }
        
        if (epochs >= patience) {
            lr *= factor;
            epochs = 0;
        }
    }
};

void printMap(std::unordered_map<std::string, double> m) {
    for (auto [k, v] : m) {
        printf("[\"%s\"]=%lf\n", k.c_str(), v);
    }
}

int main() {
    std::mt19937 gen(56);
    std::uniform_real_distribution<> dist(0.0, 1.0);

    Dataset data(0, 10, 3, 1);

    int epochs = 10000;
    double lr = 1e-3;
    double factor = 1;
    int patience = 10;

    Model model;
    Optimizer optim(model, data, lr, factor, patience);
    MSELoss criterion;

    Tensor y_pred;
    double loss;
    
    printf("Before Training:\n");
    printf("Parameters\n");
    printMap(model.parameters);
    y_pred = model(data.input);
    loss = criterion(y_pred, data.output);
    printf("Gradients\n");
    printMap(model.gradients);
    printf("Loss: %lf\n\n", loss);

    for (int i = 0; i < epochs; i++) {
        y_pred = model(data.input);
        loss = criterion(y_pred, data.output);
        optim.step(loss);
    }

    printf("After Training:\n");
    printf("Parameters\n");
    printMap(model.parameters);
    y_pred = model(data.input);
    loss = criterion(y_pred, data.output);
    printf("Gradients\n");
    printMap(model.gradients);
    printf("Loss: %lf\n", loss);

    return 0;
}