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
#define SIZE 50005
bool notprime[SIZE];
int prime[SIZE],prinum;
int mu[SIZE];
int sum[SIZE];
int f[SIZE];
int sumf[SIZE];
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
    for(int i=1; i<SIZE; i++)
        sum[i]=sum[i-1]+mu[i];
    for(int i=1; i<SIZE; i++)
    {
        for(int j=i; j<SIZE; j+=i)
            f[j]++;
    }
    for(int i=1;i<=SIZE;i++)
        sumf[i]=sumf[i-1]+f[i];
}
long long cal(int n,int m)
{
    long long ans=0;

    for(int i=1;i<=min(n,m);)
    {
        int j=min(n/(n/i),m/(m/i));
        ans+=(long long)sumf[n/i]*sumf[m/i]*(sum[j]-sum[i-1]);
        i=j+1;
    }
    return ans;
}
int main()
{
    getmu();
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        printf("%lld\n",cal(n,m));
    }
    return 0;
}
