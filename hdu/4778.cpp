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

int dp[1<<21];
int bag[21][11];
int G,B,S;
int sum;
int num[11];
int main()
{
    while(1)
    {
        scanf("%d%d%d",&G,&B,&S);
        if(G==0&&B==0&&S==0)
            break;
        memset(bag,0,sizeof(bag));
        sum=0;
        memset(num,0,sizeof(num));
        for(int i=0; i<B; i++)
        {
            int n;
            scanf("%d",&n);
            for(int j=0; j<n; j++)
            {
                int t;
                scanf("%d",&t);
                bag[i][t-1]++;
            }
            for(int j=0; j<G; j++)
                num[j]+=bag[i][j];
        }
        for(int i=0; i<G; i++)
            sum+=num[i]/S;
        memset(dp,0,sizeof(dp));
        for(int i=(1<<B)-2; i>=0; i--)
        {
            memset(num,0,sizeof(num));
            int now=0;
            for(int j=0; j<B; j++)
            {
                if(i&(1<<j))
                {
                    for(int k=0; k<G; k++)
                        num[k]+=bag[j][k];
                }
            }
            for(int j=0; j<G; j++)
            {

                now+=num[j]/S;
                num[j]%=S;
            }
            int res=sum-now;
            for(int j=0; j<B; j++)
            {
                if((i&(1<<j))==0)
                {
                    int cnt=0;
                    for(int k=0; k<G; k++)
                    {
                        cnt+=(num[k]+bag[j][k])/S;
                    }
                    if(cnt>0)
                        dp[i]=max(dp[i],dp[i|(1<<j)]+cnt);
                    else
                        dp[i]=max(dp[i],res-dp[i^(1<<j)]);
                }
            }
        }
        printf("%d\n",dp[0]-(sum-dp[0]));
    }
    return 0;
}
