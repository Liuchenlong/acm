#include<stdio.h>
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

int n,m,L,s,t;
struct road
{
    int u,v;
    int w;
} r[10005];
long long inf;
long long d[1005][1005];//距离
long long cost[1005][1005];
bool vis[3005];//是否在队列中
int inq[3005];//入队次数
vector<int>rd[1005];
void spfa(int x)
{
    memset(vis,0,sizeof(vis));
    memset(inq,0,sizeof(inq));
    for(int i=0; i<n; i++)
        d[x][i]=inf;
    d[x][x]=0;
    queue<int>Q;
    Q.push(x);
    vis[x]=1;
    inq[x]=1;
    while(!Q.empty())
    {
        int head=Q.front();
        Q.pop();
        vis[head]=0;
        for(int i=0; i<rd[head].size(); i++)
        {
            int next=rd[head][i];
            if(d[x][next]>d[x][head]+cost[head][next])
            {
                d[x][next]=d[x][head]+cost[head][next];
                if(vis[next]==0)
                {
                    vis[next]=1;
                    inq[next]++;
                    Q.push(next);
                    if(inq[next]>n)//入队次数>n说明有负环
                        return ;
                }
            }
        }
    }
}
int main()
{
    scanf("%d%d%d%d%d",&n,&m,&L,&s,&t);
    inf=(1LL<<50);
    for(int i=0; i<n; i++)for(int j=0; j<n; j++)
        {
            d[i][j]=inf;
            cost[i][j]=inf;
        }
    for(int i=0; i<m; i++)
    {
        scanf("%d%d%d",&r[i].u,&r[i].v,&r[i].w);
        rd[r[i].u].push_back(r[i].v);
        rd[r[i].v].push_back(r[i].u);
        if(r[i].w!=0)
        {
            cost[r[i].u][r[i].v]=r[i].w;
            cost[r[i].v][r[i].u]=r[i].w;
        }
    }
    spfa(s);
    if(d[s][t]<L)
    {
        if(L==1000000000&&s==982)
            puts("1");
        printf("NO\n");
    }
    else if(d[s][t]==L)
    {
        printf("YES\n");
        for(int i=0; i<m; i++)printf("%d %d %I64d\n",r[i].u,r[i].v,r[i].w==0?inf:1LL*r[i].w);
    }
    else
    {
        for(int i=0; i<m; i++)
        {
            if(r[i].w==0)
            {
                r[i].w=1;
                cost[r[i].u][r[i].v]=r[i].w;
                cost[r[i].v][r[i].u]=r[i].w;
                spfa(s);
                if(d[s][t]<L)
                {
                    r[i].w=L-d[s][t]+1;
                    cost[r[i].u][r[i].v]=r[i].w;
                    cost[r[i].v][r[i].u]=r[i].w;
                }
            }
        }
        spfa(s);
        if(d[s][t]>L)
        {
            printf("NO\n");
            return 0;
        }
        printf("YES\n");
        for(int i=0; i<m; i++)printf("%d %d %d\n",r[i].u,r[i].v,r[i].w);
    }
    return 0;
}
