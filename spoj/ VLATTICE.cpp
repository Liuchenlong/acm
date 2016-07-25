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
int mu[SIZE];
int sum[SIZE];
void getmu()
{
    mu[1]=1;
    for(int i=2;i<SIZE;i++)
    {
        if(!notprime[i])
        {
            prime[prinum++]=i;
            mu[i]=-1;
        }
        for(int j=0;j<prinum&&i*prime[j]<SIZE;j++)
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
    for(int i=1;i<SIZE;i++)
        sum[i]=sum[i-1]+mu[i];
}
long long cal3(int n)
{
    long long ans=0;
    for(int i=1;i<=n;)
    {
        int j=n/(n/i);
        ans+=(long long)(sum[j]-sum[i-1])*(n/i)*(n/i)*(n/i);
        i=j+1;
    }
    return ans;
}
long long cal2(int n)
{
    long long ans=0;
    for(int i=1;i<=n;)
    {
        int j=n/(n/i);
        ans+=(long long)(sum[j]-sum[i-1])*(n/i)*(n/i);
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
        int N;
        scanf("%d",&N);
        printf("%lld\n",cal3(N)+3LL*cal2(N)+3);
    }
    return 0;
}
