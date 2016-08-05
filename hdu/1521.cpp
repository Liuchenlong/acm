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
const int mod=100000007;
int n,m;
int num[15];
double dp[2][15];
double fac[15];
int main()
{
    fac[0]=1;
    for(int i=1;i<=10;i++)
        fac[i]=fac[i-1]*i;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)scanf("%d",&num[i]);
        for(int i=0;i<=num[0];i++)dp[0][i]=1.0/fac[i];
        int now=0,next=1;
        for(int i=1;i<n;i++)
        {
            memset(dp[next],0,sizeof(dp[next]));
            for(int j=0;j<=num[i];j++)
            {
                for(int k=j;k<=m;k++)
                    dp[next][k]+=(1.0/fac[j])*dp[now][k-j];
            }
            swap(now,next);
        }
        printf("%.0f\n",dp[now][m]*fac[m]);
    }
    return 0;
}
