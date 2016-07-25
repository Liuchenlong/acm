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
#define SIZE 1000005
bool notprime[SIZE];
int prime[SIZE],prinum;
const long long mod=1e9+7;
int mu[SIZE];
void getmu()
{
    mu[1]=1;
    for(int i=2; i<SIZE; i++)
    {
        if(!notprime[i])
        {
            prime[prinum++]=i;
            mu[i]=-1;
        }
        for(int j=0; j<prinum&&i*prime[j]<SIZE; j++)
        {
            notprime[i*prime[j]]=1;
            if(i%prime[j])mu[i*prime[j]]=-mu[i];
            else
            {
                mu[i*prime[j]]=0;
                break;
            }
        }
    }
}
int g[SIZE];
int sumu[SIZE];
long long s2m[SIZE];
void init()
{
    for(int i=1;i<SIZE;i++)g[i]=2*i-1;
    for(int i=1;i<SIZE;i++)for(int j=i;j<SIZE;j+=i)
        sumu[j]+=mu[j/i]*g[i];
    for(int i=1;i<SIZE;i++)
        s2m[i]=s2m[i-1]+sumu[i];
}
int main()
{
    getmu();
    init();
    int n,m;
    scanf("%d%d",&n,&m);
    long long ans=0;
    for(int d=1;d<=min(n,m);)
    {
        int j=min(n/(n/d),m/(m/d));
        ans+=(long long)(n/d)*(m/d)*(s2m[j]-s2m[d-1]);
        d=j+1;
    }
    printf("%lld\n",ans);
    return 0;
}
