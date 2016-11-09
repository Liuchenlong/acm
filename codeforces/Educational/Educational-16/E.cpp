#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
using namespace std;

long long dp[10000005];
int main()
{
    int n;
    long long x,y;
    scanf("%d%I64d%I64d",&n,&x,&y);
    dp[1]=x;
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+x;
        if(i%2==0)
            dp[i]=min(dp[i/2]+y,dp[i]);
        else
            {
                dp[i]=min(dp[i],dp[i/2]+y+x);
                dp[i]=min(dp[i],dp[i/2+1]+y+x);
            }
    }
    printf("%I64d\n",dp[n]);
    return 0;
}
