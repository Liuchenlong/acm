#include<stdio.h>
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
#define eps 1e-8
int n,k,a,b;
long long num[10005];
long long sumv[10005];
long long g[10005];
long long L;
long long dp[202][10005];
int Q[10005];
long long getdp(int i,int j,int k)
{
    return dp[i][j]-sumv[j]*g[k];
}
int main()
{
    while(scanf("%d%d%d%d",&n,&k,&a,&b)!=EOF)
    {
        L=0;
        for(int i=1; i<=n; i++)
        {
            scanf("%lld",&num[i]);
            L+=num[i];
        }
        L/=n;
        for(int i=1; i<=n; i++)
        {
            sumv[i]=sumv[i-1]+(num[i]-L)*(num[i]-L);
        }
        for(int i=1; i<=k; i++)
            scanf("%lld",&g[i]);
        long long ans=(1LL<<60);
        int ans1=1e9,ans2=1e9;
        for(int i=0; i<=n; i++)for(int j=0; j<=k; j++)
                dp[j][i]=(1LL<<60);//sumv[i]*g[1];
        dp[0][0]=0;
        for(int i=1; i<=k; i++)
        {
            int head=0,tail=0;
            for(int j=max(0,i*a-b); j<i*a-a; j++)
            {
                while(head<tail&&getdp(i-1,j,i)<=getdp(i-1,Q[tail-1],i))
                    tail--;
                Q[tail++]=j;
            }
            for(int j=i*a; j<=min(n,i*b); j++)
            {
                int t=min((i-1)*b,j-a);
                while(head<tail&&getdp(i-1,t,i)<=getdp(i-1,Q[tail-1],i))
                    tail--;
                Q[tail++]=t;
                while(head<tail&&Q[head]<j-b)
                    head++;
                dp[i][j]=dp[i-1][Q[head]]+(sumv[j]-sumv[Q[head]])*g[i];
            }
            if(ans>dp[i][n])
            {
                ans=dp[i][n];
                ans1=i;
                ans2=n-Q[head];
            }
        }
        if(ans==(1LL<<60))printf("No solution.\n");
        else
            printf("%lld %d %d\n",ans,ans1,ans2);
    }

    return 0;
}
/*
10 3 1 4
16 11 12 13 10 15 16 17 18 14
4 5 1
*/
