#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
    int data; // Data that node holds
    Node * left; // Pointer to left branch
    Node * right; // Pointer to right branch
};

// Dynamically allocate memory for node, initializing it with the given value
// Return the pointer to that node
Node * createNode(int value);

// Insert value into BST and return the new root of the BST
Node * insertNode(Node * root, int value);

// Remove value from BST and return the new root of the BST
Node * removeNode(Node * root, int value);

// Print BST in Post Order
void printPostOrderTree(Node * root);

// Print BST in order
void printInOrderTree(Node * root);

// Print BST in Pre Order
void printPreOrderTree(Node * root);

// Find lowest value node in BST
Node * minValueNode(Node * root);

// Find highest value node in BST
Node * maxValueNode(Node * root);

// Returns number of nodes in BST
int sizeofBST(Node * root);

// Frees all dynamic memory used for BST
void freeBST(Node * root);

// Returns a pointer to the node with the given value or NULL if node could not be found
Node * findNode(Node * root, int value);

// Return the max depth of BST from the given root
int getMaxDepth(Node * root);

int main()
{
    Node * root = NULL;
    root = insertNode(root, 2);
    root = insertNode(root, 6);
    root = insertNode(root, 3);
    root = insertNode(root, 7);
    root = insertNode(root, 1);
    root = insertNode(root, 4);
    root = insertNode(root, 5);

    printf("---In---\n");
    printInOrderTree(root);
    printf("---Post---\n");
    printPostOrderTree(root);
    printf("---Pre---\n");
    printPreOrderTree(root);

    printf("Size: %d\n", sizeofBST(root));

    root = removeNode(root, 5);
    root = removeNode(root, 2);
    root = removeNode(root, 6);

    printf("---In---\n");
    printInOrderTree(root);
    printf("---Post---\n");
    printPostOrderTree(root);
    printf("---Pre---\n");
    printPreOrderTree(root);

    printf("Size: %d\n", sizeofBST(root));

    freeBST(root);

    return 0;
}

Node * createNode(int value)
{
    // Create the node dynamically
    Node * newNode = (Node *) malloc(sizeof(Node));

    // Initialize data and pointers of node
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    // Return pointer to node
    return newNode;
}

Node * insertNode(Node * root, int value)
{
    // Add Node
    if (root == NULL) return createNode(value);

    // If value needs to be added to left branch of current node
    if (value < root->data)
        root->left  = insertNode(root->left, value);

    // If value needs to be added to right branch of current node
    else if (value > root->data)
        root->right = insertNode(root->right, value);

    // Do nothing if value already exists
    return root;
}

Node * removeNode(Node * root, int value)
{
    // Node was not found
    if (root == NULL) return NULL;

    // If the node was found
    if (root->data == value)
    {
        // If the node has zero children or only a right child
        if (root->left == NULL)
        {
            // Replace node with right child
            Node * temp = root->right;
            free(root);
            return temp;
        }

        // If the node only has a left child
        else if (root->right == NULL)
        {
            // Replace node with left child
            Node * temp = root->left;
            free(root);
            return temp;
        }

        // If the node has two children
        // Find which branch has the higher depth
        // Find closest value to root in that branch and replace the root with it
        Node * temp;

        if (getMaxDepth(root->left) > getMaxDepth(root->right))
        {
            temp = maxValueNode(root->left);
            root->data = temp->data;
            root->left = removeNode(root->left, temp->data);
        }
        else
        {
            temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = removeNode(root->right, temp->data);
        }
    }

    // If value is in left branch
    else if (value < root->data)
        root->left = removeNode(root->left, value);

    // If value is in right branch
    else
        root->right = removeNode(root->right, value);

    return root;
}

void printPostOrderTree(Node * root)
{
    // Reached end of a branch
    if (root == NULL) return;

    // Print left branch
    printPostOrderTree(root->left);

    // Print right branch
    printPostOrderTree(root->right);

    // Print root
    printf("%d\n", root->data);
}

void printInOrderTree(Node * root)
{
    // Reached end of a branch
    if (root == NULL) return;

    // Print left branch
    printInOrderTree(root->left);

    // Print root
    printf("%d\n", root->data);

    // Print right branch
    printInOrderTree(root->right);
}

void printPreOrderTree(Node * root)
{
    // Reached end of a branch
    if (root == NULL) return;

    // Print root
    printf("%d\n", root->data);

    // Print left branch
    printInOrderTree(root->left);

    // Print right branch
    printInOrderTree(root->right);
}

Node * minValueNode(Node * root)
{
    if (root->left == NULL)
        return root;
    
    return minValueNode(root->left);
}

Node * maxValueNode(Node * root)
{
    if (root->right == NULL)
        return root;
    
    return maxValueNode(root->right);
}

int sizeofBST(Node * root)
{
    if (root == NULL) return 0;

    return 1 + sizeofBST(root->left) + sizeofBST(root->right);
}

void freeBST(Node * root)
{
    if (root == NULL) return;

    freeBST(root->left);
    freeBST(root->right);

    free(root);
}

Node * findNode(Node * root, int value)
{
    // If value was not found
    if (root == NULL) return NULL;

    // If value is in left branch
    if (value < root->data)
        return findNode(root->left, value);

    // If value is in right branch
    if (value > root->data)
        return findNode(root->right, value);

    // If value was found
    return root;
}

int getMaxDepth(Node * root)
{
    // If end of branch was reached
    if (root == NULL) return 0;

    // Get the max depth of the left branch
    int left = getMaxDepth(root->left);

    // Get the max depth of the right branch
    int right = getMaxDepth(root->right);

    // Return the higher depth + one for the root node
    if (left > right)
        return 1 + left;

    return 1 + right;
}