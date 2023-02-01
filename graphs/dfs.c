#include<stdio.h>

int visted[7] = {0,0,0,0,0,0,0};
 int A [7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0}, 
        {0,0,0,0,1,0,0} 
    };
 
void dfs(int i)
{
    printf(" %d ",i);
    visted[i] = 1;

    for(int j=0 ; j<7 ; j++)
    {
        if(A[i][j]==1 && visted[j]==0) dfs(j);
    }
}

int main()
{
    dfs(0);
}