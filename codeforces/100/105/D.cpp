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

double dp[1005][1005];
bool vis[1005][1005];
double getdp(int w,int b)
{
    if(w==0)return 0;
    if(b==0)return 1;
    if(vis[w][b])return dp[w][b];

    double ans=1.0*w/(w+b);
    if(b>=3)
        ans=ans+(1.0*b/(w+b))*(1.0*(b-1)/(w+b-1))*(1.0*(b-2)/(w+b-2))*getdp(w,b-3);
    if(b>=2)
        ans=ans+(1.0*b/(w+b))*(1.0*(b-1)/(w+b-1))*(1.0*w/(w+b-2))*getdp(w-1,b-2);
    vis[w][b]=1;
    dp[w][b]=ans;
    return dp[w][b];
}
int main()
{
    int w,b;
    scanf("%d%d",&w,&b);
    printf("%.10f\n",getdp(w,b));
    return 0;
}
