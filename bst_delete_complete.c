#include <stdio.h>
#include <stdlib.h>

/* Binary Search Tree Node structure */
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

/* Function to allocate memory for a new node */
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

/* Recursive function to insert a node */
Node* insert(Node* root, int data) {
    if (root == NULL) return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

/* Find the leftmost leaf in the right subtree */
Node* getSuccessor(Node* curr) {
    curr = curr->right;
    while (curr != NULL && curr->left != NULL)
        curr = curr->left;
    return curr;
}

/* Core Logic: Deleting a node and maintaining BST property */
Node* deleteNode(Node* root, int key) {
    /* Base case: address is NULL */
    if (root == NULL) return root;

    /* Recursive search for the node to delete */
    if (root->data > key)
        root->left = deleteNode(root->left, key);
    else if (root->data < key)
        root->right = deleteNode(root->right, key);
    else {
        /* Case 1: Node has no children (Leaf) or Case 2: Only one child */
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root); /* Hardware: Memory deallocation from Heap */
            return temp;
        }
        if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        /* Case 3: Node has two children */
        /* Get the smallest value in the right subtree */
        Node* succ = getSuccessor(root);
        root->data = succ->data;
        /* Delete the successor node's previous address */
        root->right = deleteNode(root->right, succ->data);
    }
    return root;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);

    printf("Before deletion (Inorder): ");
    inorder(root);
    printf("\n");

    /* Delete node with value 30 (Case 3: has 20 and 40 as children) */
    root = deleteNode(root, 30);

    printf("After deleting 30 (Inorder): ");
    inorder(root);
    printf("\n");

    return 0;
}