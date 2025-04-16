#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data, height;
    struct Node *left , *right;
}Node;


Node* createNode(int data){

    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->height = 0;
    node->left = node->right = NULL;
    }

int height(Node *n){
   if(n){ return n->height;
} 
else{
    return -1;
}
}


int max(int a , int b){
    if(a>b){
        return a;
    }

    if(b>a){
        return b;
    }
}

Node* rotateLeft(Node* x){
    Node* y = x->right;
    Node* t2 = y->left;
    y->left = x;
    x->right = y;
    x->height = max(height(x->left), height(x->right)+1);
    y->height = max(height(y->right), (y->left)+1);
    return y;

}

Node* rotateRight(Node* y){
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = x;
    x->height = max(height(x->left), height(x->right)+1);
    y->height = max(height(y->right), (y->left)+1);
    return x;
}


int getbalance(Node* node){
    if(node){
        return height(node->left) - height(node->right);
    }
}


Node* insertAVL(Node* node, int data){
    if(data > node->data){
       node->right = insertAVL(node->right, data);
    }
    if(data < node->data){
        node->left = insertAVL(node->left,data);
    }
    else 
    return node;
    

    
}