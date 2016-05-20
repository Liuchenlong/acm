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
int num[10005];
int dp[2][10005];
int squ(int x)
{
    return x*x;
}
int getup(int j,int x1,int x2)
{
    return (dp[j][x1]+squ(num[x1+1]))-(dp[j][x2]+squ(num[x2+1]));
}
int getdown(int x1,int x2)
{
    return 2*(num[x1+1]-num[x2+1]);
}
int Q[10005];
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%d",&num[i]);
        sort(num+1,num+1+n);
        for(int i=1;i<=n;i++)
            dp[0][i]=squ(num[i]-num[1]);
        int now=0,next=1;
        for(int i=2;i<=m;i++)
        {
            int head=0,tail=0;
            Q[tail++]=i-1;
            for(int j=i;j<=n;j++)
            {
                while(head+1<tail&&getup(now,Q[head+1],Q[head])<=getdown(Q[head+1],Q[head])*num[j])
                    head++;
                dp[next][j]=dp[now][Q[head]]+squ(num[j]-num[Q[head]+1]);
                while(head+1<tail&&getup(now,j,Q[tail-1])*getdown(Q[tail-1],Q[tail-2])<=getup(now,Q[tail-1],Q[tail-2])*getdown(j,Q[tail-1]))
                    tail--;
                Q[tail++]=j;
            }
            swap(now,next);
        }
        printf("Case %d: %d\n",cas,dp[now][n]);
    }
    return 0;
}
