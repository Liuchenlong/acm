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
long long mod=1e9+7;
long long dp[1005][1005];
void init()
{
    dp[1][0]=1;
    for(int i=2;i<=1000;i++)
    {
        dp[i][0]=1;
        for(int j=1;j<i;j++)
        {
            dp[i][j]=dp[i-1][j]*(j+1)+dp[i-1][j-1]*(i-j);
            dp[i][j]%=mod;
        }
    }
}

int main()
{
    init();
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        printf("%I64d\n",dp[n][k]);
    }

    return 0;
}
