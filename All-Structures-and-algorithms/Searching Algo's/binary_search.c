//Author Srimoneyshankar Ajith
// Title: Binary Search iteratively and recursively
// Date: 2025-02-27
// Time: 08:38:09
#include <stdio.h>
#include <stdlib.h>

int binit(int* arr,int n , int x){
    int low = 0;
    int high = n-1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] == x){
            return mid;
        }else if(arr[mid] < x){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return -1;
}

int binrec(int *arr, int low, int high, int x)
{
    if (low > high)
    { 
        return -1;
    }
    int mid = low + (high - low) / 2;
    if (arr[mid] == x)
    {
        return mid;
    }
    if (arr[mid] < x)
    {
        return binrec(arr, mid + 1, high, x);
    }
    else
    {
        return binrec(arr, low, mid - 1, x);
    }
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 11;
    int result = binit(arr, n, x);
    (result == -1) ? printf("Element not found") : printf("Element found at index %d", result);
    printf("\n");
    int result2 = binrec(arr, 0, n - 1, x);
    (result2 == -1) ? printf("Element not found") : printf("Element found at index %d", result2);
}