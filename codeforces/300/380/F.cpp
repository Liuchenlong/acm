#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define eps 1e-8

int val[4005];
int sum[4005];
int n;
int dp[4005][100][100][2];
bool vis[4005][100][100][2];
int run(int L,int cnt,int k,int type)
{
    if(vis[L][cnt][k][type])
        return dp[L][cnt][k][type];
    int l=L,r;
    if(type==0)
    {
        r=n-(L-1)-cnt;
    }
    else
    {
        r=n-(L-k-1)-cnt;
    }
    if(l+k-1>r)
    {
        dp[L][cnt][k][type]=0;
        vis[L][cnt][k][type]=0;
    }
    else
    {
        vis[L][cnt][k][type]=1;
        if(type==0)
        {
            dp[L][cnt][k][type]=run(L+k,cnt,k,1)+sum[L+k-1]-sum[L-1];
            if(l+k<=r)dp[L][cnt][k][type]=max(dp[L][cnt][k][type],sum[L+k]-sum[L-1]+run(L+k+1,cnt,k+1,1));
        }
        else
        {
            dp[L][cnt][k][type]=run(L,cnt,k,0)-(sum[r]-sum[r-k]);
            if(l+k<=r)dp[L][cnt][k][type]=min(dp[L][cnt][k][type],-(sum[r]-sum[r-k-1])+run(L,cnt+1,k+1,0));
        }
    }
    return dp[L][cnt][k][type];
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&val[i]);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+val[i];
    printf("%d\n",run(1,0,1,0));
    return 0;
}
