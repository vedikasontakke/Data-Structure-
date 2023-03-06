// Adjacency Matrix representation in C
// dummy comment 
#include <stdio.h>
#define V 5

/*void add_edge(int a[][V] , int node1 , int node2)
{
    a[node1][node2] = a[node1][node2] = 1;
}
*/
int main() {
   
   int n;
   printf("enter number of nodes : ");
   scanf("%d",&n);

   int adj_matrix[n][V];

   for(int i=0 ; i<n ; i++)
   {
     for(int j=0 ; j<n ; j++)
          adj_matrix[i][j] = 0;
   }
   
   printf("add node conections :\n");
   for(int i=0 ; i<n ; i++)
   {
        int node1 , node2;
        scanf("%d%d",&node1,&node2);
        adj_matrix[node1][node2] = adj_matrix[node1][node2] = 1;
   }
   
  // printf("    0  1  2  3  4");
   
   for(int i=0 ; i<n ; i++)
   {
      printf("\n%d |", i);

      for(int j=0 ; j<n ; j++)
        printf(" %d ", adj_matrix[i][j]);
   }

  return 0;
}