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
int dp[1005][1005][11][2];
char str1[1005];
char str2[1005];
int n,m,t;
int main()
{
    scanf("%d%d%d",&n,&m,&t);
    scanf("%s",str1);
    scanf("%s",str2);
    for(int i=n-1; i>=0; i--)for(int j=m-1; j>=0; j--)
        {
            if(str1[i]==str2[j])
            {
                for(int k=0; k<=t; k++)
                {
                    if(k)
                    {
                        dp[i][j][k][1]=max(dp[i+1][j+1][k][1],dp[i+1][j+1][k-1][0])+1;
                        dp[i][j][k][0]=dp[i][j][k][1];
                    }
                    dp[i][j][k][0]=max(dp[i][j][k][0],dp[i+1][j][k][0]);
                    dp[i][j][k][0]=max(dp[i][j][k][0],dp[i][j+1][k][0]);
                }
            }
            else
            {
                for(int k=0; k<=t; k++)
                {
                    dp[i][j][k][0]=max(dp[i+1][j][k][0],dp[i][j+1][k][0]);
                    dp[i][j][k][0]=max(dp[i+1][j+1][k][0],dp[i][j][k][0]);
                }
            }
        }
    printf("%d\n",max(dp[0][0][t][0],dp[0][0][t][1]));
    return 0;
}
