#include<stdio.h>
#include<stdlib.h>

/*Self-referential structure for a Tree Node*/
typedef struct Node {
    int data;
    struct Node *left; /* Pointer to the left chilf (smaller values)*/
    struct Node *right; /* Pointer to the right child (larger values)*/
} Node;

/* Function to create a new node in the heap */
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memery allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL; /* Initialize left arm as NULL */
    newNode->right = NULL; /* Initial right arm as NULL */
    return newNode;;
}

/* Function to insert data using recursion ( Indirect Access via -> ) */
Node* insert(Node* root, int data) {
    /* If the tree is empty or reaches a leaf, create a new node */
    if(root == NULL) {
        return createNode(data);
    }

    /* Traversal logic based on BST property */
    if (data < root->data) {
        /* Move to the left child if data is smaller */
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        /* Move to the right child if data is larger */
        root->right = insert(root->right, data);
    }

    return root;
}

/* In-order traversal : left -> Root -> right */
void inorderTrasersal(Node* root) {
    if (root != NULL) {
        inorderTrasersal(root->left);
        printf("%d ", root->data);
        inorderTrasersal(root->right);
    }
}

int main() {
    Node* root = NULL;
    /* Build the tree */
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);

    /* Output the sorted result */
    printf("BST In-order Traversal: ");
    inorderTrasersal(root);
    printf("\n");

    return 0;
}