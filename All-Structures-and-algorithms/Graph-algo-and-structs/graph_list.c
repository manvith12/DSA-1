#include <stdio.h>
#include <stdlib.h>
#include "linear_queue.h"

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void print_graph(Node *adj[], int n)
{
    for (int i = 0; i < n; i++)
    {
        Node *temp = adj[i];
        printf("Adjacency list of vertex %d\n head ", i);
        while (temp)
        {
            printf("-> %d", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void build_graph(Node *adj[], int n)
{
    for (int i = 0; i < n; i++)
    {
        struct Node *last = NULL;
        int no;
        printf("Enter the number of neighbours for vertex %d: ", i);
        scanf("%d", &no);
        for (int j = 0; j < no; j++)
        {
            int data;
            printf("Enter neighbour %d: ", j + 1);
            scanf("%d", &data);
            Node *temp = createNode(data);
            if (last == NULL)
            {
                adj[i] = temp;
            }
            else
            {
                last->next = temp;
            }
            last = temp;
        }
    }
}

void bfs(Node *adj[], int n, int start)
{
    int visited[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    Queue queue;
    create_queue(&queue);

    printf("BFS starting from vertex %d: ", start);
    visited[start] = 1;
    enqueue(&queue, start);

    while (!isEmpty(&queue))
    {
        int current = dequeue(&queue);
        printf("%d ", current);

        Node *temp = adj[current];
        while (temp)
        {
            if (!visited[temp->data])
            {
                visited[temp->data] = 1;
                enqueue(&queue, temp->data);
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    Node *adj[n];
    for (int i = 0; i < n; i++)
    {
        adj[i] = NULL;
    }
    build_graph(adj, n);
    print_graph(adj, n);

    return 0;
}
