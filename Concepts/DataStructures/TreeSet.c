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

// Insert value into set and return the new root of the set
Node * insertNode(Node * root, int value);

// Remove value from set and return the new root of the set
Node * removeNode(Node * root, int value);

// Print set in order
void printSet(Node * root);

// Returns number of nodes in set
int sizeofSet(Node * root);

// Frees all dynamic memory used for set
void freeSet(Node * root);

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

    printSet(root);

    printf("Size: %d\n", sizeofBST(root));

    root = removeNode(root, 5);
    root = removeNode(root, 2);
    root = removeNode(root, 6);

    printSet(root);

    printf("Size: %d\n", sizeofBST(root));

    freeSet(root);

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

void printSet(Node * root)
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

int sizeofSet(Node * root)
{
    if (root == NULL) return 0;

    return 1 + sizeofBST(root->left) + sizeofBST(root->right);
}

void freeSet(Node * root)
{
    if (root == NULL) return;

    freeBST(root->left);
    freeBST(root->right);

    free(root);
}