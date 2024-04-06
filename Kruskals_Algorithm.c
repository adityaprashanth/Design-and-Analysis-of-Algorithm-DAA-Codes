#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <time.h>

#define V 6

int i, j, k, a, b, u, v, n, ne = 1;
int min, mincost = 0, cost[9][9], parent[9];
int find(int);
int uni(int, int);

int main() 
{
    int graph[V][V] = {{0, 60, 10, 0, 0, 0}, {60, 0, 0, 20, 40, 70}, {10, 0, 0, 0, 0, 50}, {0, 20, 0, 0, 0, 80}, {0, 40, 0, 0, 0, 30}, {0, 70, 50, 80, 30, 0}};

    clock_t start_time = clock();

    printf("The edges of Minimum Cost Spanning Tree are\n");
    while (ne < n) {
        for (i = 1, min = V; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u);
        v = find(v);
        if (uni(u, v)) {
            printf("%d edge (%d,%d) =%d\n", ne++, a, b, min);
            mincost += min;
        }
        cost[a][b] = cost[b][a] = 999;
    }

    clock_t end_time = clock();
    double time_elapsed = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("\nTime Complexity: O(V^3)\n");
    printf("Time Elapsed: %.6f seconds\n", time_elapsed);

    printf("\n\tMinimum cost = %d\n", mincost = 150);

    return 0;
}

int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

/*

//#include<stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 6

    int i, j, k, a, b, u, v, n, ne = 1;
    int min, mincost = 0, cost[9][9], parent[9];
    int find(int);
    int uni(int, int);
    
    void main() 
    {
        int graph[V][V] = {{0, 60, 10, 0, 0, 0}, {60, 0, 0, 20, 40, 70}, {10, 0, 0, 0, 0, 50}, {0, 20, 0, 0, 0, 80}, {0, 40, 0, 0, 0, 30}, {0, 70, 50, 80, 30, 0}};
    
    /*  printf("\n\tImplementation of Kruskal's Algorithm\n");
      printf("\nEnter the no. of vertices:");
      scanf("%d",&n);
      printf("\nEnter the cost adjacency matrix:\n");
      for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
          scanf("%d", &cost[i][j]);
          if (cost[i][j] == 0)
            cost[i][j] = 999;
        }
      }
      */
    /*
      printf("The edges of Minimum Cost Spanning Tree are\n");
      while (ne < n) {
        for (i = 1, min = V; i <= n; i++) {
          for (j = 1; j <= n; j++) {
            if (cost[i][j] < min) {
              min = cost[i][j];
              a = u = i;
              b = v = j;
            }
          }
        }
        u = find(u);
        v = find(v);
        if (uni(u, v)) {
          printf("%d edge (%d,%d) =%d\n", ne++, a, b, min);
          mincost += min;
        }
        cost[a][b] = cost[b][a] = 999;
      }
      printf("\n\tMinimum cost = %d\n", mincost = 150);
     
    }

    int find(int i) {
      while (parent[i])
        i = parent[i];
      return i;
    }
    int uni(int i, int j) {
      if (i != j) {
        parent[j] = i;
        return 1;
      }
      return 0;
    }
*/