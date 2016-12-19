#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<time.h>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
int n,x,y,c;
long long fang(long long t)
{
    long long ans=t*t;
    return ans;
}
bool solve(long long t)
{
    long long ans=fang(t)+fang(t+1);
    if(x+t>n)
        ans-=fang(x+t-n);
    if(x-t<1)
        ans-=fang(1-x+t);
    if(y+t>n)
        ans-=fang(y+t-n);
    if(y-t<1)
        ans-=fang(1-y+t);
    if(x+t>n&&y+t>n&&x+t-n-(n-y)>0)
        ans+=(x+t-n-(n-y+1))*(x+t-n-(n-y+1)+1)/2;
    if(x+t>n&&y-t<1&&x+t-n-y>0)
        ans+=(x+t-n-y)*(x+t-n-y+1)/2;
    if(x-t<1&&y+t>n&&y+t-n-x>0)
        ans+=(y+t-n-x)*(y+t-n-x+1)/2;
    if(x-t<1&&y-t<1&&1-x+t-y>0)
        ans+=(1-x+t-y)*(1-x+t-y+1)/2;
    if(ans>=c)
        return true;
    else return false;
}
int main()
{
    scanf("%d%d%d%d",&n,&x,&y,&c);
    long long l=0,r=2*n;
    while(l<r)
    {
        long long mid=(l+r)/2;
        if(solve(mid))
            r=mid-1;
        else
            l=mid+1;
    }
    while(solve(l)&&l>0)l--;
    while(!solve(l))l++;
    printf("%I64d\n",l);
    return 0;
}
