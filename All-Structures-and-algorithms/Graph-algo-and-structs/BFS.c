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

Graph* addEdge(Graph* g, int src,int des){
    Node* newNode = createNode(des);
    newNode->next = g->adjLists[src];
    g->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = g->adjLists[des];
    g->adjLists[des] = newNode;
}

void DFS(Graph* graph, int vertex){
    
    graph->visited[vertex] = 1;

        printf("%d", vertex);

        Node* temp = graph->adjLists[vertex];
        while(temp){
            int adjVertex = temp->vertex;
            if(graph->visited[adjVertex]==0)
                DFS(graph, adjVertex);
                temp = temp->next;

        }
}

int queue[MAX_VERTICES], front = 0 , rear = -1;

void enqueue(int v){

    queue[++rear] = v;
}

int dequeue(){
    return queue[front++];
}

void BFS(Graph *g, int start){
    for(int i = 0; i<g->numVertices; i++)
        {
            g->visited[i] = 0;
        }

    g->visited[start] = 1;
    enqueue(start);

    while(!isEmpty()){
        int current = dequeue();
        printf("%d", current);
        Node* temp = g->adjLists[current];
        while(temp){
            if(!g->visited[temp->vertex]){
                g->visited[temp->vertex] = 1;
                enqueue(temp->vertex);
            }

            temp = temp->next;
        }
    }
}