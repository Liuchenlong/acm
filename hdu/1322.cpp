#include<stdio.h>
#include<cmath>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<set>
#include<vector>
#include<map>
using namespace std;
#define eps 1e-12

double dp[1005][105];
int c,n,m;
int main()
{
    while(scanf("%d",&c),c)
    {
        scanf("%d%d",&n,&m);
        if(m>c)
            printf("0.000\n");
        else
        {
            memset(dp,0,sizeof(dp));
            dp[0][0]=1;
            int maxn;
            if(n%2==1)
                maxn=1001;
            else
                maxn=1000;
            for(int i=1;i<=min(n,maxn);i++)
            {
                for(int j=0;j<=c;j++)
                {
                    if(j!=0)
                    {
                        dp[i][j]+=dp[i-1][j-1]*(1.0*(c-j+1)/c);
                    }
                    if(j!=c)
                    {
                        dp[i][j]+=dp[i-1][j+1]*(1.0*(j+1)/c);
                    }
                }
            }
            printf("%.3f\n",dp[min(maxn,n)][m]);
        }
    }
    return 0;
}
