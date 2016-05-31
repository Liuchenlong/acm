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
#define SIZE 1001005
int a,b;
int dp[300005];
int inf=100000000;
int main()
{

    scanf("%d%d",&a,&b);
    for(int i=0;i<=300000;i++)dp[i]=inf;
    dp[b]=0;
    for(int i=b-1;i>=1;i--)
    {
        for(int j=1;j*j<=i;j++)
        {
            if(i%j==0)
            {
                dp[i]=min(dp[i],1+dp[i+j]);
                if(j*j!=i)
                    dp[i]=min(dp[i],1+dp[i+i/j]);
            }
        }
    }
    int ans=dp[a];
    if(ans==inf)printf("-1\n");
    else
        printf("%d\n",ans);
    return 0;
}
