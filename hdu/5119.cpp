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
#define eps 1e-8
long long dp[42][1<<20];
int n,m;
int num[42];
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        memset(dp,0,sizeof(dp));
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)scanf("%d",&num[i]);
        dp[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<(1<<20);j++)
            {
                dp[i][j]+=dp[i-1][j];
                dp[i][j^num[i]]+=dp[i-1][j];
            }
        }
        long long ans=0;
        for(int i=m;i<(1<<20);i++)
            ans+=dp[n][i];
        printf("Case #%d: %I64d\n",cas,ans);
    }
    return 0;
}
