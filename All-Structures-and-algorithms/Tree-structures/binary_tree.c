#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    Node* left;
    Node*right;
    int data;
}Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node*root,int data){
    if(!root){
        return createNode(data);
    }
    if (!root->left) {
        root->left = createNode(data);
    } else if (!root->right) {
        root->right = createNode(data);
    } else {
        insert(root->left, data);
    }
    return root;
}

void search(Node* root, int data) {
    if (root == NULL) {
        printf("Node not found\n");
        return;
    }
    if (root->data == data) {
        printf("Node found: %d\n", root->data);
        return;
    }
    search(root->left, data);
    search(root->right, data);
}

void freeTree(Node* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

void inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void deleteNode(Node* root, int data) {
    if (root == NULL) {
        return;
    }
    if (root->data == data) {
        free(root);
        return;
    }
    deleteNode(root->left, data);
    deleteNode(root->right, data);
}

