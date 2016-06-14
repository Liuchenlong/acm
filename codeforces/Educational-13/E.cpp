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

double p[22][22];
int ones[1<<18];
double dp[18][1<<18];
int main()
{
    for(int i=0; i<(1<<18); i++)
    {
        int t=i;
        while(t)
        {
            ones[i]+=t%2;
            t/=2;
        }
    }
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)for(int j=0; j<n; j++)scanf("%lf",&p[i][j]);
    dp[0][(1<<n)-1]=1.0;
    for(int i=(1<<n)-2;i>=1;i--)
    {
        for(int j=0;j<n;j++)
        {
            if(i&(1<<j))
            {
                for(int k=0;k<n;k++)
                {
                    if(i&(1<<k))
                        continue;
                    dp[j][i]=max(dp[j][i],p[j][k]*dp[j][i|(1<<k)]+p[k][j]*dp[k][i|(1<<k)]);
                }
            }
        }
    }
    double ans=0;
    for(int i=0;i<n;i++)
        ans=max(ans,dp[i][1<<i]);
    printf("%.10f\n",ans);
    return 0;
}
