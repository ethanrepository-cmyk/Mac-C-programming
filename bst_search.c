#include <stdio.h>
#include <stdlib.h>

/* Structure definition for a BST node */
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

/* Function to create a new node in Heap memory */
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return NULL;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

/* Function to insert a node (Building the structure) */
Node* insert(Node* root, int data) {
    if (root == NULL) return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

/* * Core Logic: Searching for a specific value 
 * This demonstrates indirect access (->) to traverse memory addresses.
 */
Node* search(Node* root, int key) {
    /* Base Case: root is NULL (not found) or key is present at root */
    if (root == NULL || root->data == key) {
        return root;
    }

    /* Key is greater than root's data: Search in the right subtree */
    if (key > root->data) {
        return search(root->right, key);
    }

    /* Key is smaller than root's data: Search in the left subtree */
    return search(root->left, key);
}

int main() {
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);

    int target = 40;
    /* Perform Indirect Access to find the target address */
    Node* result = search(root, target);

    if (result != NULL) {
        printf("Element %d found at memory address: %p\n", target, (void*)result);
    } else {
        printf("Element %d not found in the tree.\n", target);
    }

    return 0;
}