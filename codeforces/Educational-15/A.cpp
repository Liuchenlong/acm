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

int a[1000005];
int dp[1000005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        dp[i]=1;
        scanf("%d",&a[i]);
    }
    for(int i=2; i<=n; i++)
    {
        if(a[i]>a[i-1])
            dp[i]=max(dp[i-1]+1,dp[i]);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,dp[i]);
    }
    printf("%d\n",ans);
    return 0;
}
