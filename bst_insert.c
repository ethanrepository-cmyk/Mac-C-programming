
#include<stdio.h>
#include<stdlib.h>

/*Using typedef to create aliases for pointers and function tupes*/
typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef Node* Treeptr;
typedef int (*Comparefunc)(int, int);

/*Helper function to create a new node*/
Treeptr createNode(int data) {
    Treeptr newNode = (Treeptr)malloc(sizeof(Node));
    if (newNode){
        newNode->data = data;
        newNode->left = newNode->right = NULL;
    }
    return newNode;
}

/*Logic for comparing two integers*/
int compareInt(int a, int b) {
    if(a<b) return -1;
    if(a>b) return 1;
    return 0;
}

/*BSt Insertion using the compare funtion pointer*/
Treeptr insert(Treeptr root, int data, Comparefunc cmp) {
    if(root==NULL) return createNode(data);

    int res = cmp(data, root->data);
    if(res<0) {
        root->left = insert(root->right,data,cmp);
    } else if (res>0) {
        root->right = insert(root->right, data, cmp);
    }
    return root;
}

/*In-order trasersal for verification*/
void inOrder(Treeptr root) {
    if(root==NULL) return;
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}

int main() {
    Treeptr root = NULL;

    /*Insertion data using the compareInt logic*/
    root = insert(root, 50, compareInt);
    insert(root, 30, compareInt);
    insert(root, 70, compareInt);
    insert(root, 20, compareInt);
    insert(root, 40, compareInt);

    printf("in-order Traversal Result: ");
    inOrder(root);
    printf("\n");

    return 0;
}