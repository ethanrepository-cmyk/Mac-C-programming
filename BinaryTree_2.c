#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//mid turning left -> me -> right 
void inOrder(Node* root){
    if(root==NULL) return;

    inOrder(root->left);
    printf("%d\t", root->data);
    inOrder(root->right);
}

int main(){
    Node* root = createNode(10);
    root->left = createNode(20);
    root->right = createNode(30);
    root->left->left = createNode(40);

    printf("In-order Traversal: ");
    inOrder(root);
    printf("\n");

}