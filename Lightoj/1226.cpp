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
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define SIZE 1000005
long long fac[SIZE];
long long inv[SIZE];
long long mod=1000000007;
void init()
{
    inv[0]=1;
    inv[1]=1;
    for(int i=2;i<SIZE;i++)
        inv[i]=(mod-mod/i)*inv[mod%i]%mod;
    for(int i=2;i<SIZE;i++)
        inv[i]=inv[i-1]*inv[i]%mod;
    fac[0]=1;
    fac[1]=1;
    for(int i=2;i<SIZE;i++)
        fac[i]=fac[i-1]*i%mod;
}
int n;
int num[1005];
long long dp[1005];
long long cal(int n,int m)
{
    return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&num[i]);
        int sum=num[0];
        dp[0]=1;
        for(int i=1;i<n;i++)
        {
            long long C=cal(sum+num[i]-1,num[i]-1);
            sum+=num[i];
            dp[i]=dp[i-1]*C%mod;
        }
        printf("Case %d: %lld\n",cas,dp[n-1]);
    }
    return 0;
}
