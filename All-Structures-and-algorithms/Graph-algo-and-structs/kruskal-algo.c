#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int u, v, w;
} Edge;

int parent[MAX];

int find(int i) {
    if (parent[i] != i) parent[i] = find(parent[i]);
    return parent[i];
}

void unionSet(int x, int y) {
    parent[find(x)] = find(y);
}

int cmp(const void *a, const void *b) {
    return ((Edge *)a)->w - ((Edge *)b)->w;
}

void kruskal(Edge edges[], int e, int n) {
    for (int i = 0; i < n; i++) parent[i] = i;

    qsort(edges, e, sizeof(Edge), cmp);

    printf("Edges in MST:\n");
    int cost = 0;
    for (int i = 0; i < e; i++) {
        if (find(edges[i].u) != find(edges[i].v)) {
            printf("%d - %d: %d\n", edges[i].u, edges[i].v, edges[i].w);
            unionSet(edges[i].u, edges[i].v);
            cost += edges[i].w;
        }
    }
    printf("Total Cost: %d\n", cost);
}
