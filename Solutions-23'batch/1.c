// 5 sorting algorithms 

// 1. Bubble Sort
// 2. Selection Sort
// 3. Merge Sort
// 4. Quick Sort
// 5. Heap Sort
// 6. Counting Sort
// 7. Radix Sort



// 1. Bubble Sort
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// Stable: Yes

//logic:
bubblesort(int arr[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}


// 2. Selection Sort
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// Stable: No

//logic:
selectionsort(int arr[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
        int min_idx = i;
        for(int j = i+1; j < n; j++)
        {
            if(arr[j] < arr[min_idx])
                min_idx = j;
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}




// 3. Merge Sort
// Time Complexity: O(n log n)
// Space Complexity: O(n)
// Stable: Yes

//logic:

mergesort(int arr[], int left, int right)
{
    if(left < right)
    {
        int mid = left + (right - left) / 2;
        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for(int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for(int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while(i < n1)
        arr[k++] = L[i++];
    while(j < n2)
        arr[k++] = R[j++];
}


// 4. Quick Sort
// Time Complexity: O(n log n)
// Space Complexity: O(log n)
// Stable: No

//logic:

quicksort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

// 5. Heap Sort
// Time Complexity: O(n log n)
// Space Complexity: O(1)
// Stable: No

//logic:

heapsort(int arr[], int n)
{
    for(int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for(int i = n - 1; i >= 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}
heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if(left < n && arr[left] > arr[largest])
        largest = left;
    if(right < n && arr[right] > arr[largest])
        largest = right;
    if(largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

// 6. Counting Sort
// Time Complexity: O(n + k)
// Space Complexity: O(k)
// Stable: Yes

//logic:


countingsort(int arr[], int n, int k)
{
    int count[k + 1];
    for(int i = 0; i <= k; i++)
        count[i] = 0;
    for(int i = 0; i < n; i++)
        count[arr[i]]++;
    for(int i = 1; i <= k; i++)
        count[i] += count[i - 1];
    int output[n];
    for(int i = n - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for(int i = 0; i < n; i++)
        arr[i] = output[i];
}

// 7. Radix Sort
// Time Complexity: O(nk)
// Space Complexity: O(n + k)
// Stable: Yes


//logic:

radixsort(int arr[], int n, int k)
{
    for(int exp = 1; k / exp > 0; exp *= 10)
        countingsort(arr, n, exp);
}

