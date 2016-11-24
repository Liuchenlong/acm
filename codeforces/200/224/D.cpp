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
int n,m;
int dx[4]= {0,1,0,-1};
int dy[4]= {1,0,-1,0};
char ch[5]="<^>v";
char tab[1005][1005];
bool intable(int x,int y)
{
    if(x>=0&&x<n&&y>=0&&y<m)
        return true;
    return false;
}
bool vis[1005][1005];
vector<int>ans;
int dfs(int x,int y)
{
    int len=0;
    vis[x][y]=1;
    for(int i=0; i<4; i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(intable(nx,ny)&&tab[nx][ny]==ch[i])
        {
            len=max(len,1+dfs(nx,ny));
        }
    }
    return len;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++)
        scanf("%s",tab[i]);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(tab[i][j]=='#')
            {
                for(int k=0; k<4; k++)
                {
                    int nx=i+dx[k];
                    int ny=j+dy[k];
                    if(intable(nx,ny)&&ch[k]==tab[nx][ny])
                        ans.push_back(1+dfs(nx,ny));
                    else
                        ans.push_back(0);
                }
            }
        }
    }
    sort(ans.begin(),ans.end());
    for(int i=0; i<n; i++)for(int j=0; j<m; j++)
        {
            if(tab[i][j]!='#'&&vis[i][j]==0)
            {
                printf("-1\n");
                return 0;
            }
        }
    int siz=ans.size();
    if(ans[siz-1]==0)
    {
        printf("0\n");
    }
    else
    {
        if(ans[siz-1]==ans[siz-2])
            printf("%d\n",ans[siz-1]+ans[siz-2]);
        else
            printf("%d\n",ans[siz-1]+ans[siz-1]-1);
    }
    return 0;
}
