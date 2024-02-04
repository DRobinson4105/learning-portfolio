#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node Node;

struct Node {
    int data; // Data that node holds
    int bf; // Balance factor
    int depth; // Depth from root
    Node * left; // Pointer to left child
    Node * right; // Pointer to right child
    Node * parent; // Pointer to parent
};

// Dynamically allocate memory for node, initializing it with the given value
// Return the pointer to that node
Node * createNode(int data)
{
    Node * newNode = (Node *) malloc(sizeof(Node));

    newNode->data = data;
    newNode->bf = 0;
    newNode->depth = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;

    return newNode;
}

// Return the depth of a node
int getDepth(Node * cur)
{
    return (cur == NULL) ? 0 : cur->depth;
}

// Recalculates depth and balance factor of a node
void recalcDepth(Node * cur)
{
    // Check if the tree was empty
    if (cur == NULL) return;

    // Get the depth from the 2 children
    int leftDepth = getDepth(cur->left);
    int rightDepth = getDepth(cur->right);

    // Determine which side is deeper
    if (leftDepth > rightDepth)
        cur->depth = leftDepth + 1;
    else
        cur->depth = rightDepth + 1;

    // Update the balance factor
    cur->bf = leftDepth - rightDepth;
}

// Left rotation on a BST
void rotateLeft(Node * cur)
{
    // Can only rotate left if a right child exists
    if (cur->right == NULL) return;
    
    // Get reference pointers
    Node * parent = cur->parent;
    Node * child = cur->right;
    Node * grandchild = child->left;

    // Set up the three edges from top to bottom
    // Top
    child->parent = parent;

    if (parent != NULL)
    {
        // Determine which child of the parent the current node was originally
        if (parent->right == cur)
            parent->right = child;
        else
            parent->left = child;
    }

    // Middle
    child->left = cur;
    cur->parent = child;

    // Bottom
    cur->right = grandchild;

    if (grandchild != NULL)
        grandchild->parent = cur;

    // Recalculate the balance factors
    recalcDepth(cur);
    recalcDepth(child);    
}

// Right rotation on a BST
void rotateRight(Node * cur)
{
    // Can only rotate right if a left child exists
    if (cur->left == NULL) return;
    
    // Get reference pointers
    Node * parent = cur->parent;
    Node * child = cur->left;
    Node * grandchild = child->right;

    // Set up the three edges from top to bottom
    // Top
    child->parent = parent;

    if (parent != NULL)
    {
        // Determine which child of the parent the current node was originally
        if (parent->right == cur)
            parent->right = child;
        else
            parent->left = child;
    }

    // Middle
    child->right = cur;
    cur->parent = child;

    // Bottom
    cur->left = grandchild;

    if (grandchild != NULL)
        grandchild->parent = cur;

    // Recalculate the balance factors
    recalcDepth(cur);
    recalcDepth(child);    
}

// Rebalances a BST
Node * rebalance(Node * cur)
{
    // If tree is empty
    if (cur == NULL) return NULL;

    // Check if the balance factor is valid
    if (cur->bf >= -1 && cur->bf <= 1) return cur;

    // Check which case the imbalance is in
    if (cur->bf == 2) // Left Heavy
    {
        if (cur->left->bf == -1)
        {
            // Left Right Case
            rotateLeft(cur->left); 
        }
        
        // Left Left Case
        rotateRight(cur);
    }
    else // Right Heavy
    {
        if (cur->right->bf == 1)
        {
            // Right Left Case
            rotateRight(cur->right);
        }

        // Right Right Case
        rotateLeft(cur);
    }

    // Return the parent of the original node
    return cur->parent;
}

// Inserts a value into an AVL Tree, performing
// any rebalancing to make sure tree is balanced
Node * insert(Node * root, int value)
{
    // Empty tree case
    if (root == NULL) return createNode(value);

    if (value < root->data)
    {
        // Insert node into left branch
        root->left = insert(root->left, value);

        // Make sure that root is pointing to its parent
        root->left->parent = root;

        // Recalculate the depth of the node
        recalcDepth(root);
    }

    if (value > root->data)
    {
        // Insert node into right branch
        root->right = insert(root->right, value);

        // Make sure that root is pointing to its parent
        root->right->parent = root;

        // Recalculate the depth of the node c 
        recalcDepth(root);
    }

    // Return the root of the subtree after any potential rebalance
    return rebalance(root);
}

// Print BST in order
void printInOrderTree(Node * root)
{
    // Reached end of a branch
    if (root == NULL) return;
    
    // Print left branch
    printInOrderTree(root->left);
    
    // Print root
    printf("%d ", root->data);

    // Print right branch
    printInOrderTree(root->right);

    if (root->parent == NULL) printf("\n");
}

// Function to check if a value is contained
int contains(Node * root, int value)
{
    // If end of branch is reached
    if (root == NULL) return 0;

    // If value is found
    if (root->data == value) return 1;

    // If value is in left branch
    if (value < root->data)
        return contains(root->left, value);

    // If value is in right branch
    return contains(root->right, value);
}

Node * maxValueNode(Node * root)
{
    if (root->right == NULL)
        return root;
    
    return maxValueNode(root->right);
}

// Function to remove a value from an AVL tree
Node * removeNode(Node * root, int value)
{
    if (root == NULL) return NULL;
    if (value < root->data) {
        // Go left
        root->left = removeNode(root->left, value);
        recalcDepth(root);
    }
    if (value > root->data) {
        // Go right
        root->right = removeNode(root->right, value);
        recalcDepth(root);
    }
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
        Node * temp = maxValueNode(root->left);
        root->data = temp->data;
        root->left = removeNode(root->left, temp->data);
    }

    // Fix the tree
    return rebalance(root);
}

// Function to find the number of nodes in a tree
int getSize(Node * root)
{
    return (root == NULL) ? 0 : 1 + getSize(root->left) + getSize(root->right);
}

// Free all dynamic memory used in AVL tree
void freeTree(Node * root)
{
    if (root == NULL) return;

    freeTree(root->left);
    freeTree(root->right);

    free(root);
}

// The main function to test the the AVL functions
int main() {
    Node * root = NULL;
    // Insert 20 values
    for (int value = 0; value < 33; value++)
    {
        printf("Inserting %d...\n", value);
        root = insert(root, value);
        // Print the tree
        printInOrderTree(root);
    }

    // Remove all the values from the tree
    for (int i = 0; i < 33; i++) {
        if (contains(root, i)) {
            printf("Removing %d...\n", i);
            root = removeNode(root, i);

            // Print the tree in pre order
            printInOrderTree(root);
            printf("\n");
        }   
    }

    printInOrderTree(root);

    freeTree(root);

    return 0;
}
