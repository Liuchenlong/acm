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
unsigned long long dp[55][55][2];
void init()
{
    dp[0][0][0]=1;
    dp[0][0][1]=1;
    dp[1][1][0]=1;
    dp[1][1][1]=1;
    for(int i=2;i<=50;i++)
    {
        for(int j=1;j<=i;j++)
        {
            for(int k=1;k<j;k++)
                dp[i][j][0]+=dp[i-1][k][1];
            for(int k=j;k<=i-1;k++)
                dp[i][j][1]+=dp[i-1][k][0];
        }
    }
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        unsigned long long ans;
        if(m==1)
        {
            if(n<=2)
                ans=1;
            else
                ans=dp[n-1][2][0];
        }
        else
            ans=dp[n][m][0];
        printf("Case %d: %llu\n",cas,ans);
    }
    return 0;
}
