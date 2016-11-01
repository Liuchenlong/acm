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
#define eps 1e-14
const int mod=1e9+7;
int n,h;
double p;
int hi[2005];
int L[2005],R[2005];
bool vis[2005][2005][2][2];
double dp[2005][2005][2][2];
double getdp(int l,int r,int f1,int f2)
{
    if(vis[l][r][f1][f2])return dp[l][r][f1][f2];
    vis[l][r][f1][f2]=1;
    if(l>r)return 0;
    double ans=0;
    ans+=0.5*p*(min(h,hi[l]-hi[l-1]-h*f1)+getdp(l+1,r,0,f2));
    ans+=0.5*(1-p)*(min(h,hi[r+1]-hi[r]-h*f2)+getdp(l,r-1,f1,0));
    int lef=L[r];
    int rit=R[l];
    if(lef<=l)ans+=0.5*p*(min(h,hi[l]-hi[l-1]-h*f1)+hi[r]-hi[l]);
    else ans+=0.5*p*(hi[r]-hi[lef]+h+getdp(l,lef-1,f1,1));
    if(rit>=r)ans+=0.5*(1-p)*(min(h,hi[r+1]-hi[r]-h*f2)+hi[r]-hi[l]);
    else ans+=0.5*(1-p)*(hi[rit]-hi[l]+h+getdp(rit+1,r,1,f2));
    dp[l][r][f1][f2]=ans;
    return dp[l][r][f1][f2];

}
int main()
{
    scanf("%d%d",&n,&h);
    scanf("%lf",&p);
    for(int i=1;i<=n;i++)scanf("%d",&hi[i]);
    sort(hi+1,hi+1+n);
    hi[0]=-1e9;
    hi[n+1]=1e9;
    L[1]=1;
    R[n]=n;
    for(int i=2;i<=n;i++)
    {
        if(hi[i]-hi[i-1]<h)
            L[i]=L[i-1];
        else
            L[i]=i;
    }
    for(int i=n-1;i>=1;i--)
    {
        if(hi[i+1]-hi[i]<h)
            R[i]=R[i+1];
        else
            R[i]=i;
    }
    printf("%.10f\n",getdp(1,n,0,0));
    return 0;
}
