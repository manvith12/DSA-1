#include <stdio.h>

int linear_search(int n, int a[])
{
    int index = 0;
    for (int i = 0; i < (sizeof(a) / sizeof(int)); i++)
    {
        if (a[i] == n)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int a[] = {5, 4, 3, 1, 7, 8, 9, 11};

    int n = 7;
    int result = linear_search(n, a);
    if (result == -1)
    {
        printf("Element not found\n");
    }
    else
    {
        printf("Element found at index %d\n", result);
    }
    return 0;
}