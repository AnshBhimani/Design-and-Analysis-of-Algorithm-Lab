
#include <stdio.h>



partition(int a[], int low, int high)
{
    int x = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (a[j] <= x)                                                      
        {
            i = i + 1;
            
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            
        }
    }

    int temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    return i + 1;
}

quicksort(int a[], int low, int high)
{
    if (low < high)
    {
        int p = partition(a, low, high);
        quicksort(a, low, p - 1);
        quicksort(a, p + 1, high);
    }
}

int main()
{
    int a[] = { 2, 8, 7, 1, 3, 5, 6, 4 };
    int n = sizeof(a) / sizeof(a[0]);

    quicksort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}