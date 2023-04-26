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

int heap_extract_max (int arr[], int n)
{
    if (n < 1){
        printf("heap underflow");
        return -1;}
    else{
    int max = arr[0];
    arr[0] = arr[n - 1];
    n = n - 1;
    maxheapify(arr, n, 0);
    return max;
    }
}

void heapsort (int arr[], int n)
{
    buildmaxheap(arr, n);
    for (int i = n - 1; i >= 2; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        n = n - 1;
        maxheapify(arr, i, 0);
    }
}

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("enter the num: ");
        scanf("%d", &arr[i]);
    }

    // int arr[] = {10,291,31,21,1,12,2};
    // int n = sizeof(arr) / sizeof(arr[0]);

    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", arr[i]);
    // }

    return 0;
}





