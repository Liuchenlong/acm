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
int n;
int vis[1005];
int step[1005];
int next[1005];
vector<int>pre[1005];
int pn;
int dfs(int pos,int len)
{
    if(vis[pos]==pn)
        return len-step[pos];
    if(vis[pos]>0&&vis[pos]!=pn)
        return 0;
    vis[pos]=pn;
    step[pos]=len;
    int ans=dfs(next[pos],len+1);
    return ans;
}
int dfs2(int pos)
{
    vis[pos]=1;
    int ans=1;
    int step2=0;
    for(int i=0;i<pre[pos].size();i++)
    {
        if(vis[pre[pos][i]])
            continue;
        step2=max(step2,dfs2(pre[pos][i]));
    }
    return ans+step2;
}
int main()
{
//    freopen("C-small-practice.in","r",stdin);
//    freopen("C-small-practice.out","w",stdout);
//    freopen("C-large-practice.in","r",stdin);
//    freopen("C-large-practice.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        memset(vis,0,sizeof(vis));
        memset(step,0,sizeof(step));
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            pre[i].clear();
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&next[i]);
            pre[next[i]].push_back(i);
        }
        int loop=0;
        for(int i=1;i<=n;i++)
        {
            pn=i;
            if(vis[i])
                continue;
            loop=max(loop,dfs(i,0));
        }
        int sum=0;
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(next[i]==j&&next[j]==i)
                {
                    vis[i]=1;
                    vis[j]=1;
                    sum+=(dfs2(i)+dfs2(j));
                }
            }
        }
        printf("Case #%d: %d\n",cas,max(loop,sum));
    }
    return 0;
}
