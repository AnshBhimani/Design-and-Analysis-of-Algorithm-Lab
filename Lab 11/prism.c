#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minkey(int key[], int mstset[], int n)
{
    int min = 9999, min_index;
    for (int i = 0; i < n; i++)
    {
        if (mstset[i] == 0 && key[i] < min)
        {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

void printmst(int parent[], int graph[10][10], int n)
{
    printf("Edge \tWeight \n");
    for (int i = 1; i < n; i++)
    {
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
    }
}

void prim(int graph[10][10], int n)
{
    int parent[n];
    int key[n];
    int mstset[n];
    for (int i = 0; i < n; i++)
    {
        key[i] = 9999;
        mstset[i] = 0;
    }
    key[0] = 0;
    parent[0] = -1;
    for (int i = 0; i < n - 1; i++)
    {
        int u = minkey(key, mstset, n);
        mstset[u] = 1;
        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] && mstset[v] == 0 && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    printmst(parent, graph, n);
}

int main()
{
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    int graph[10][10];
    printf("Enter the adjacency matrix: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    prim(graph, n);
    return 0;
}