class Node {
    int data;
    boolean color;
    Node left, right, parent;
    
    static boolean RED = true, BLACK = false;
  
    public Node(int data, boolean color) {
        this.data = data;
        this.color = color;
    }
}

class NilNode extends Node {
    NilNode() {
      super(0, Node.BLACK);
    }
}

public class RedBlackTree {
    Node root;

    public boolean contains(int key) {
        Node node = root;

        while (node != null) {
            if (key == node.data)
                return true;
            else if (key < node.data)
                node = node.left;
            else
                node = node.right;
        }
      
        return false;
    }

    public void insert(int key) {
        Node node = root;
        Node parent = null;
      
        // Traverse the tree to the left or right depending on the key
        while (node != null) {
            parent = node;
            if (key < node.data)
                node = node.left;
            else if (key > node.data)
                node = node.right;
            else return;
        }
      
        // Insert new node
        Node newNode = new Node(key, Node.RED);
        if (parent == null)
            root = newNode;
        else if (key < parent.data)
            parent.left = newNode;
        else
            parent.right = newNode;
        
        newNode.parent = parent;
      
        fixPropertiesAfterInsertion(newNode);
    }

    public void delete(int key) {
        Node node = root;

        // Find node
        while (node != null && node.data != key) {
            if (key < node.data)
                node = node.left;
            else
                node = node.right;
        }

        // Node is not in tree
        if (node == null) {
            return;
        }
        
        Node movedUpNode;
        boolean deletedNodeColor;

        // Node does not have two children
        if (node.left == null || node.right == null) {
            movedUpNode = deleteNodeWithZeroOrOneChild(node);
            deletedNodeColor = node.color;
        }

        // Node has two children
        else {
            // Find minimum node of right subtree
            Node inOrderSuccessor = findMinimum(node.right);

            // Replace node with inorder successor
            node.data = inOrderSuccessor.data;

            // Delete inorder successor
            movedUpNode = deleteNodeWithZeroOrOneChild(inOrderSuccessor);
            deletedNodeColor = inOrderSuccessor.color;
        }

        // Properties need to be fixed
        if (deletedNodeColor == Node.BLACK) {
            fixPropertiesAfterDeletion(movedUpNode);

            // Remove the temporary NIL node
            if (movedUpNode.getClass() == NilNode.class) {
                replaceParentsChild(movedUpNode.parent, movedUpNode, null);
            }
        }
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        inOrderTraversalToString(sb, root);
        return sb.toString();
    }

    private void inOrderTraversalToString(StringBuilder sb, Node node) {
        if (node == null) return;

        inOrderTraversalToString(sb, node.left);

        sb.append(node.data + " ");

        inOrderTraversalToString(sb, node.right);
    }

    private void fixPropertiesAfterDeletion(Node node) {
        if (node == root) {
            node.color = Node.BLACK;
            return;
        }
      
        Node sibling = getSibling(node);
      
        // Node has red sibling
        if (sibling.color == Node.RED) {
            handleRedSibling(node, sibling);
            sibling = getSibling(node);
        }
      
        // Node has black sibling with two black children
        if (isBlack(sibling.left) && isBlack(sibling.right)) {
            sibling.color = Node.RED;
        
            if (node.parent.color == Node.RED)
                node.parent.color = Node.BLACK;
            else
                fixPropertiesAfterDeletion(node.parent);
        }
      
        // Node has black sibling with at least one red child
        else handleBlackSiblingWithAtLeastOneRedChild(node, sibling);
    }

    private void handleBlackSiblingWithAtLeastOneRedChild(Node node, Node sibling) {
        boolean nodeIsLeftChild = node == node.parent.left;
      
        if (nodeIsLeftChild && isBlack(sibling.right)) {
            sibling.left.color = Node.BLACK;
            sibling.color = Node.RED;
            rotateRight(sibling);
            sibling = node.parent.right;
        } else if (!nodeIsLeftChild && isBlack(sibling.left)) {
            sibling.right.color = Node.BLACK;
            sibling.color = Node.RED;
            rotateLeft(sibling);
            sibling = node.parent.left;
        }
      
        sibling.color = node.parent.color;
        node.parent.color = Node.BLACK;

        if (nodeIsLeftChild) {
            sibling.right.color = Node.BLACK;
            rotateLeft(node.parent);
        } else {
            sibling.left.color = Node.BLACK;
            rotateRight(node.parent);
        }
    }

    private Node getSibling(Node node) {
        Node parent = node.parent;

        if (node == parent.left)
            return parent.right;
        else if (node == parent.right)
            return parent.left;

        return null;
    }
      
    private boolean isBlack(Node node) {
        return node == null || node.color == Node.BLACK;
    }

    private void handleRedSibling(Node node, Node sibling) {
        sibling.color = Node.BLACK;
        node.parent.color = Node.RED;
      
        if (node == node.parent.left)
            rotateLeft(node.parent);
        else
            rotateRight(node.parent);
    }

    private Node findMinimum(Node node) {
        return node.left != null ? findMinimum(node.left) : node;
    }

    private Node deleteNodeWithZeroOrOneChild(Node node) {
        // Node has left child
        if (node.left != null) {
            replaceParentsChild(node.parent, node, node.left);
            return node.left;
        }
      
        // Node has right child
        else if (node.right != null) {
            replaceParentsChild(node.parent, node, node.right);
            return node.right;
        }
      
        // Node has zero children
        else {
            Node newChild = node.color == Node.BLACK ? new NilNode() : null;
            replaceParentsChild(node.parent, node, newChild);
            return newChild;
        }
    }

    private void fixPropertiesAfterInsertion(Node node) {
        Node parent = node.parent;
      
        // Node is root
        if (parent == null) {
            node.color = Node.BLACK;
            return;
        }
      
        // Parent is black
        if (parent.color == Node.BLACK) return;
      
        Node grandparent = parent.parent;
      
        if (grandparent == null) {
            parent.color = Node.BLACK;
            return;
        }
      
        Node uncle = getUncle(parent);
      
        // Uncle is red -> recolor parent, grandparent and uncle
        if (uncle != null && uncle.color == Node.RED) {
            parent.color = Node.BLACK;
            grandparent.color = Node.RED;
            uncle.color = Node.BLACK;
        
            fixPropertiesAfterInsertion(grandparent);
        }
      
        // Parent is left child of grandparent
        else if (parent == grandparent.left) {
            if (node == parent.right) {
                rotateLeft(parent);
                parent = node;
            }

            rotateRight(grandparent);
        
            parent.color = Node.BLACK;
            grandparent.color = Node.RED;
        }
      
        // Parent is right child of grandparent
        else {
            if (node == parent.left) {
                rotateRight(parent);
                parent = node;
            }
        
            rotateLeft(grandparent);
        
            parent.color = Node.BLACK;
            grandparent.color = Node.RED;
        }
    }

    private Node getUncle(Node parent) {
        Node grandparent = parent.parent;

        if (grandparent.left == parent)
            return grandparent.right;
        else if (grandparent.right == parent)
            return grandparent.left;

        return null;
    }

    private void rotateRight(Node node) {
        Node parent = node.parent;
        Node leftChild = node.left;
      
        node.left = leftChild.right;
        if (leftChild.right != null)
            leftChild.right.parent = node;
      
        leftChild.right = node;
        node.parent = leftChild;
      
        replaceParentsChild(parent, node, leftChild);
    }

    private void rotateLeft(Node node) {
        Node parent = node.parent;
        Node rightChild = node.right;
      
        node.right = rightChild.left;
        if (rightChild.left != null)
            rightChild.left.parent = node;
      
        rightChild.left = node;
        node.parent = rightChild;
      
        replaceParentsChild(parent, node, rightChild);
    }

    private void replaceParentsChild(Node parent, Node oldChild, Node newChild) {
        if (parent == null)
            root = newChild;
        else if (parent.left == oldChild)
            parent.left = newChild;
        else if (parent.right == oldChild)
            parent.right = newChild;
      
        if (newChild != null)
          newChild.parent = parent;
    }

    public static void main(String[] args) {
        RedBlackTree tree = new RedBlackTree();

        for (int i = 0; i < 20; i += 3) {
            tree.insert(i);
        }

        System.out.println(tree);

        for (int i = 0; i < 20; i += 2) {
            tree.delete(i);
        }

        System.out.println(tree);
    }
}