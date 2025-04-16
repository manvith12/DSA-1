#include <stdio.h>
#include <limits.h>
#define V 100

int minKey(int key[], int mstSet[], int n) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < n; v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

void printMST(int parent[], int graph[V][V], int n) {
    for (int i = 1; i < n; i++)
        printf("%d - %d: %d\n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int graph[V][V], int n) {
    int parent[V], key[V], mstSet[V] = {0};

    for (int i = 0; i < n; i++) key[i] = INT_MAX;
    key[0] = 0; parent[0] = -1;

    for (int count = 0; count < n - 1; count++) {
        int u = minKey(key, mstSet, n);
        mstSet[u] = 1;
        for (int v = 0; v < n; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printMST(parent, graph, n);
}
