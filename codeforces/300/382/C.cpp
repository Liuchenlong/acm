#include <bits/stdc++.h>

using namespace std;

long long dp[105];

int main()
{
    dp[1]=2;
    dp[0]=1;
    for(int i=2;i<=100;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    long long n;
    scanf("%I64d",&n);
    int ans;
    for(int i=1;;i++)
    {
        if(dp[i]<=n)
            ans=i;
        else
            break;
    }
    printf("%d\n",ans);
    return 0;
}
