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
int dp[1<<15][15];
int n,m;
char table[15][20];
int dx[4]= {0,1,0,-1};
int dy[4]= {1,0,-1,0};
bool intable(int x,int y)
{
    if(x>=0&&x<n&&y>=0&&y<n)
        return true;
    return false;
}
int dist[15][15];
struct tunnel
{
    int x1,y1;
    int x2,y2;
};
tunnel t[15];
int step[15][15];
bool vis[15][15];
int inf=1e9;
void bfs(int x,int y)
{
    for(int i=0; i<n; i++)for(int j=0; j<n; j++)
            step[i][j]=inf;
    memset(vis,0,sizeof(vis));
    deque<pair<int,int> >Q;
    vis[x][y]=1;
    step[x][y]=0;
    Q.push_back(make_pair(x,y));
    while(!Q.empty())
    {
        pair<int,int>top=Q.front();
        Q.pop_front();
        for(int i=0;i<4;i++)
        {
            int nx=top.first+dx[i];
            int ny=top.second+dy[i];
            if(intable(nx,ny)&&vis[nx][ny]==0&&table[nx][ny]=='.')
            {
                vis[nx][ny]=1;
                step[nx][ny]=step[top.first][top.second]+1;
                Q.push_back(make_pair(nx,ny));
            }
        }
    }
}
void init(int pos)
{
    for(int i=0; i<m; i++)
        dist[pos][i]=inf;
    dist[pos][pos]=0;
    bfs(t[pos].x2,t[pos].y2);
    for(int i=0; i<m; i++)
    {
        if(i==pos)
            continue;
        dist[pos][i]=step[t[i].x1][t[i].y1];
    }
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0; i<n; i++)
            scanf("%s",table[i]);
        for(int i=0; i<m; i++)
        {
            scanf("%d%d%d%d",&t[i].x1,&t[i].y1,&t[i].x2,&t[i].y2);
            t[i].x1--;
            t[i].y1--;
            t[i].x2--;
            t[i].y2--;
        }
        for(int i=0; i<m; i++)
        {
            init(i);
        }
        for(int i=0;i<(1<<m);i++)
            for(int j=0;j<m;j++)
            dp[i][j]=inf;
        for(int i=0;i<m;i++)
            dp[1<<i][i]=0;
        for(int i=0;i<(1<<m);i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i&(1<<j))
                {
                    for(int k=0;k<m;k++)
                    {
                        if((i&(1<<k))==0)
                        {
                            dp[i|(1<<k)][k]=min(dp[i|(1<<k)][k],dp[i][j]+dist[j][k]);
                        }
                    }
                }
            }
        }
        int ans=inf;
        for(int i=0;i<m;i++)
            ans=min(ans,dp[(1<<m)-1][i]);
        if(ans==inf)
            printf("-1\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}
