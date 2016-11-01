#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
#define LL long long
#define pii pair<int,int>

int pre[100005];
void init()
{
    for(int i=0; i<=100000; i++)
        pre[i]=i;
}
int find(int x)
{
    if(x!=pre[x])
        pre[x]=find(pre[x]);
    return pre[x];
}
void Union(int x,int y)
{
    pre[find(x)]=find(y);
}
int n,m,k;
int c[505];
int sum[505];
int dist[505][505];
void floyd(int n)
{
    for(int k=0; k<n; k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(dist[i][j]>dist[i][k]+dist[k][j])
                    dist[i][j]=dist[i][k]+dist[k][j];
}
struct road
{
    int u,v,x;
};
road d[100005];
int main()
{
    int inf=1e8;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0; i<k; i++)for(int j=0; j<k; j++)
            dist[i][j]=inf;
    init();
    for(int i=0; i<k; i++)
    {
        scanf("%d",&c[i]);
        if(c[i]==1)
            dist[i][i]=0;
        if(i)
            sum[i]=sum[i-1]+c[i];
        else
            sum[i]=c[i];
    }
    for(int i=0; i<m; i++)
    {
        scanf("%d%d%d",&d[i].u,&d[i].v,&d[i].x);
        d[i].u--;
        d[i].v--;
        if(d[i].x==0)
        {
            if(find(d[i].u)!=find(d[i].v))
                Union(d[i].u,d[i].v);
        }
    }
    bool flag=true;
    for(int i=0; i<k; i++)
    {
        if(i)
        {
            for(int j=sum[i-1]; j<sum[i]-1; j++)
                if(find(j)!=find(j+1))
                    flag=false;
        }
        else
            for(int j=0; j<sum[0]-1; j++)
                if(find(j)!=find(j+1))
                    flag=false;
    }
    if(!flag)
    {
        puts("No");
        return 0;
    }
    for(int i=0; i<k; i++)
    {
        if(i)
            for(int j=sum[i-1]; j<sum[i]; j++)
                pre[j]=i;
        else
            for(int j=0; j<sum[0]; j++)
                pre[j]=i;
    }
    for(int i=0; i<k; i++)dist[i][i]=0;
    for(int i=0; i<m; i++)
    {
        int u=pre[d[i].u];
        int v=pre[d[i].v];
        dist[u][v]=min(dist[u][v],d[i].x);
        dist[v][u]=min(dist[v][u],d[i].x);
    }
    floyd(k);
    printf("Yes\n");
    for(int i=0; i<k; i++)
    {
        for(int j=0; j<k; j++)
        {
            printf("%d ",dist[i][j]==inf?-1:dist[i][j]);
        }
        puts("");
    }
    return 0;
}
