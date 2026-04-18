#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef Node* Treeptr;

/*Create a new node*/

Treeptr createNode(int data) {
    Treeptr newNode = (Treeptr)malloc(sizeof(Node));
    if(newNode) {
        newNode->data = data;
        newNode->left = newNode->right = NULL;
    }
    return newNode;
}

/*Find the minimum value node in a subtree (Used for Case 3 of deletion)*/
Treeptr findMin(Treeptr node) {
    Treeptr current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;    
}

/*Delete a node from BST*/
Treeptr deleteNode(Treeptr root, int data) {
    if(!root) return root;

    /*1. Find the node to delete */
    if(data < root->data)
        root->left = deleteNode(root->left,data);
    else if(data > root->data)
        root->right = deleteNode(root->right, data);

    /*2. Node found! Handle 3 cases*/

    else {
        // Case 1 & 2 : No child or only one child
        if(root->left == NULL){
            Treeptr temp = root->right;
            free(root); //release hardware memoty//
            return temp;
        }

        else if (root->right == NULL) {
            Treeptr temp = root->left;
            free(root);
            return temp;
        }

        // Case 3 : Two children 
        // Get the inorder succesor (smallest in the right subtree)
        Treeptr temp = findMin(root->right);
        root->data = temp->data; // Copy the successor's data to this node
        root->right = deleteNode(root->right, temp->data); // Delete the successor
    }
    return root;
}

/* Bst Insettion and Inorder Traversal for testing*/
Treeptr insert(Treeptr root, int data) {
    if (root == NULL) return createNode(data);
    if (data < root->data) root->left = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data);
    return root;
}

void inOrder(Treeptr root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d ",root->data);
}

int main() {
    Treeptr root=NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);

    printf("Before deletion: ");
    inOrder(root);
    printf("\n");

    root = deleteNode(root, 30); // Test deleting node with two children

    printf("After deleting 30: ");
    inOrder(root);
    printf("\n");
    
    return 0;
}

