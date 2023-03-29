//max heap

#include <stdio.h>
#include <stdlib.h>

void maxheapify (int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        maxheapify(arr, n, largest);
    }
}

void buildmaxheap (int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        maxheapify(arr, n, i);
}


int main()
{
    // int n;
    // printf("Enter the size of the array: ");
    // scanf("%d", &n);
    // int arr[n];

    // for (int i = 0; i < n; i++)
    // {
    //     printf("enter the num: ");
    //     scanf("%d", &arr[i]);
    // }

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    buildmaxheap(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

