#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
bool zero(double x)
{
    return fabs(x)<=eps;
}
double dp[2005][50];
void init()
{
    for(int i=0;i<25;i++)dp[0][i]=0;
    for(int i=1;i<=2000;i++)dp[i][0]=10000000;
    for(int i=1;i<=2000;i++)
    {
        double tmp;
        for(int j=1;j<=20;j++)
        {
            for(int k=1;k<=i;k++)
            {
                double sum=(dp[k-1][j-1]+1)*(1.0*k)/(i+1)+(dp[i-k][j]+1)*(1.0*(i+1-k)/(i+1));
                if(zero(dp[i][j]))
                    dp[i][j]=sum;
                else
                    dp[i][j]=min(dp[i][j],sum);
            }
        }
    }
}
int main()
{
    init();
    int k,w;
    while(scanf("%d%d",&k,&w)!=EOF)
    {
        printf("%.6f\n",dp[k][min(w,20)]);
    }
    return 0;
}
