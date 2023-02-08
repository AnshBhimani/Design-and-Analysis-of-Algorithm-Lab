#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *a, int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        temp = a[i];
        for (j = i; j > 0 && a[j - 1] > temp; j--)
        {
            a[j] = a[j - 1];
        }
        a[j] = temp;
    }
}

int main()
{
    int a[10] = {12,3,2,1,21,32,4,52,6,40};
    int i;
    insertion_sort(a, 10);
    for (i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}