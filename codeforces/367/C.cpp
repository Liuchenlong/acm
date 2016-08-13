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
int n;
string str[100005][2];
long long c[100005];
long long dp[100005][2];
char sstr[100005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)scanf("%I64d",&c[i]);
    for(int i=0; i<n; i++)
    {
        scanf("%s",sstr);
        str[i][0]=string(sstr);
        reverse(sstr,sstr+strlen(sstr));
        str[i][1]=string(sstr);
    }
    memset(dp,0x3f,sizeof(dp));
    long long inf=dp[0][0];
    dp[0][0]=0;
    dp[0][1]=c[0];
    for(int i=1; i<n; i++)
    {
        if(str[i][0]>=str[i-1][0])
        {
            dp[i][0]=min(dp[i][0],dp[i-1][0]);
        }
        if(str[i][0]>=str[i-1][1])
        {
            dp[i][0]=min(dp[i][0],dp[i-1][1]);
        }
        if(str[i][1]>=str[i-1][0])
        {
            dp[i][1]=min(dp[i][1],dp[i-1][0]+c[i]);
        }
        if(str[i][1]>=str[i-1][1])
        {
            dp[i][1]=min(dp[i][1],dp[i-1][1]+c[i]);
        }
    }
    long long ans=min(dp[n-1][0],dp[n-1][1]);
    if(ans==inf)ans=-1;
    printf("%I64d\n",ans);
    return 0;
}
