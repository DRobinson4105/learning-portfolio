#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
    int flag; // Count of insertions
    Node * children[26]; // 26 children for 26 letters
};

Node * createNode()
{
    Node * node = (Node *) malloc(sizeof(Node));

    // Node is
    node->flag = 0;

    // Set child pointers
    for (int i = 0; i < 26; i++)
        node->children[i] = NULL;

    return node;
}

Node * insert(Node * root, char * str)
{
    if (root == NULL)
        root = createNode();

    // Loop to end of string
    Node * cur = root;
    int index;

    while (str[0] != '\0')
    {
        // Find the child index based on the letter
        int index = str[0] - 'a';

        // Create the child if it does not exist
        if (cur->children[index] == NULL)
            cur->children[index] = createNode();

        // Try moving to next child
        cur = cur->children[index];

        str++;
    }

    // At location to insert value
    cur->flag++;

    // Return the resulting root
    return root;
}

int countNodes(Node * root)
{
    if (root == NULL) return 0;

    int count = 1;
    
    for (int i = 0; i < 26; i++)
        count += countNodes(root->children[i]);

    return count;
}

void deleteTrie(Node * root)
{
    if (root == NULL) return;

    for (int i = 0; i < 26; i++)
        deleteTrie(root->children[i]);

    free(root);
}

int main()
{
    Node * root = NULL;
    root = insert(root, "alice");
    root = insert(root, "ali");
    root = insert(root, "andy");
    root = insert(root, "bobby");

    printf("Count: %d\n", countNodes(root));

    deleteTrie(root);
}