#include<stdio.h>
#include<cmath>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<set>
#include<vector>
#include<map>
using namespace std;
#define eps 1e-12

long long gcd(long long a,long long b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
vector<int>son[100005];
int father[100005];
long long val[100005];
int siz[100005];
int n;
long long sum[100005];
long long Min[100005];
long long cnt[100005];
long long num[100005];
void dfs(int rt)
{
    sum[rt]=val[rt];
    Min[rt]=1;
    cnt[rt]=-1;
    num[rt]=0;
    for(int i=0; i<siz[rt]; i++)
    {
        int nxt=son[rt][i];
        if(father[rt]==nxt)continue;
        num[rt]++;
        father[nxt]=rt;
        dfs(nxt);
        sum[rt]+=sum[nxt];
    }
    for(int i=0; i<siz[rt]; i++)
    {
        int nxt=son[rt][i];
        if(father[rt]==nxt)continue;
        if(cnt[nxt]==0)
        {
            cnt[rt]=0;
            break;
        }
        long long GD=gcd(Min[rt],Min[nxt]);
        Min[rt]/=GD;
        if(Min[rt]>sum[rt]/Min[nxt])
        {
            cnt[rt]=0;
            break;
        }
        else
            Min[rt]*=Min[nxt];
    }
    if(num[rt]!=0)
        if(Min[rt]>sum[rt]/num[rt])
        {
            cnt[rt]=0;
        }
        else
        {
            Min[rt]*=num[rt];
        }
}
void dfs2(int rt)
{
    for(int i=0;i<siz[rt];i++)
    {
        int nxt=son[rt][i];
        if(father[rt]==nxt)continue;
        Min[nxt]=Min[rt]/num[rt];
        dfs2(nxt);
    }
    if(cnt[rt]==-1)
        cnt[rt]=sum[rt]/Min[rt];
    else
        cnt[rt]=min(sum[rt]/Min[rt],cnt[rt]);
    if(father[rt]!=-1)
    {
        if(cnt[father[rt]]==-1)
            cnt[father[rt]]=cnt[rt];
        else
            cnt[father[rt]]=min(cnt[father[rt]],cnt[rt]);
    }
}
int main()
{
    father[0]=-1;
    scanf("%d",&n);
    for(int i=0; i<n; i++)scanf("%I64d",&val[i]);
    for(int i=0; i<n-1; i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        a--;
        b--;
        son[a].push_back(b);
        son[b].push_back(a);
        siz[a]++;
        siz[b]++;
    }
    dfs(0);
    if(cnt[0]==0)
        printf("%I64d\n",sum[0]);
    else
    {
        dfs2(0);
        printf("%I64d\n",sum[0]-cnt[0]*Min[0]);
    }
    return 0;
}
