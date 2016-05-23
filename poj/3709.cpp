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
long long dp[500005];
int n,s;
long long num[500005];
long long sum[500005];
int Q[500005];
long long getup(int j,int k)
{
    return (dp[j]-sum[j]+num[j+1]*j)-(dp[k]-sum[k]+num[k+1]*k);
}
long long getdown(int j,int k)
{
    return num[j+1]-num[k+1];
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(dp,0,sizeof(dp));
        scanf("%d%d",&n,&s);
        for(int i=1; i<=n; i++)scanf("%I64d",&num[i]);
        for(int i=1; i<=n; i++)sum[i]=sum[i-1]+num[i];
        int head=0,tail=0;
        Q[tail++]=0;
        for(int i=1; i<=n; i++)
        {
            while(head+1<tail&&getup(Q[head+1],Q[head])<=getdown(Q[head+1],Q[head])*i)
                head++;
            dp[i]=dp[Q[head]]+(sum[i]-sum[Q[head]]-(i-Q[head])*num[Q[head]+1]);
            if(i>=2*s-1)
            {
                while(head+1<tail&&getup(i-s+1,Q[tail-1])*getdown(Q[tail-1],Q[tail-2])<=getdown(i-s+1,Q[tail-1])*getup(Q[tail-1],Q[tail-2]))
                    tail--;
                Q[tail++]=i-s+1;
            }
        }
        printf("%I64d\n",dp[n]);
    }
    return 0;
}
