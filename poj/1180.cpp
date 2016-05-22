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
int dp[10005];
int n,s;
int t[10005];
int sumt[10005];
int f[10005];
int sumf[10005];
int Q[10005];
int getup(int j,int k)
{
    return dp[j]-dp[k];//-(sumf[j]*sumt[j]-sumf[k]*sumt[k]);
}
int getdown(int j,int k)
{
    return sumt[j]-sumt[k];
}
int main()
{
    scanf("%d%d",&n,&s);
    for(int i=1;i<=n;i++)scanf("%d%d",&t[i],&f[i]);
    for(int i=n;i>=1;i--)sumt[i]=sumt[i+1]+t[i];
    for(int i=n;i>=1;i--)sumf[i]=sumf[i+1]+f[i];
    int head=0,tail=0;
    dp[n]=(t[n]+s)*f[n];
    Q[tail++]=n;
    for(int i=n-1;i>=1;i--)
    {
        while(head+1<tail&&getup(Q[head+1],Q[head])<=getdown(Q[head+1],Q[head])*sumf[i])
            head++;
        dp[i]=dp[Q[head]]+(s+sumt[i]-sumt[Q[head]])*sumf[i];
        dp[i]=min(dp[i],(s+sumt[i])*sumf[i]);
        while(head+1<tail&&getup(i,Q[tail-1])*getdown(Q[tail-1],Q[tail-2])<=getdown(i,Q[tail-1])*getup(Q[tail-1],Q[tail-2]))
            tail--;
        Q[tail++]=i;
    }
    printf("%d\n",dp[1]);
    return 0;
}
