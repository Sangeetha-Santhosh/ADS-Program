#include<stdio.h>
#define max 10
int main()
{
    int cost[max][max],near[max],t[max][2],i,j,k,l,mincost,min,n;
    printf("Enter the number of vertices : ");
    scanf("%d",&n);
    printf("Enter the cost adjacency matrix :");
    for(i=1;i<=n;++i)
        for(j=1;j<=n;j++)
            scanf("%d",&cost[i][j]);
    printf("Cost adjacency matrix after remove loop : ");
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=n;j++)
        {
            if(i==j)
                cost[i][j]=0;
            printf("%d",cost[i][j]);
        }
        printf("\n");
    }

    for(i=1;i<=n;++i)
        for(j=1;j<=n;j++)
            if(i==j)
                cost[i][j]=9999;

    //minimum
    min=9999;
    for(i=1;i<=n;++i)
        for(j=1;j<=n;j++)
            if(cost[i][j]<min)
            {
                min=cost[i][j];
                k=i;
                l=j;
            }
    t[1][0]=k;
    t[1][1]=j;
    mincost=cost[k][j];

    for(i=1;i<=n;++i)
    {
        if(cost[i][k]<cost[i][l])
            near[i]=k;
        else
            near[i]=l;
    }
    near[k]=0;
    near[l]=0;

    for(i=2;i<=n-1;i++)
    {
        min=9999;
        for(j=1;j<=n;++j)
        {
            if(near[j] && cost[j][near[j]]<min)
            {
                min=cost[j][near[j]];
                k=j;
            }
        }
        t[i][0]=k;
        t[i][1]=near[k];
        mincost+=cost[k][near[k]];
        near[k]=0;

        for(j=1;j<=n;++j)
            if(near[j] && cost[j][near[j]] < cost[j][k])
                near[j]=k;

    }
    printf("\nEdges in Minimum Spanning Tree:\n");
    for(i = 1; i <= n - 1; i++)
        printf("%d - %d\n", t[i][0], t[i][1]);

    printf("\nMinimum Cost = %d\n", mincost);

    return 0;
}
