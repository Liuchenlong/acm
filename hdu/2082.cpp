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
#include<bitset>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-7
const int maxn=100005;
int num[27];
int dp[2][55];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(dp,0,sizeof(dp));
        for(int i=1; i<=26; i++)
        {
            scanf("%d",&num[i]);
        }
        dp[0][0]=1;
        for(int i=1; i<=26; i++)
        {
            for(int j=num[i]; j>=1; j--)
            {
                for(int k=50; k>=j*i; k--)
                    dp[1][k]+=dp[0][k-j*i];
            }
            for(int j=1;j<=50;j++)
                dp[0][j]+=dp[1][j];
            memset(dp[1],0,sizeof(dp[1]));
        }
        int ans=0;
        for(int i=1;i<=50;i++)ans+=dp[0][i];
        printf("%d\n",ans);
    }
    return 0;
}
