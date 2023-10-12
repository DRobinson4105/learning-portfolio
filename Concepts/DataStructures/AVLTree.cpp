#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    int data, bf, depth;
    Node *left, *right, *parent;
                
    Node(int x) : data(x), bf(0), depth(1), left(nullptr), 
                right(nullptr), parent(nullptr) {}
};

class Tree {
    public:
        Tree() : root(nullptr), sizeVal(0) {}

        void insert(int value) {
            this->root = insertNode(this->root, value);
            this->sizeVal++;
        }

        void remove(int value) {
            this->root = removeNode(this->root, value);
            sizeVal--;
        }

        bool includes(int value) {
            return includesNode(this->root, value);
        }

        string toString() {
            string res = "[";
            string nodes = getNodes(this->root);
            vector<char> nodeVec;

            for (char c : nodes)
                if (isdigit(c))
                    nodeVec.push_back(c);

            int len = nodeVec.size();
            for (int i = 0; i < len; i++) {
                res.append(to_string(nodeVec[i] - '0'));

                if (i < len - 1)
                    res.append(", ");
            }

            res.append("]");
            return res;
        }

        int size() {
            return this->sizeVal;
        }

    private:
        Node* root;
        int sizeVal;

        Node* insertNode(Node* root, int value) {
        if (root == nullptr) return new Node(value);

            if (value < root->data) {
                root->left = insertNode(root->left, value);

                root->left->parent = root;

                recalcDepth(root);
            } else if (value > root->data) {
                root->right = insertNode(root->right, value);

                root->right->parent = root;

                recalcDepth(root);
            }

            return rebalance(root);
        }

        int getDepth(Node* cur) {
            return (cur == nullptr) ? 0 : cur->depth;
        }

        void recalcDepth(Node* cur) {
            if (cur == nullptr) return;

            int leftDepth = getDepth(cur->left);
            int rightDepth = getDepth(cur->right);

            cur->depth = (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
            cur->bf = leftDepth - rightDepth;
        }

        void rotateLeft(Node* cur) {
            if (cur->right == nullptr) return;

            Node* parent = cur->parent;
            Node* child = cur->right;
            Node* grandchild = child->left;

            child->parent = parent;

            if (parent != nullptr) {
                if (parent->right == cur)
                    parent->right = child;
                else
                    parent->left = child;
            }

            child->left = cur;
            cur->parent = child;

            cur->right = grandchild;

            if (grandchild != nullptr)
                grandchild->parent = cur;

            recalcDepth(cur);
            recalcDepth(child);
        }

        void rotateRight(Node* cur) {
            if (cur->left == nullptr) return;

            Node* parent = cur->parent;
            Node* child = cur->left;
            Node* grandchild = child->right;

            child->parent = parent;

            if (parent != nullptr) {
                if (parent->right == cur)
                    parent->right = child;
                else
                    parent->left = child;
            }

            child->right = cur;
            cur->parent = child;

            cur->left = grandchild;

            if (grandchild != nullptr)
                grandchild->parent = cur;

            recalcDepth(cur);
            recalcDepth(child);
        }

        Node* rebalance(Node* cur) {
            if (cur == nullptr)
                return nullptr;

            if (abs(cur->bf) <= 1)
                return cur;

            if (cur->bf >= 2) {
                if (cur->left->bf == -1)
                    rotateLeft(cur->left);

                rotateRight(cur);
            } else {
                if (cur->right->bf == 1)
                    rotateRight(cur->right);

                rotateLeft(cur);
            }

            return cur->parent;
        }



        Node* maxValueNode(Node* root) {
            return (root->right == nullptr) ? root : root->right;
        }

        Node* removeNode(Node* root, int value) {
            if (root == nullptr) return nullptr;

            if (value < root->data) {
                root->left = removeNode(root->left, value);
                recalcDepth(root);
            } else if (value > root->data) {
                root->right = removeNode(root->right, value);
                recalcDepth(root);
            } else {
                if (root->left == nullptr) {
                    Node* temp = root->right;
                    delete(root);
                    return temp;
                }
                if (root->right == nullptr) {
                    Node* temp = root->left;
                    free(root);
                    return temp;
                }

                Node* temp = maxValueNode(root->left);
                root->data = temp->data;
                root->left = removeNode(root->left, temp->data);
            }

            return rebalance(root);
        }

        bool includesNode(Node* root, int value) {
            if (root == nullptr) return false;

            if (value < root->data)
                return includesNode(root->left, value);

            if (value > root->data)
                return includesNode(root->right, value);

            return true;
        }

        string getNodes(Node* root) {
            if (root == nullptr) return "";

            return getNodes(root->left) + " " + to_string(root->data) + getNodes(root->right);
        }


        void deleteTree(Node* root) {
            if (root == nullptr) return;

            deleteTree(root->left);
            deleteTree(root->right);

            delete(root);
        }
};



int main() {
    Tree* avlTree = new Tree();
    avlTree->insert(1);
    avlTree->insert(2);
    avlTree->insert(3);
    avlTree->insert(4);
    avlTree->insert(5);

    cout << avlTree->toString() << avlTree->size() << endl;

    return 0;
}