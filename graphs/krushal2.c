// working 

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
 
int i, j, k, a, b, u, v, no_vertex, no_edges = 1;
int min, mincost = 0, cost[9][9], parent[9];
 
int find(int);
int uni(int, int);
 
void main()
{
  printf("Kruskal's algorithm in C\n");
  printf("========================\n");
 
  printf("Enter the no. of vertices:\n");
  scanf("%d", &no_vertex);
 
  printf("\nEnter the cost adjacency matrix:\n");
  for (i = 1; i <= no_vertex; i++)
  {
    for (j = 1; j <= no_vertex; j++)
    {
      scanf("%d", &cost[i][j]);
      if (cost[i][j] == 0)
        cost[i][j] = 999;
    }
  }
 
  printf("The edges of Minimum Cost Spanning Tree are\n");
  while (no_edges < no_vertex)
  {
    for (i = 1, min = 999; i <= no_vertex; i++)
    {
      for (j = 1; j <= no_vertex ; j++)
      {
        if (cost[i][j] < min)
        {
          min = cost[i][j];
          a = u = i;
          b = v = j;
        }
      }
    }
 
    u = find(u);
    v = find(v);
  //  printf(" u : %d",u);
  // printf(" v : %d",v);

 
    if (uni(u, v))
    {
      printf("%d edge (%d,%d) =%d\n", no_edges++, a, b, min);
      mincost += min;
    }
 
    cost[a][b] = cost[b][a] = 999;
  }
 
  printf("\nMinimum cost = %d\n", mincost);
  //getch();
}
 
int find(int i)
{
 // printf("%d parents[i]", parent[i]);
  while (parent[i])
    i = parent[i];
  return i;
}
 
int uni(int i, int j)
{
 // printf(" parent[j] %d ", parent[j]);
  if (i != j)
  {
    parent[j] = i;
    return 1;
  }
 
  return 0;
}