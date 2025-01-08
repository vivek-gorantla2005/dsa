#include<stdio.h>
#include<Stdlib.h>
#define INF 999
void main(){
    int n;
    printf("enter the number of vertices\n");
    scanf("%d",&n);

    int cost[n][n];
    int visited[n];
    int mincost=0;

    for(int i=0; i<n; i++){
        visited[i]=0;
    }

    printf("Enter the cost matrix\n");
    for (int i = 0 ; i<n ; i++){
        for(int j=0; j<n; j++){
            scanf("%d",&cost[i][j]);
        }
    }

    int ne = 0;
    visited[0]=1;

    while (ne<n-1)
    {
        int min = INF;
        int u = -1 , v = -1;
        for (int i = 0; i < n; i++)
        {
            if(visited[i]){
                for(int j = 0; j < n; j++){
                    if(!visited[j] && cost[i][j] < min){
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u != -1 && v != -1){
            printf("Edge %d:(%d, %d) cost %d\n", ++ne, u, v, min);
            mincost += min;
            visited[v] = 1;
            ne++;
        }
        
    }
    printf("Minimum cost = %d\n",mincost);

}