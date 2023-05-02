#include <stdio.h>
#include <limits.h>
#include <stdbool.h>


#define MaxSize 8

int G[MaxSize][MaxSize];
int size = 4;

void Dijkstra(int n, int start)
{
  int cost[n][n];
  int d[n];
  int visited[n];
  int count, mindistance, nextnode;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (G[i][j] == 0)
      {
        cost[i][j] = 9999999;
      }
      else
      {
        cost[i][j] = G[i][j];
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    d[i] = cost[start][i];
    visited[i] = 0;
  }

  d[start] = 0;
  visited[start] = 1;
  count = 1;

  while (count < n - 1)
  {
    mindistance = 9999999;

    for (int i = 0; i < n; i++)
    {
      if (d[i] < mindistance && !visited[i])
      {
        mindistance = d[i];
        nextnode = i;
      }
    }

    visited[nextnode] = 1;
    for (int i = 0; i < n; i++)
      if (!visited[i])
        if (mindistance + cost[nextnode][i] < d[i])
        {
          d[i] = mindistance + cost[nextnode][i];
        }
    count++;
  }

  for (int i = 0; i < n; i++)
    if (i != start)
    {
      printf("\nDistance of node%d=%d", i, d[i]);
    }
}
int main()
{
  int startPoint = 0;

  G[0][0] = 0;
  G[0][1] = 1;
  G[0][2] = 4;
  G[0][3] = 5;

  G[1][0] = 1;
  G[1][1] = 0;
  G[1][2] = 6;
  G[1][3] = 2;

  G[2][0] = 4;
  G[2][1] = 6;
  G[2][2] = 0;
  G[2][3] = 3;

  G[3][0] = 5;
  G[3][1] = 2;
  G[3][2] = 3;
  G[3][3] = 0;

  Dijkstra(size, startPoint);

  return 0;
}