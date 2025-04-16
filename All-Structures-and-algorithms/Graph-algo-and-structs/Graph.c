#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct Node {
    int dest;
    struct Node* next;
} Node;

typedef struct Graph {
    int V;
    Node** adjList;
    bool* visited;
} Graph;

Node* createNode(int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->adjList = (Node**)malloc(V * sizeof(Node*));
    graph->visited = (bool*)malloc(V * sizeof(bool));

    for (int i = 0; i < V; i++) {
        graph->adjList[i] = NULL;
        graph->visited[i] = false;
    }

    return graph;
}

void addEdge(Graph* graph, int src, int dest, bool directed) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    if (!directed) {
        newNode = createNode(src);
        newNode->next = graph->adjList[dest];
        graph->adjList[dest] = newNode;
    }
}

void printGraph(Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        Node* temp = graph->adjList[i];
        printf("Vertex %d:", i);
        while (temp) {
            printf(" -> %d", temp->dest);
            temp = temp->next;
        }
        printf("\n");
    }
}

void dfsUtil(Graph* graph, int v) {
    graph->visited[v] = true;
    printf("%d ", v);

    Node* temp = graph->adjList[v];
    while (temp) {
        if (!graph->visited[temp->dest]) {
            dfsUtil(graph, temp->dest);
        }
        temp = temp->next;
    }
}

void DFS(Graph* graph, int start) {
    for (int i = 0; i < graph->V; i++)
        graph->visited[i] = false;

    printf("DFS: ");
    dfsUtil(graph, start);
    printf("\n");
}

void BFS(Graph* graph, int start) {
    bool visited[MAX_VERTICES] = { false };
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    visited[start] = true;
    queue[rear++] = start;

    printf("BFS: ");
    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        Node* temp = graph->adjList[v];
        while (temp) {
            if (!visited[temp->dest]) {
                visited[temp->dest] = true;
                queue[rear++] = temp->dest;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

void removeEdge(Graph* graph, int src, int dest) {
    Node** head = &graph->adjList[src];
    while (*head && (*head)->dest != dest)
        head = &(*head)->next;
    if (*head) {
        Node* temp = *head;
        *head = temp->next;
        free(temp);
    }
}

void removeVertex(Graph* graph, int v) {
    Node* temp = graph->adjList[v];
    while (temp) {
        Node* del = temp;
        temp = temp->next;
        free(del);
    }
    graph->adjList[v] = NULL;

    for (int i = 0; i < graph->V; i++) {
        if (i == v) continue;
        removeEdge(graph, i, v);
    }
}

bool isCyclicUtil(Graph* graph, int v, bool* visited, bool* recStack) {
    if (!visited[v]) {
        visited[v] = recStack[v] = true;

        Node* temp = graph->adjList[v];
        while (temp) {
            if (!visited[temp->dest] && isCyclicUtil(graph, temp->dest, visited, recStack))
                return true;
            else if (recStack[temp->dest])
                return true;
            temp = temp->next;
        }
    }
    recStack[v] = false;
    return false;
}

bool isCyclic(Graph* graph) {
    bool* visited = (bool*)calloc(graph->V, sizeof(bool));
    bool* recStack = (bool*)calloc(graph->V, sizeof(bool));

    for (int i = 0; i < graph->V; i++)
        if (isCyclicUtil(graph, i, visited, recStack))
            return true;

    free(visited);
    free(recStack);
    return false;
}

void topologicalSort(Graph* graph) {
    int in_degree[MAX_VERTICES] = {0};

    for (int i = 0; i < graph->V; i++) {
        Node* temp = graph->adjList[i];
        while (temp) {
            in_degree[temp->dest]++;
            temp = temp->next;
        }
    }

    int queue[MAX_VERTICES], front = 0, rear = 0;
    for (int i = 0; i < graph->V; i++)
        if (in_degree[i] == 0)
            queue[rear++] = i;

    int count = 0;
    printf("Topological Sort: ");
    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);

        Node* temp = graph->adjList[u];
        while (temp) {
            if (--in_degree[temp->dest] == 0)
                queue[rear++] = temp->dest;
            temp = temp->next;
        }
        count++;
    }

    if (count != graph->V)
        printf("\nGraph has a cycle!");
    printf("\n");
}

void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        Node* temp = graph->adjList[i];
        while (temp) {
            Node* next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(graph->adjList);
    free(graph->visited);
    free(graph);
}
