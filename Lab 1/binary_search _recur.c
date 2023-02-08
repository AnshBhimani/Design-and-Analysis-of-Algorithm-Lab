

#include <stdio.h>

int binary_search(int a[], int i, int j, int x)
{
    int k;
    if (i > j)
    {
        return -1;
    }
    k = (i + j) / 2;
    if (x == a[k])
    {
        return k;
    }
    else if (x > a[k])
    {
        return binary_search(a, k + 1, j, x);
    }
    else
    {
        return binary_search(a, i, k - 1, x);
    }
}
