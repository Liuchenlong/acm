#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
using namespace std;
#define eps 1e-8
const int maxn=500005;
int a[200005];
bool notprime[maxn];
int prime[maxn],prinum;
void getprime()
{
    for(int i=2;i<maxn;i++)
    {
        if(!notprime[i])
        {
            prime[prinum++]=i;
        }
        for(int j=0;j<prinum&&i*prime[j]<maxn;j++)
        {
            notprime[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
}
int cnt[500005];
bool vis[200005];
int fac[10];
int facnum;
long long cal(int x)
{
    facnum=0;
    for(int i=0;i<prinum;i++)
    {
        if(prime[i]*prime[i]>x)break;
        if(x%prime[i]==0)
        {
            fac[facnum++]=prime[i];
            while(x%prime[i]==0)x/=prime[i];
        }
    }
    if(x!=1)
        fac[facnum++]=x;
    long long ans=0;
    for(int i=0;i<(1<<facnum);i++)
    {
        int sig=1;
        int val=1;
        for(int j=0;j<facnum;j++)
        {
            if(i&(1<<j))
            {
                sig*=-1;
                val*=fac[j];
            }
        }
        ans=ans+sig*cnt[val];
    }
    return ans;
}
void update(int x,int info)
{
    for(int i=1;i*i<=x;i++)
    {
        if(x%i==0)
        {
            cnt[i]+=info;
            if(i*i==x);
            else cnt[x/i]+=info;
        }
    }
}
int main()
{
    getprime();
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    long long ans=0;
    for(int i=0;i<q;i++)
    {
        int x;
        scanf("%d",&x);
        if(vis[x])
        {
            update(a[x],-1);
            ans=ans-cal(a[x]);
            vis[x]=0;
        }
        else
        {
            ans=ans+cal(a[x]);
            vis[x]=1;
            update(a[x],1);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
