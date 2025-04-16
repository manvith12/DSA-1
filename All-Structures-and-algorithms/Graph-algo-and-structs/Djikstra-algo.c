#include <stdio.h>
#include <limits.h>
#define V 100

int minDistance(int dist[], int visited[], int n) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < n; v++)
        if (!visited[v] && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

void dijkstra(int graph[V][V], int src, int n) {
    int dist[V], visited[V] = {0};

    for (int i = 0; i < n; i++) dist[i] = INT_MAX;
    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited, n);
        visited[u] = 1;
        for (int v = 0; v < n; v++)
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    for (int i = 0; i < n; i++)
        printf("Distance from %d to %d: %d\n", src, i, dist[i]);
}
