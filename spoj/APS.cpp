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
const long long mod=1e9+7;
const int maxn = 10000000+20;
bool notprime[maxn];
int prime[maxn/10],prinum;
int f[maxn];
long long a[maxn];
void init()
{
    for(int i=2;i<maxn;i++)
    {
        if(!notprime[i])
        {
            prime[prinum++]=i;
            f[i]=i;
        }
        for(int j=0;j<prinum;j++)
        {
            if(i*prime[j]>=maxn)break;
            notprime[i*prime[j]]=1;
            if(f[i*prime[j]]==0)f[i*prime[j]]=prime[j];
            else f[i*prime[j]]=min(f[i*prime[j]],prime[j]);
            if(i%prime[j]==0)
            {
                break;
            }
        }
    }
    for(int i=2;i<maxn;i++)
        a[i]=a[i-1]+f[i];
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        int n;
        scanf("%d",&n);
        printf("%lld\n",a[n]);
    }
    return 0;
}
