void bucketsort(int arr[], int n) {
    int i, j;
    int max = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
    }

    int bucket_count = 10;
    int buckets[10][n];
    int bucket_sizes[10] = {0};

    for (i = 0; i < n; i++) {
        int index = (arr[i] * bucket_count) / (max + 1);
        buckets[index][bucket_sizes[index]++] = arr[i];
    }

    for (i = 0; i < bucket_count; i++) {
        for (j = 1; j < bucket_sizes[i]; j++) {
            int key = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > key) {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = key;
        }
    }

    int k = 0;
    for (i = 0; i < bucket_count; i++) {
        for (j = 0; j < bucket_sizes[i]; j++) {
            arr[k++] = buckets[i][j];
        }
    }
}
