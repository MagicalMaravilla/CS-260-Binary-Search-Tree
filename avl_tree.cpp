#include <iostream>
#include <algorithm> // Included for max function

// Node structure for AVL Tree
struct Node {
    int value;      // The value of the node
    Node* left;     // Pointer to left child
    Node* right;    // Pointer to right child
    int height;     // Height of this node

    // Constructor to initialize node values
    Node(int val) : value(val), left(nullptr), right(nullptr), height(1) {}
};

// AVL Tree class
class AVLTree {
private:
    Node* root; // Root of the AVL Tree

    // Utility function to get the height of a node
    int height(Node* N) {
        if (N == nullptr) return 0;
        return N->height;
    }

    // Utility function to calculate the maximum depth of the tree
    int maxDepth(Node* node) {
        if (node == nullptr) return 0;
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);
        // Return the larger one
        return std::max(lDepth, rDepth) + 1;
    }

    // Utility function to update the height of a node
    int updateHeight(Node* N) {
        if (N == nullptr) return 0;
        return std::max(height(N->left), height(N->right)) + 1;
    }

    // Utility function to get balance factor of a node
    int getBalance(Node* N) {
        if (N == nullptr) return 0;
        return height(N->left) - height(N->right);
    }

    // Right rotate utility
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = updateHeight(y);
        x->height = updateHeight(x);
        return x;
    }

    // Left rotate utility
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = updateHeight(x);
        y->height = updateHeight(y);
        return y;
    }

    // Recursive function to insert a value in the AVL tree and rebalance it
    Node* addRecursive(Node* node, int value) {
        if (node == nullptr) return new Node(value);

        if (value < node->value) node->left = addRecursive(node->left, value);
        else if (value > node->value) node->right = addRecursive(node->right, value);
        else return node; // Duplicate values not allowed

        node->height = updateHeight(node);
        int balance = getBalance(node);

        // Left Left Case
        if (balance > 1 && value < node->left->value) return rightRotate(node);

        // Right Right Case
        if (balance < -1 && value > node->right->value) return leftRotate(node);

        // Left Right Case
        if (balance > 1 && value > node->left->value) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && value < node->right->value) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    // Recursive function to remove a node
    Node* removeRecursive(Node* root, int value) {
        if (root == nullptr) return root;

        if (value < root->value) root->left = removeRecursive(root->left, value);
        else if (value > root->value) root->right = removeRecursive(root->right, value);
        else {
            if ((root->left == nullptr) || (root->right == nullptr)) {
                Node* temp = root->left ? root->left : root->right;
                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                } else *root = *temp;
                delete temp;
            } else {
                Node* temp = minValueNode(root->right);
                root->value = temp->value;
                root->right = removeRecursive(root->right, temp->value);
            }
        }

        if (root == nullptr) return root;

        root->height = updateHeight(root);
        int balance = getBalance(root);

        // Balancing the tree
        if (balance > 1 && getBalance(root->left) >= 0) return rightRotate(root);
        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if (balance < -1 && getBalance(root->right) <= 0) return leftRotate(root);
        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    // Utility function to find the node with minimum value
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current->left != nullptr) current = current->left;
        return current;
    }

    // In-order traversal for display
    void inorderRecursive(Node* node) {
        if (node != nullptr) {
            inorderRecursive(node->left);
            std::cout << node->value << " ";
            inorderRecursive(node->right);
        }
    }

public:
    // Constructor initializing root as nullptr
    AVLTree() : root(nullptr) {}

    // Public method to add a value to the tree
    void add(int value) {
        root = addRecursive(root, value);
    }

    // Public method to remove a value from the tree
    void remove(int value) {
        root = removeRecursive(root, value);
    }

    // Public method for in-order traversal
    void inorder() {
        inorderRecursive(root);
        std::cout << std::endl;
    }

    // Public method to print the height of the tree
    void printHeight() {
        std::cout << "Tree Height: " << maxDepth(root) - 1 << "\n";
    }
};

// Main function to demonstrate AVL Tree operations
int main() {
    AVLTree tree;

    // Insert elements
    tree.add(10);
    tree.add(20);
    tree.add(30);
    tree.add(40);
    tree.add(50);
    tree.add(25);

    // Display tree
    std::cout << "Inorder traversal of the constructed AVL tree is \n";
    tree.inorder();

    // Display tree height
    tree.printHeight();

    return 0;
}
