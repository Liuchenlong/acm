#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8

int maxv[105][105];
int sum[105][105];
int num[105];
int val[105][105];
int dp[105][10005];
int sumnum[105];
int main()
{
    memset(maxv,0x3f,sizeof(maxv));
    memset(dp,0x3f,sizeof(dp));
    int n,m;
    scanf("%d%d",&n,&m);
    int ssum=0;
    for(int i=0; i<n; i++)
    {
        scanf("%d",&num[i]);
        for(int j=1; j<=num[i]; j++)
        {
            scanf("%d",&val[i][j]);
            ssum+=val[i][j];
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=1; j<=num[i]; j++)
        {
            sum[i][j]=sum[i][j-1]+val[i][j];
        }
    }
    sumnum[0]=num[0];
    for(int i=1; i<n; i++)
        sumnum[i]=sumnum[i-1]+num[i];
    if(m>=sumnum[n-1])
    {
        printf("%d\n",ssum);;
        return 0;
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=num[i]; j++)
        {
            for(int k=j; k<=num[i]; k++)
            {
                maxv[i][k-j]=min(maxv[i][k-j],sum[i][k]-sum[i][j]);
            }
        }
    }
    for(int i=0; i<=num[0]; i++)
        dp[0][i]=maxv[0][i];
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<=sumnum[i]; j++)
        {
            for(int k=0; k<=j&&k<=num[i]; k++)
                dp[i][j]=min(dp[i][j],dp[i-1][j-k]+maxv[i][k]);
        }
    }
    printf("%d\n",ssum-dp[n-1][sumnum[n-1]-m]);
    return 0;
}
