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
#define LL long long
#define pii pair<int,int>
int n;
long long v[200005];
long long pre[200005];
long long dp[200005];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%I64d",&v[i]);
        pre[i]=pre[i-1]+v[i];
    }
    long long mx=pre[n]-dp[n];
    for(int i=n-1;i>=1;i--)
    {
        dp[i]=mx;
        mx=max(mx,pre[i]-dp[i]);
    }
    printf("%I64d\n",dp[1]);
    return 0;
}
