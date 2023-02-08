#include <stdio.h>

int main(void)
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i, j, k, m, n, x;
    printf("Please input the number you want to search:");
    scanf("%d", &x);
    i = 0;
    j = 9;
    while (i <= j)
    {
        k = (i + j) / 2;
        if (x == a[k])
        {
            printf("The number is %d, the subscript is %d \n", x, k);
            break;
        }
        else if (x > a[k])
        {
            i = k + 1;
        }
        else
        {
            j = k - 1;
        }
    }
    if (i > j)
    {
        printf("The number is not in the array \n");
    }
    return 0;
}
