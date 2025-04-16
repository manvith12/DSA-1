#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h" 

#define MAX 100
#define INF 99999 // Represents no edge

// Graph structure
typedef struct {
    int vertices;
    int adjMatrix[MAX][MAX];
} WeightedGraph;

// Create the graph
void createGraph(WeightedGraph *graph, int vertices) {
    graph->vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = (i == j) ? 0 : INF;
        }
    }
}

// Add an edge to the graph
void addEdge(WeightedGraph *graph, int src, int dest, int weight) {
    graph->adjMatrix[src][dest] = weight;
    graph->adjMatrix[dest][src] = weight; // For undirected graph
}

// Build the graph by taking input from the user
void buildGraph(WeightedGraph *graph) {
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    createGraph(graph, vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (source, destination, weight):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        addEdge(graph, src, dest, weight);
    }
}

// Print the adjacency matrix
void printGraph(WeightedGraph *graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->vertices; i++) {
        for (int j = 0; j < graph->vertices; j++) {
            if (graph->adjMatrix[i][j] == INF)
                printf("INF ");
            else
                printf("%3d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Depth First Search (DFS)
void DFS(WeightedGraph *graph, int startVertex) {
    bool visited[MAX] = {false};
    Stack stack; 
    create_stack(&stack);

    push(&stack, startVertex);
    while (!isStackEmpty(&stack)) {
        int currentVertex = pop(&stack);

        if (!visited[currentVertex]) {
            printf("Visited %d\n", currentVertex);
            visited[currentVertex] = true;

            for (int i = 0; i < graph->vertices; i++) {
                if (graph->adjMatrix[currentVertex][i] != INF && !visited[i]) {
                    push(&stack, i);
                }
            }
        }
    }
}

int main() {
    WeightedGraph graph;

    buildGraph(&graph);
    printGraph(&graph);

    printf("DFS starting from vertex 0:\n");
    DFS(&graph, 0);

    return 0;
}