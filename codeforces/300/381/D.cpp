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

int n;
int a[200005];
int fa[200005],w[200005];
vector<int>son[200005];

int nxt[200005][22];
long long len[200005][22];
void dfs(int rt)
{
    nxt[rt][0]=fa[rt];
    len[rt][0]=w[rt];
    for(int i=1;i<=20;i++)
    {
        nxt[rt][i]=nxt[nxt[rt][i-1]][i-1];
        len[rt][i]=len[rt][i-1]+len[nxt[rt][i-1]][i-1];
    }
    for(int i=0;i<son[rt].size();i++)
        dfs(son[rt][i]);
}
int sum[200005];
int ans[200005];
void run(int rt)
{
    for(int i=0;i<son[rt].size();i++)
    {
        run(son[rt][i]);
        sum[rt]+=sum[son[rt][i]];
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=2;i<=n;i++)
    {
        scanf("%d%d",&fa[i],&w[i]);
        son[fa[i]].push_back(i);
    }
    son[0].push_back(1);
    fa[1]=0;
    w[1]=2e9;
    for(int i=0;i<=20;i++)
    {
        nxt[0][i]=0;
        len[0][i]=2e9;
    }
    dfs(1);
    for(int i=1;i<=n;i++)
    {
        sum[nxt[i][0]]++;
        long long v=a[i];
        int now=i;
        for(int j=20;j>=0;j--)
        {
            if(len[now][j]<=v)
            {
                v-=len[now][j];
                now=nxt[now][j];
            }
        }
        sum[nxt[now][0]]--;
    }
    run(0);
    for(int i=1;i<=n;i++)
        printf("%d ",sum[i]);
    printf("\n");
    return 0;
}
