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
long long dp[55];///到i这个点的方案有多少种(i个点的完全图)
void init()
{
    dp[1]=1;
    dp[2]=1;
    long long sum=2;
    for(int i=3;i<=50;i++)
    {
        dp[i]=sum;
        sum+=dp[i];
    }
}
int ans[55][55];
int main()
{
//    freopen("B-small-practice.in","r",stdin);
//    freopen("B-small-practice.out","w",stdout);
//    freopen("B-large-practice.in","r",stdin);
//    freopen("B-large-practice.out","w",stdout);
//    freopen("data.txt","w",stdout);
    init();
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        int B;
        long long m;
        scanf("%d%I64d",&B,&m);
        printf("Case #%d: ",cas);
        if(m>dp[B])
            printf("IMPOSSIBLE\n");
        else
        {
            long long sum=dp[B];
            for(int i=1;i<=B;i++)
            {
                for(int j=i+1;j<=B;j++)
                    ans[i][j]=1;
            }
            for(int j=B-1;j>=1;j--)
            {
                if(sum-dp[j]>=m)
                {
                    sum-=dp[j];
                    ans[j][B]=0;
                }
            }
            printf("POSSIBLE\n");
            for(int i=1;i<=B;i++)
            {
                for(int j=1;j<=B;j++)
                    printf("%d",ans[i][j]);
                printf("\n");
            }
        }
    }
    return 0;
}
