#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data, height;
    struct Node *left, *right;
} Node;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(Node *n) {
    return n ? n->height : -1;
}

Node* createNode(int data) {
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    node->height = 0;
    return node;
}

Node* rotateRight(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

Node* rotateLeft(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

int getBalance(Node *node) {
    return node ? height(node->left) - height(node->right) : 0;
}

Node* insertAVL(Node* node, int data) {
    if (!node) return createNode(data);

    if (data < node->data)
        node->left = insertAVL(node->left, data);
    else if (data > node->data)
        node->right = insertAVL(node->right, data);
    else
        return node;

    node->height = max(height(node->left), height(node->right)) + 1;
    int balance = getBalance(node);

    // LL
    if (balance > 1 && data < node->left->data)
        return rotateRight(node);

    // RR
    if (balance < -1 && data > node->right->data)
        return rotateLeft(node);

    // LR
    if (balance > 1 && data > node->left->data) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // RL
    if (balance < -1 && data < node->right->data) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

void inorder(Node *root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void freeTree(Node *root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    Node *root = NULL;
    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < n; i++)
        root = insertAVL(root, arr[i]);

    printf("Inorder of AVL Tree (sorted): ");
    inorder(root);
    freeTree(root);
    return 0;
}
