#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
#define eps 1e-8
bool zero(double x)
{
    if(fabs(x)<=eps)return true;
    return false;
}
int sign(double x)
{
    if(zero(x))return 0;
    if(x>0)return 1;
    return -1;
}
int n;
double dp[100010][2];
int main()
{
    dp[1][0]=1;
    dp[1][1]=0;
    for(int i=2;i<=100000;i++)
    {
        dp[i][0]=1.0/i+(i-1)*dp[i-1][1]/i;
        dp[i][1]=1.0-dp[i][0];
    }
    while(scanf("%d",&n)!=EOF)
    {
        if(sign(dp[n+1][0]-dp[n+1][1])==0)printf("0\n");
        else if(sign(dp[n+1][0]-dp[n+1][1])==1)printf("1\n");
        else printf("2\n");
    }
    return 0;
}
