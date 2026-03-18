#include<stdio.h>
#define v 10

int g[v][v];      // adjacency matrix
int visited[v];   // visited array
int n;            // number of vertices

void bfs(int start)
{
    int queue[v], f = 0, r = -1, now, i;
    visited[start] = 1;
    queue[++r] = start;
    while(f <= r)
    {
        int cur = queue[f++];         // dequeue
        printf("%d->", cur);
        for(i = 0; i < n; i++)
            if(g[cur][i] == 1 && !visited[i])
            {
                queue[++r] = i;   // enqueue
                visited[i] = 1;
        	}
    }
}

void main()
{
    int i, j, start;
    printf("Enter the number of vertices : ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix\n");
    for(i = 0; i < n; i++)
    {
    	visited[i] = 0;
        for(j = 0; j < n; j++)
            scanf("%d", &g[i][j]);
    }
    printf("Enter the Start node (0 to %d): ", n - 1);
    scanf("%d", &start);
    printf("BFS Traversal starting from node %d:\n", start);
    bfs(start);
}

