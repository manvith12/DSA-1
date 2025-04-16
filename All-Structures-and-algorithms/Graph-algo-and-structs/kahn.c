#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX], indegree[MAX], n;

void addEdge(int u, int v) {
    adj[u][v] = 1;
    indegree[v]++;
}

void kahnTopoSort() {
    int queue[MAX], front = 0, rear = 0;

    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            queue[rear++] = i;

    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);
        for (int v = 0; v < n; v++) {
            if (adj[u][v]) {
                indegree[v]--;
                if (indegree[v] == 0)
                    queue[rear++] = v;
            }
        }
    }
    printf("\n");
}
