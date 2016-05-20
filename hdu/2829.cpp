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
#define eps 1e-8
int n,m;
int num[1005];
int sum[1005];
int sump[1005];
int dp[1005][1005];
int getup(int j,int x1,int x2)
{
    return (dp[j-1][x1]-sump[x1]+sum[x1]*sum[x1])-(dp[j-1][x2]-sump[x2]+sum[x2]*sum[x2]);
}
int getdown(int x1,int x2)
{
    return sum[x1]-sum[x2];
}
int Q[1005];
int main()
{
    while(1)
    {
        scanf("%d%d",&n,&m);
        if(n==0&&m==0)
            break;
        sum[0]=0;
        sump[0]=0;
        for(int i=1; i<=n; i++)scanf("%d",&num[i]);
        for(int i=1; i<=n; i++)sum[i]=sum[i-1]+num[i];
        for(int i=1; i<=n; i++)sump[i]=sump[i-1]+num[i]*sum[i-1];
        memset(dp,0,sizeof(dp));
        for(int i=1; i<=n; i++)
            dp[1][i]=sump[i];
        for(int i=2; i<=m+1; i++)
        {
            int head=0,tail=0;
            Q[tail++]=i-1;
            for(int j=i; j<=n; j++)
            {
                while(head+1<tail&&getup(i,Q[head+1],Q[head])<sum[j]*getdown(Q[head+1],Q[head]))
                    head++;
                dp[i][j]=dp[i-1][Q[head]]+sump[j]-sump[Q[head]]-(sum[j]-sum[Q[head]])*sum[Q[head]];
                while(head+1<tail&&getup(i,j,Q[tail-1])*getdown(Q[tail-1],Q[tail-2])<=getup(i,Q[tail-1],Q[tail-2])*getdown(j,Q[tail-1]))
                    tail--;
                Q[tail++]=j;
            }
        }
        printf("%d\n",dp[m+1][n]);
    }
    return 0;
}
