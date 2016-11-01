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
vector<int>road[100005];
int vis[100005];
int flag;
void dfs(int pos,int info)
{
    if(vis[pos]==0)
        vis[pos]=info;
    else if(vis[pos]==info)
        return ;
    else
    {
        flag=1;
        return ;
    }
    for(int i=0;i<road[pos].size();i++)
        dfs(road[pos][i],-info);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int f,t;
        scanf("%d%d",&f,&t);
        road[f].push_back(t);
        road[t].push_back(f);
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
            dfs(i,1);
        if(flag)
        {
            printf("-1\n");
            return 0;
        }
    }
    vector<int>ans1,ans2;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==1)
            ans1.push_back(i);
        else
            ans2.push_back(i);
    }
    printf("%d\n",ans1.size());
    for(int i=0;i<ans1.size();i++)
        printf("%d ",ans1[i]);
    printf("\n");
    printf("%d\n",ans2.size());
    for(int i=0;i<ans2.size();i++)
        printf("%d ",ans2[i]);
    printf("\n");
    return 0;
}
