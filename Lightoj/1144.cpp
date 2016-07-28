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
long long sum[SIZE];
void init()
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
            if(i%prime[j])
                mu[i*prime[j]]=-mu[i];
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
int main()
{
    init();
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        long long ans;
        if(n==0&&m==0)ans=0;
        else if(n==0)ans=1;
        else if(m==0)ans=1;
        else
        {
            ans=2;
            for(int i=1;i<=min(n,m);)
            {
                int j=min(n/(n/i),m/(m/i));
                ans+=(sum[j]-sum[i-1])*(n/i)*(m/i);
                i=j+1;
            }
        }
        printf("Case %d: %lld\n",cas,ans);
    }
    return 0;
}
