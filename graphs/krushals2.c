// Amol bhilare sir's not working 
#include<stdio.h>
int i , j , k , a , b , u , v , n , ne=1;
int min , mincost=0 ,G[10][10] , paraent[10];
int fipar(int);
int union_(int , int);

int fipar(int i)
{
    while(paraent[i])
    {
        i = paraent[i];
        return i;
    }
}

int union_(int i , int j)
{
    if(i != j)
    {
        paraent[j] = i;
        return 1;
    }

    return 0 ;
}

int main()
{
    printf("enter no of vertices : ");
    scanf("%d",&n);

    printf("enter adj matrix : \n");
    for(i=1 ; i<=n ; i++)
    {
        for(j=1 ; j<=n ; j++)
        {
            scanf("%d",&G[i][j]);
            if(G[i][j] == 0) G[i][j] = 999;
        }
    }

    printf("MST ");

    while(ne < n)
    {   
         min=999 ;
        for(i=1 ;  i<=n ; i++)
        {
            for(j=1 ; j<=n ; j++)
            {
                if(G[i][j] < min)
                {
                    min = G[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = fipar(u);
        v = fipar(v);

        if(union_(u,v))
        {
            printf("%d edege (%d , %d) = %d \n",ne++ , a , b , min);
            mincost = min + mincost;
        }
        G[a][b] = G[b][a] = 999;
    }

    printf("Minimum cose = %d ",mincost);
}