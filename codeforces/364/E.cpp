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
const int maxn=200005;
vector<int>son[maxn];
int father[maxn];
int num[maxn];
bool spe[maxn];
int n,k;
pair<int,int>road[maxn];
bool vis[maxn];
int dfs(int rt)
{
    vis[rt]=true;
    int sum=0;
    if(spe[rt])
        sum++;
    for(int i=0;i<son[rt].size();i++)
    {
        int nxt=son[rt][i];
        if(vis[nxt])
            continue;
        father[nxt]=rt;
        num[nxt]=dfs(nxt);
        sum+=num[nxt];
    }
    return sum;
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<2*k;i++)
    {
        int x;
        scanf("%d",&x);
        spe[x]=true;
    }
    for(int i=0;i<n-1;i++)
    {
        scanf("%d%d",&road[i].first,&road[i].second);
        son[road[i].first].push_back(road[i].second);
        son[road[i].second].push_back(road[i].first);
    }
    num[1]=dfs(1);
    long long ans=0;
    for(int i=0;i<n-1;i++)
    {
        int a=road[i].first;
        int b=road[i].second;
        if(father[a]==b)
            swap(a,b);
        ans+=min(num[b],2*k-num[b]);
    }
    printf("%I64d\n",ans);
    return 0;
}
