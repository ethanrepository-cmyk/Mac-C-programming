#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;  
}Node;

//A function that create a new node
Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode) return NULL;

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main(){
    //1. Creating Node(allocated in a hip)
    Node* root = createNode(10);
    Node* node2 = createNode(20);
    Node* node3 = createNode(30);

    // Manual linking using a pointers(tree structure)
    root->left = node2;
    root->right = node3;

    //Checking result
    printf("Root data : %d\n", root->data);
    printf("Left Child: %d\n", root->left->data);
    printf("Right Child: %d\n", root->right->data);

    //Free Memoty
    free(node3);
    free(node2);
    free(root);
}
