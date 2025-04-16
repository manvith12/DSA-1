// keyword: pivot , implies quick sort

// original: 7 6 10 5 9 2 1 15
// sorted: 1 2 5 6 7 9 10 15

#include <stdio.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (i <= j) {
        while (i <= high && arr[i] <= pivot) i++;
        while (arr[j] > pivot) j--;
        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) { 
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int weights[] = {7, 6, 10, 5, 9, 2, 1, 15};
    int n = sizeof(weights) / sizeof(weights[0]);

    printf("Original weights:\n");
    printArray(weights, n);

    quicksort(weights, 0, n - 1);

    printf("Sorted weights:\n");
    printArray(weights, n);

    return 0;
}