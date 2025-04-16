#include <stdio.h>
#include <stdlib.h>

// Define structure for tree node
typedef struct TreeNode
{
    int data;
    struct TreeNode *firstChild;
    struct TreeNode *nextSibling;
} TreeNode;

// Function to create a new node
TreeNode *createNode(int data)
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->firstChild = NULL;
    newNode->nextSibling = NULL;
    return newNode;
}

// Function to add a child to a given parent node
void addChild(TreeNode *parent, int data)
{
    TreeNode *newNode = createNode(data);
    if (parent->firstChild == NULL)
    {
        parent->firstChild = newNode;
    }
    else
    {
        TreeNode *temp = parent->firstChild;
        while (temp->nextSibling != NULL)
        {
            temp = temp->nextSibling;
        }
        temp->nextSibling = newNode;
    }
}

// Function to print the tree (preorder traversal)
void printTree(TreeNode *root, int level)
{
    if (root == NULL)
        return;

    for (int i = 0; i < level; i++)
    {
        printf("  ");
    }
    printf("%d\n", root->data);

    printTree(root->firstChild, level + 1);
    printTree(root->nextSibling, level);
}

// Function to search for a node with a given value
TreeNode *search(TreeNode *root, int data)
{
    if (root == NULL)
        return NULL;
    if (root->data == data)
        return root;

    TreeNode *found = search(root->firstChild, data);
    if (found)
        return found;

    return search(root->nextSibling, data);
}

// Function to delete the tree
void deleteTree(TreeNode *root)
{
    if (root == NULL)
        return;
    deleteTree(root->firstChild);
    deleteTree(root->nextSibling);
    free(root);
}

int main()
{
    TreeNode *root = NULL;
    int choice, data, parentData;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Create Root\n");
        printf("2. Add Child\n");
        printf("3. Print Tree\n");
        printf("4. Search Node\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (root != NULL)
            {
                printf("Root already exists!\n");
            }
            else
            {
                printf("Enter root data: ");
                scanf("%d", &data);
                root = createNode(data);
            }
            break;
        case 2:
            if (root == NULL)
            {
                printf("Create the root first!\n");
            }
            else
            {
                printf("Enter parent node value: ");
                scanf("%d", &parentData);
                TreeNode *parent = search(root, parentData);
                if (parent == NULL)
                {
                    printf("Parent node not found!\n");
                }
                else
                {
                    printf("Enter child data: ");
                    scanf("%d", &data);
                    addChild(parent, data);
                }
            }
            break;
        case 3:
            if (root == NULL)
            {
                printf("Tree is empty!\n");
            }
            else
            {
                printf("Tree structure:\n");
                printTree(root, 0);
            }
            break;
        case 4:
            if (root == NULL)
            {
                printf("Tree is empty!\n");
            }
            else
            {
                printf("Enter value to search: ");
                scanf("%d", &data);
                TreeNode *found = search(root, data);
                if (found)
                {
                    printf("Node with value %d found!\n", data);
                }
                else
                {
                    printf("Node not found!\n");
                }
            }
            break;
        case 5:
            deleteTree(root);
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice!\n");
        }
    }
}
