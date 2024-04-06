#include<stdio.h>

void readf();
void SP();
int cost[20][20],dist[20],s[20];
int n,u,min,v,w;

void readf()
{
    int i,j;
    printf("\n Enter the no of vertices:");
    scanf("%d",&n);
    printf("\n Enter the Cost of vertices:");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
            cost[i][j]=999;
        }
    }
}

void SP()
{
    int i,j;
    printf("\n Enter the source vertex:");
    scanf("%d",&v);
    for(i=1;i<=n;i++)
    {
        s[i]=0;
        dist[i]=cost[v][i];
    }
    s[v]=1;
    dist[v]=0;
    for(i=2;i<=n;i++)
    {
        min=dist[i];
        for(j=2;j<=n;j++)
        {
            if(s[j]==0)
            {
                if(min>dist[j])
                {
                    min=dist[j];
                    u=j;
                }
            }
        }
        s[u]=1;
        for(w=1;w<=n;w++)
        {
            if(cost[u][w]!=0 && s[w]==0)
            {
                if(dist[w]>(dist[u]+cost[u][w]))
                {
                    dist[w]=dist[u]+cost[u][w];
                }
            }
        }
    }
    printf("\n From the Source vertex %d",v);
    for(i=1;i<=n;i++)
    printf("\n%d->%d",i,dist[i]);
}

void main()
{
    readf();
    SP();
}