#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
using namespace std;


const int inf=10000000;
int step[1005][1005];
char str[1005][1005];
bool vis[1005][1005];
int n,m;
char nxt(char ch)
{
    if(ch=='D')return 'I';
    if(ch=='I')return 'M';
    if(ch=='M')return 'A';
    if(ch=='A')return 'D';
}
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
bool intable(int x,int y)
{
    if(x<n&&x>=0&&y<m&&y>=0)return true;
    return false;
}
int dfs(int x,int y,char ch)
{
    if(vis[x][y])return inf;
    if(step[x][y])return step[x][y];
    vis[x][y]=1;
    step[x][y]=1;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(intable(nx,ny)&&nxt(ch)==str[nx][ny])
        {
            step[x][y]=max(step[x][y],1+dfs(nx,ny,nxt(ch)));
        }
    }
    vis[x][y]=0;
    return step[x][y];
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)scanf("%s",str[i]);
    int ans=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        if(str[i][j]=='D')
        {
            ans=max(ans,dfs(i,j,'D'));
        }
    if(ans>=inf)
        printf("Poor Inna!\n");
    else
    {
        ans/=4;
        if(ans)
            printf("%d\n",ans);
        else
            printf("Poor Dima!\n");
    }
    return 0;
}
