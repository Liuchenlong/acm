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
#define eps 1e-8
int n;
long long a[3005];
long long dp[3005][3005];
int main()
{
    vector<long long>vec;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%I64d",&a[i]);
        a[i]-=i;
        vec.push_back(a[i]);
    }
    sort(vec.begin(),vec.end());
    int siz=unique(vec.begin(),vec.end())-vec.begin();
    memset(dp,0x3f,sizeof(dp));
    for(int i=0;i<siz;i++)dp[0][i]=abs(a[0]-vec[i]);
    for(int i=1;i<n;i++)
    {
        long long bef=dp[i-1][0];
        for(int j=0;j<siz;j++)
        {
            bef=min(bef,dp[i-1][j]);
            dp[i][j]=bef+abs(a[i]-vec[j]);
        }
    }
    long long ans=dp[n-1][0];
    for(int i=1;i<siz;i++)
    {
        ans=min(ans,dp[n-1][i]);
    }
    printf("%I64d\n",ans);
    return 0;
}
