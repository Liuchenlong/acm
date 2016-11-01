#include<cstdio>
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
#define abs(x) (x>=0?x:-x)
long long m;
long long h1,a1,x1,y1;
long long h2,a2,x2,y2;
long long cal(long long h,long long x,long long y)
{
    return (x*h+y)%m;
}
bool vis[1000005];
long long d,x,y;
long long exgcd(long long a,long long b,long long &x,long long &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    else
    {
        long long ret=exgcd(b,a%b,x,y);
        long long temp=x;
        x=y;
        y=temp-a/b*y;
        return ret;
    }
}
int main()
{
    scanf("%I64d",&m);
    scanf("%I64d%I64d",&h1,&a1);
    scanf("%I64d%I64d",&x1,&y1);
    scanf("%I64d%I64d",&h2,&a2);
    scanf("%I64d%I64d",&x2,&y2);
    long long d1=1,d2=1;
    long long na1=0,na2=0;
    long long term=h1;
    vis[term]=1;
    while(1)
    {
        term=cal(term,x1,y1);
        if(term==a1||vis[term])
        {
            vis[term]=1;
            break;
        }
        d1++;
        vis[term]=1;
    }
    if(!vis[a1])
    {
        printf("-1\n");
        return 0;
    }
    memset(vis,0,sizeof(vis));
    na1=1;
    term=cal(a1,x1,y1);
    while(term!=a1)
    {
        if(vis[term])
        {
            na1=0;
            break;
        }
        na1++;
        vis[term]=1;
        term=cal(term,x1,y1);

    }

    memset(vis,0,sizeof(vis));
    term=h2;
    vis[term]=1;
    while(1)
    {
        term=cal(term,x2,y2);
        if(term==a2||vis[term])
        {
            vis[term]=1;
            break;
        }
        d2++;
        vis[term]=1;
    }
    if(!vis[a2])
    {
        printf("-1\n");
        return 0;
    }
    memset(vis,0,sizeof(vis));
    na2=1;
    term=cal(a2,x2,y2);
    while(term!=a2)
    {
        if(vis[term])
        {
            na2=0;
            break;
        }
        na2++;
        vis[term]=1;
        term=cal(term,x2,y2);

    }
    if(d1==d2)
    {
        printf("%I64d\n",d1);
        return 0;
    }
    d=exgcd(na1,na2,x,y);
    if(d==0)
    {
        if(d1==d2)
        {
            printf("%I64d\n",d1);
            return 0;
        }
        else
        {
            printf("-1\n");
            return 0;
        }
    }
    if((d2-d1)%d!=0)
    {
        printf("-1\n");
        return 0;
    }
    if(na2==0)
    {
        x=(d2-d1)/na1;
        if(x<0)
            printf("-1\n");
        else
            printf("%I64d\n",(d1+x*na1));
        return 0;
    }
    if(na1==0)
    {
        y=(d2-d1)/na2;
        y*=-1;
        if(y<0)
            printf("-1\n");
        else
            printf("%I64d\n",(d2+y*na2));
        return 0;
    }
    long long t=(d2-d1)/d;
    x*=t;
    y*=(-t);
    long long tt1=abs(na2/d);
    long long tt2=abs(na1/d);
    x=(x%tt1+tt1)%tt1;
    y=(y%tt2+tt2)%tt2;
    printf("%I64d\n",max((d1+x*na1),(d2+y*na2)));
    return 0;
}
