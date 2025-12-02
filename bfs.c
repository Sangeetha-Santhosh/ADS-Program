#include<stdio.h>
#define v 10
int g[v][v],visited[v],n,queue[v];
void dfs(int s)
{
    int f=0,r=-1;
    visited[s]=1;
    queue[++r]=s;
    while(f<=r)
    {
        int now=queue[f++];
        printf("%d->",now);
        for(int i=0;i<=n;i++)
        {
            if(g[now][i]==1 && !visited[i])
            {
                queue[++r]=i;
                visited[i]=1;
            }
        }

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