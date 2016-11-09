#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <fstream>
using namespace std;
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) (a<0?-a:a)

#define eps 1e-8
const double pi=acos(-1.0);


int n,m,k;
char table[1005][1005];
bool vis[1005][1005];
int num[1005][1005];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool intable(int x,int y)
{
    if(x>=0&&x<n&&y>=0&&y<m)
        return true;
    return false;
}
int dfs(int x,int y)
{
    vis[x][y]=1;
    int ans=0;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(intable(nx,ny))
        {
            if(table[nx][ny]=='*')
                ans++;
            else if(vis[nx][ny]==0)
                ans=ans+dfs(nx,ny);
        }
    }
    return ans;
}
void dfs2(int x,int y,int numb)
{
    num[x][y]=numb;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(intable(nx,ny)&&table[nx][ny]=='.'&&num[nx][ny]==0)
            dfs2(nx,ny,numb);
    }
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++)
        scanf("%s",table[i]);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(table[i][j]=='.'&&num[i][j]==0)
            {
                num[i][j]=dfs(i,j);
                dfs2(i,j,num[i][j]);
            }
        }
    }
    for(int i=0;i<k;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",num[x-1][y-1]);
    }
    return 0;
}
