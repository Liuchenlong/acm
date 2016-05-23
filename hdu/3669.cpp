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
struct node
{
    long long h,w;
};
node p[50005];
bool cmp(node a,node b)
{
    if(a.h==b.h)
        return a.w>b.w;
    return a.h>b.h;
}
long long dp[105][50005];
int n,k;
int Q[50005];
long long getup(int i,int j,int k)
{
    return dp[i][j]-dp[i][k];
}
long long getdown(int j,int k)
{
    return p[k+1].h-p[j+1].h;
}
int main()
{
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        for(int i=1;i<=n;i++)scanf("%I64d%I64d",&p[i].w,&p[i].h);
        sort(p+1,p+1+n,cmp);
        int m=1;
        for(int i=2;i<=n;i++)
        {
            if(p[i].w>p[m].w)
            {
                p[++m]=p[i];
            }
        }
        memset(dp,0,sizeof(dp));
        long long ans;
        for(int i=1;i<=m;i++)
        dp[1][i]=p[1].h*p[i].w;
        ans=dp[1][m];
        for(int i=2;i<=min(k,m);i++)
        {
            int head=0,tail=0;
            Q[tail++]=i-1;
            for(int j=i;j<=m;j++)
            {
                while(head+1<tail&&getup(i-1,Q[head+1],Q[head])<=getdown(Q[head+1],Q[head])*p[j].w)
                    head++;
                dp[i][j]=dp[i-1][Q[head]]+p[Q[head]+1].h*p[j].w;
                while(head+1<tail&&getup(i-1,j,Q[tail-1])*getdown(Q[tail-1],Q[tail-2])<=getup(i-1,Q[tail-1],Q[tail-2])*getdown(j,Q[tail-1]))
                    tail--;
                Q[tail++]=j;
            }
            if(dp[i][m]>=ans)
                break;
            ans=min(ans,dp[i][m]);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
