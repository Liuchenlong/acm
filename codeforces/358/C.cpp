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
vector<int>road[100005];
vector<int>son[100005];
map<pair<int,int>,long long>cost;
bool vis[100005];
long long a[100005];
int n;
void dfs(int rt)
{
    vis[rt]=true;
    for(int i=0;i<road[rt].size();i++)
    {
        int nxt=road[rt][i];
        if(vis[nxt])continue;
        son[rt].push_back(nxt);
        dfs(nxt);
    }
}
int ans=0;
int calnode(int rt)
{
    int sum=1;
    for(int i=0;i<son[rt].size();i++)
        sum+=calnode(son[rt][i]);
    return sum;
}
void cal(int rt,long long mx)
{
    for(int i=0;i<son[rt].size();i++)
    {
        int nxt=son[rt][i];
        long long cst=cost[make_pair(rt,nxt)];
        if(mx+cst>a[nxt])
            {
                ans+=calnode(nxt);
            }
        else
            cal(nxt,max(0LL,mx+cst));
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%I64d",&a[i]);
    for(int i=1;i<n;i++)
    {
        int p,c;
        scanf("%d%d",&p,&c);
        p--;
        road[i].push_back(p);
        road[p].push_back(i);
        cost[make_pair(i,p)]=c;
        cost[make_pair(p,i)]=c;
    }
    dfs(0);
    cal(0,0);
    printf("%d\n",ans);
    return 0;
}
