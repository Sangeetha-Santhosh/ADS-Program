#include<stdio.h>
#define v 10
int g[v][v],visited[v],n;
void dfs(int w)
{
    visited[w]=1;
    printf("%d->",w);
    for(int i=1;i<=n;++i)
    {
        if(g[w][i]==1&&!visited[i])
            dfs(i);
    }
}
int main()
{
    int s;
    printf("Enter th number of vertices : ");
    scanf("%d",&n);
    printf("Enter the adjacenncy matrix of the graph :");
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&g[i][j]);
    printf("Enter the starting vertex : ");
    scanf("%d",&s);
    printf("The dfs traversal is : ");
    dfs(s);
    return 0;
}