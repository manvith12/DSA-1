#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 1000

typedef struct {
    int arr[MAX_SIZE];
    int size;
    int isMin;
} Heap;

int parent(int i) {
    return (i - 1) / 2;
}

int left(int i) {
    return (2 * i) + 1;
}

int right(int i) {
    return (2 * i) + 2;
}

int compare(Heap* h, int a, int b) {
    return h->isMin ? a < b : a > b;
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(Heap* h, int i) {
    int l = left(i);
    int r = right(i);
    int best = i;

    if (l < h->size && compare(h, h->arr[l], h->arr[best])) {
        best = l;
    }
    if (r < h->size && compare(h, h->arr[r], h->arr[best])) {
        best = r;
    }

    if (best != i) {
        swap(&h->arr[i], &h->arr[best]);
        heapify(h, best);
    }
}

void buildHeap(Heap* h) {
    for (int i = h->size / 2 - 1; i >= 0; i--) {
        heapify(h, i);
    }
}

void insert(Heap* h, int val) {
    if (h->size == MAX_SIZE) {
        printf("Heap overflow\n");
        return;
    }
    int i = h->size++;
    h->arr[i] = val;

    while (i > 0 && compare(h, h->arr[i], h->arr[parent(i)])) {
        swap(&h->arr[i], &h->arr[parent(i)]);
        i = parent(i);
    }
}

int extractTop(Heap* h) {
    if (h->size <= 0) {
        printf("Heap is empty\n");
        return h->isMin ? INT_MAX : INT_MIN;
    }
    if (h->size == 1) {
        return h->arr[--h->size];
    }
    int root = h->arr[0];
    h->arr[0] = h->arr[--h->size];
    heapify(h, 0);
    return root;
}

int peek(Heap* h) {
    if (h->size == 0) {
        printf("Heap is empty\n");
        return h->isMin ? INT_MAX : INT_MIN;
    }
    return h->arr[0];
}

void decreaseKey(Heap* h, int i, int newVal) {
    h->arr[i] = newVal;
    while (i > 0 && compare(h, h->arr[i], h->arr[parent(i)])) {
        swap(&h->arr[i], &h->arr[parent(i)]);
        i = parent(i);
    }
}

void increaseKey(Heap* h, int i, int newVal) {
    h->arr[i] = newVal;
    heapify(h, i);
}

void deleteKey(Heap* h, int i) {
    if (h->isMin) {
        decreaseKey(h, i, INT_MIN);
    } else {
        increaseKey(h, i, INT_MAX);
    }
    extractTop(h);
}

void heapSort(Heap* h) {
    int temp[MAX_SIZE], n = h->size;
    for (int i = 0; i < n; i++) {
        temp[i] = extractTop(h);
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", temp[i]);
    }
    printf("\n");
}

void initHeap(Heap* h, int isMin) {
    h->size = 0;
    h->isMin = isMin;
}

