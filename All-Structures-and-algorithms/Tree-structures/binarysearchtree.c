#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *left, *right;
}Node;

Node* createNode(int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left  = newNode->right = NULL;
    return newNode;
}

Node* insert(Node *root, int val){
    if(root == NULL) return createNode(val);
    if(val < root->data){
        root->left = insert(root->left, val);
    } else if (val > root->data){
        root->right = insert(root->right, val);
    }
    return root;
}


int search(Node *root, int val){
    if(root == NULL) return 0;
    if(root->data == val) return 1;
    if(val < root->data) return search(root->left, val);
    return search(root->right, val);

}

int height(Node *root){
    if(!root) return 0;
    int l = height(root->left);
    int r = height(root->right);
    return 1 + (l>r ? l : r);
}


int countNodes(Node *root){
    if(root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void inorder(Node *root){
    if(!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(Node *root){
    if(!root) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root){
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void mirror(Node *root){
    if(!root) return;
    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirror(root->left);
    mirror(root->right);
}

Node* findMin(Node *root){
    if(root == NULL)return NULL;
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}
Node* findMax(Node *root){
    if(root == NULL)return NULL;
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}

Node* delete(Node *root, int val){
    if(root == NULL) return NULL;
    if(val < root->data){
        root->left = delete(root->left, val);
    } else if(val > root->data){
        root->right = delete(root->right, val);
    } else {
        if(root->left == NULL){
            Node *temp = root->right;
            free(root);
            return temp;
        } else if(root->right == NULL){
            Node *temp = root->left;
            free(root);
            return temp;
        }
        Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
}

void levelOrder(Node* root){
    if(!root) return;
    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while(front < rear){
        Node* current = queue[front++];
        printf("%d ", current->data);
        if(current->left) queue[rear++] = current->left;
        if(current->right) queue[rear++] = current->right;
    }
}