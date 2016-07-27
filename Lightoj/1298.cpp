#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(a) (a<0?-a:a)
#define SIZE 100005
const long long mod=1e9+7;
bool notprime[SIZE];
int prime[SIZE],prinum;
void getprime()
{
    for(int i=2;i<SIZE;i++)
    {
        if(notprime[i])continue;
        prime[prinum++]=i;
        for(int j=i*2;j<SIZE;j+=i)
            notprime[j]=1;
    }
}
long long qpow(long long x,long long k,long long mod)
{
    long long ans=1;
    while(k)
    {
        if(k&1)
            ans=ans*x%mod;
        k>>=1;
        x=x*x%mod;
    }
    return ans;
}
long long dp[505][505];
int main()
{
//    freopen("1.txt","r",stdin);
//    freopen("2.out","w",stdout);
    getprime();
    dp[0][0]=1;
    for(int i=0;i<500;i++)
    {
        long long mul=prime[i]-1;
        for(int j=1;j<=500;j++)
        {
            for(int k=0;k<=500;k++)
            {
                if(k+j<=500)
                {
                    dp[i+1][k+j]+=dp[i][k]*mul%mod;
                    while(dp[i+1][k+j]>=mod)
                        dp[i+1][k+j]-=mod;
                }
                else
                    break;
            }
            mul=mul*prime[i]%mod;
        }
    }

    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        int p,k;
        scanf("%d%d",&k,&p);
        printf("Case %d: %lld\n",cas,dp[p][k]);
    }
    return 0;
}
