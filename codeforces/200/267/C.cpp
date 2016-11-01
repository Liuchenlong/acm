#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
using namespace std;
long long p[5005];
long long pre[5005];
long long dp[2][5005];
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)scanf("%I64d",&p[i]);
    for(int i=1;i<=n;i++)pre[i]=pre[i-1]+p[i];
    int now=0,next=1;
    for(int i=1;i<=k;i++)
    {
        memset(dp[next],0,sizeof(dp[next]));
        for(int j=m;j<=n;j++)
        {
            dp[next][j]=max(dp[next][j-1],dp[now][j-m]+pre[j]-pre[j-m]);
        }
        swap(now,next);
    }
    printf("%I64d\n",dp[now][n]);
    return 0;
}
