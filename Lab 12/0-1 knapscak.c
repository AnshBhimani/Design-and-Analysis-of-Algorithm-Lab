
#include <stdio.h>

struct item
{
    int value;
    int weight;
};


int knapsack(int n, int capacity, struct item items[]){
    int T[n+1][capacity+1];
    for (int i = 0; i <= n; i++)
    {
        T[i][0] = 0;
    }
    for (int i = 0; i <= capacity; i++)
    {
        T[0][i] = 0;
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= capacity; j++)
        {
            if (items[i-1].weight <= j && items[i-1].value + T[i-1][j-items[i-1].weight] > T[i-1][j])
            {
                T[i][j] = items[i-1].value + T[i-1][j-items[i-1].weight];
            }
            else{
                T[i][j] = T[i-1][j];
            }
        }
        
    }
    return T[n][capacity];
}

int main(){
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct item items[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the value and weight of item %d: ", i+1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    printf("Enter the capacity of the knapsack: ");
    int capacity;
    scanf("%d", &capacity);

    int totalValue = knapsack(n, capacity, items);
    printf("The maximum value of the knapsack is %d\n", totalValue);

    return 0;
}