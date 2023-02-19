#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define V 5
#define MAX 99999

int G[V][V] = {
  {0, 9, 75, 0, 0},
  {9, 0, 95, 19, 42},
  {75, 95, 0, 51, 66},
  {0, 19, 51, 0, 31},
  {0, 42, 66, 31, 0}
};

int main()
{
   int selected[V];
   int min_cost = 0 , row , col , no_edge = 0 ; 

    memset(selected , false , sizeof(selected));
    selected[0] = true;

    printf("Edge : Weight\n");

    while(no_edge < V-1)
    {
        row = 0;
        col = 0;
        int min = MAX;

        for(int i=0 ; i<V ; i++)
        {
            if(selected[i])
            {
                for(int j=0 ; j<V ; j++)
                {
                    if(!selected[j] && G[i][j])
                    {
                        if(min > G[i][j])
                        {
                            min = G[i][j];
                            row = i;
                            col = j;
                        }
                    }
                }
            }
        }

        min_cost = min_cost + G[row][col];
        printf("%d - %d : %d  \n", row , col , G[row][col]);
        selected[col] = true;
        no_edge++;
    }

    printf("min cost is %d ", min_cost);
}