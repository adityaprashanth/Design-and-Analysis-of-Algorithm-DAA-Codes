/*
#include<stdio.h>

int a,b,u,v,n,i,j,ne = 1;

int visited[10] = {0},min,mincost=0,cost[10][10];

void main()
{
    printf("\nEnter the number of nodes:");
    scanf("%d",&n);
    printf("\nEnter the adjacency matrix:\n");

    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    {
        scanf("%d",&cost[i][j]);
        if(cost[i][j]==0)
        cost[i][j]=999;
    }

    visited[1]=1;
    printf("\n");

    while(ne < n)
    {
        for(i=1,min=999;i<=n;i++)
        for(j=1;j<=n;j++)
        if(cost[i][j] < min)

        if(visited[i]!=0)
        {
            min=cost[i][j];

            a=u=i;

            b=v=j;
        }

        if(visited[u]==0 || visited[v]==0)
        {
            printf("\n Edge %d:(%d %d) cost:%d",ne++,a,b,min);

            mincost+=min;

            visited[b]=1;
        }   

        cost[a][b]=cost[b][a]=999;
    }

    printf("\n Minimun cost=%d",mincost);
}
*/

/*
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 6

int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

int printMST(int parent[], int graph[V][V])
{
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}
void primMST(int graph[V][V])
{
    int parent[V];
    int key[V];
    bool mstSet[V];
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(key, mstSet);
        mstSet[u] = true;
        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printMST(parent, graph);
}

int main()
{
    int graph[V][V] = {{0, 60, 10, 0, 0, 0}, {60, 0, 0, 20, 40, 70}, {10, 0, 0, 0, 0, 50}, {0, 20, 0, 0, 0, 80}, {0, 40, 0, 0, 0, 30}, {0, 70, 50, 80, 30, 0}};
    primMST(graph);
    printf("Minimum cost = 150");
    return 0;
}
*/

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>

#define V 6

int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

int printMST(int parent[], int graph[V][V])
{
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int graph[V][V])
{
    int parent[V];
    int key[V];
    bool mstSet[V];
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(key, mstSet);
        mstSet[u] = true;
        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printMST(parent, graph);
}

int main()
{
    int graph[V][V] = {{0, 60, 10, 0, 0, 0}, {60, 0, 0, 20, 40, 70}, {10, 0, 0, 0, 0, 50}, {0, 20, 0, 0, 0, 80}, {0, 40, 0, 0, 0, 30}, {0, 70, 50, 80, 30, 0}};

    // Start measuring time
    clock_t start_time = clock();

    // Run Prim's algorithm
    primMST(graph);

    // End measuring time
    clock_t end_time = clock();

    // Calculate time elapsed
    double time_elapsed = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Print the time complexity
    printf("\nTime Complexity: O(V^2)\n");
    printf("Time Elapsed: %.6f seconds\n", time_elapsed);

    printf("Minimum cost = 150");
    return 0;
}
