#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<time.h>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
int dp[4005][4005];
int num[4005];
map <int,int>r;
int pos=1;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
        if(r[num[i]]==0)
            r[num[i]]=pos++;
    }
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=1;
        dp[0][i]=1;
    }
    int ans=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            dp[i][r[num[j]]]=max(dp[j][r[num[i]]],dp[j][0])+1;
            ans=max(ans,dp[i][r[num[j]]]);
        }

    }
    printf("%d\n",ans);
    return 0;
}
