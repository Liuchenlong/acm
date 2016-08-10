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
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
long long d,x,y;
long long exgcd(long long a,long long b,long long &x,long long &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    long long res=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return res;
}
int main()
{
    long long xx,yy,m,n,l;
    scanf("%I64d%I64d%I64d%I64d%I64d",&xx,&yy,&m,&n,&l);
    d=exgcd(m-n,l,x,y);
    if(d==0)
    {
        if(yy!=xx)
            printf("Impossible\n");
        else
            printf("0\n");
    }
    else
    {
        if((yy-xx)%d!=0)
            printf("Impossible\n");
        else
        {
            x*=(yy-xx)/d;
            x=(x%l+l)%l;
            printf("%I64d\n",x);
        }
    }
    return 0;
}
