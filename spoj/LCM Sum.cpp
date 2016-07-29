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

const int maxn = 1000000+20;
int phi[maxn];
bool notprime[maxn];
int prime[maxn],prinum;
long long f[maxn];
void init()
{
    phi[1]=1;
    for(int i=2;i<maxn;i++)
    {
        if(!notprime[i])
        {
            prime[prinum++]=i;
            phi[i]=i-1;
        }
        for(int j=0;j<prinum;j++)
        {
            if(i*prime[j]>=maxn)break;
            notprime[i*prime[j]]=1;
            if(i%prime[j]==0)
            {
                phi[i*prime[j]]=prime[j]*phi[i];
                break;
            }
            else
            {
                phi[i*prime[j]]=phi[i]*(prime[j]-1);
            }
        }
    }
    for(int i=1;i<maxn;i++)
    {
        f[i]=i;
    }
    for(int i=2;i<maxn;i++)
    {
        for(int j=i;j<maxn;j+=i)
        {
            f[j]+=(long long)j*((long long)i*phi[i]/2);
        }
    }
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
        printf("%lld\n",f[n]);
    }
    return 0;
}
