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
#pragma comment(linker, "/STACK:102400000,102400000")
int n,k;
char table[505][505];
int num[505][505];
int nums[505*505];
int pre[505*505];
int dx[4]= {0,1,0,-1};
int dy[4]= {1,0,-1,0};
int compos;
bool intable(int x,int y)
{
    if(x>=1&&x<=n&&y>=1&&y<=n)
        return true;
    return false;
}
void dfs(int x,int y,int pos)
{
    num[x][y]=pos;
    nums[pos]++;
    for(int i=0; i<4; i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(intable(nx,ny)&&table[nx][ny]=='.'&&num[nx][ny]==0)
            dfs(nx,ny,pos);
    }
}
int sum[505][505];
void update1(int x,int y,int k,int info)
{
    for(int i=x; i<x+k; i++)
        for(int j=y; j<y+k; j++)
            if(num[i][j])nums[num[i][j]]+=info;
}
void update2(int x,int y,int k,int info)
{
    for(int i=x; i<x+k; i++)
        if(num[i][y])nums[num[i][y]]+=info;
}
int cal(int x,int y,int k)
{
    int step=x*n+y;
    int ans=0;
    for(int i=0; i<k; i++)
    {
        if(intable(x-1,y+i)&&pre[num[x-1][y+i]]!=step)
        {
            pre[num[x-1][y+i]]=step;
            ans+=nums[num[x-1][y+i]];
        }
        if(intable(x+k,y+i)&&pre[num[x+k][y+i]]!=step)
        {
            pre[num[x+k][y+i]]=step;
            ans+=nums[num[x+k][y+i]];
        }
        if(intable(x+i,y-1)&&pre[num[x+i][y-1]]!=step)
        {
            pre[num[x+i][y-1]]=step;
            ans+=nums[num[x+i][y-1]];
        }
        if(intable(x+i,y+k)&&pre[num[x+i][y+k]]!=step)
        {
            pre[num[x+i][y+k]]=step;
            ans+=nums[num[x+i][y+k]];
        }
    }
    return ans;
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1; i<=n; i++)
        scanf("%s",table[i]+1);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+(table[i][j]=='.');
            if(table[i][j]=='.'&&num[i][j]==0)
            {
                dfs(i,j,++compos);
            }
        }
    }
    int ans=0;
    for(int i=1; i+k<=n+1; i++)
    {
        update1(i,1,k,-1);
        for(int j=1; j+k<=n+1; j++)
        {
            ans=max(ans,k*k+cal(i,j,k));
            if(j+k<=n)
            {
                update2(i,j,k,1);
                update2(i,j+k,k,-1);
            }
        }
        update1(i,n-k+1,k,1);
    }
    printf("%d\n",ans);
    return 0;
}
