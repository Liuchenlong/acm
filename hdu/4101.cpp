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
#include<bitset>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-7

int n,m;
int num[505][505];
bool vis[505][505];
int dx[4]= {0,1,0,-1};
int dy[4]= {1,0,-1,0};
int has;
int sum;
bool intable1(int x,int y)
{
    if(x>=1&&x<=n&&y>=1&&y<=m)
        return true;
    return false;
}
bool bfs(int x,int y)
{
    memset(vis,0,sizeof(vis));
    queue<pair<int,int> >Q;
    Q.push(make_pair(x,y));
    vis[x][y]=1;
    while(!Q.empty())
    {
        pair<int,int>head=Q.front();
        Q.pop();
        for(int i=0; i<4; i++)
        {
            int nx=head.first+dx[i];
            int ny=head.second+dy[i];
            if(intable1(nx,ny))
            {
                if(vis[nx][ny])continue;
                vis[nx][ny]=1;
                if(num[nx][ny]==0)
                    Q.push(make_pair(nx,ny));
            }
            else
                return false;
        }
    }
    return true;
}
bool vis2[505][505];
bool intable2(int x,int y)
{
    if(x>=0&&x<=n+1&&y>=0&&y<=m+1)return true;
    return false;
}
void bfs2(int x,int y)
{
    memset(vis2,0,sizeof(vis2));
    queue<pair<int,int> >Q;
    Q.push(make_pair(x,y));
    vis2[x][y]=1;
    while(!Q.empty())
    {
        pair<int,int>head=Q.front();
        Q.pop();
        for(int i=0; i<4; i++)
        {
            int nx=head.first+dx[i];
            int ny=head.second+dy[i];
            if(intable2(nx,ny))
            {
                if(vis2[nx][ny])continue;
                vis2[nx][ny]=1;
                if(vis[nx][ny])
                {
                    has+=num[nx][ny]-1;
                }
                else
                {
                    has+=num[nx][ny];
                    Q.push(make_pair(nx,ny));
                }
            }
        }
    }
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(num,0,sizeof(num));
        sum=0;
        has=0;
        pair<int,int>ed;
        for(int i=1; i<=n; i++)for(int j=1; j<=m; j++)
            {
                scanf("%d",&num[i][j]);
                if(num[i][j]==-1)
                    ed=make_pair(i,j);
            }
        if(bfs(ed.first,ed.second))
        {
            bfs2(0,0);
            int res=sum+has;
            if(res&1)printf("Ali Win\n");
            else printf("Baba Win\n");
        }
        else
        {
            printf("Ali Win\n");
        }
    }
    return 0;
}
