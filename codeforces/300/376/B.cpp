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
bool dp[200005][2];
int a[200005];
int n;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        if(dp[i-1][0])
            dp[i][a[i]%2]=1;
        if(dp[i-1][1])
        {
            if(a[i])
                dp[i][(a[i]-1)%2]=1;
        }
    }
    if(dp[n][0]) printf("YES\n");
    else printf("NO\n");
    return 0;
}
