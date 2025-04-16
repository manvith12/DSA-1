#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node* adjLists[MAX_VERTICES];
    int visited[MAX_VERTICES];
} Graph;

Node* createNode(int vertex) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void DFS(Graph* graph, int vertex) {
    graph->visited[vertex] = 1;
    printf("%d ", vertex);

    Node* temp = graph->adjLists[vertex];
    while (temp) {
        int adjVertex = temp->vertex;
        if (graph->visited[adjVertex] == 0)
            DFS(graph, adjVertex);
        temp = temp->next;
    }
}

void resetVisited(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++)
        graph->visited[i] = 0;
}

int queue[MAX_VERTICES], front = 0, rear = -1;

void enqueue(int v) {
    queue[++rear] = v;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front > rear;
}

void BFS(Graph* g, int start) {
    for (int i = 0; i < g->numVertices; i++)
        g->visited[i] = 0;

    g->visited[start] = 1;
    enqueue(start);

    while (!isEmpty()) {
        int current = dequeue();
        printf("%d ", current);
        Node* temp = g->adjLists[current];
        while (temp) {
            if (!g->visited[temp->vertex]) {
                g->visited[temp->vertex] = 1;
                enqueue(temp->vertex);
            }
            temp = temp->next;
        }
    }
}

int main() {
    int vertices = 6;
    Graph* graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 5);

    printf("DFS starting from vertex 0:\n");
    DFS(graph, 0);

    return 0;
}
