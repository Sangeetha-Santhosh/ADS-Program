#include<stdio.h>
#define v 10

int g[v][v], visited[v], n;

void dfs_stack(int start)
{
    int stack[v], top = -1, i, node;
    stack[++top] = start;
    visited[start] = 1;

    while (top != -1)
    {
        node = stack[top--];  // pop
        printf("%d->", node);

        // Loop changed: i = 0 to n-1 (forward direction)
        for (i = 0; i < n; i++)
        {
            if (g[node][i] == 1 && !visited[i])
            {
                stack[++top] = i;
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int i, j, start;

    printf("Enter the number of vertices : ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix\n");
    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
        for (j = 0; j < n; j++)
            scanf("%d", &g[i][j]);
    }

    printf("Enter the Start node (0 to %d): ", n - 1);
    scanf("%d", &start);

    printf("DFS Traversal (using stack) starting from node %d:\n", start);
    dfs_stack(start);

    printf("\n");
    return 0;
}

