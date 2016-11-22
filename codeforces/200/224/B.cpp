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
int a,b,w,x,c;
bool check(long long t)
{
    long long val=(long long)(1e15)*w+b;
    long long now=val-1LL*t*x;
    long long na=1LL*a-(val/w-now/w);
    long long nc=c-t;
    return nc<=na;
}
int main()
{
    scanf("%d%d%d%d%d",&a,&b,&w,&x,&c);
    long long l=0,r=(1LL<<50);
    while(l<r)
    {
        long long mid=(l+r)/2;
        if(check(mid))
            r=mid;
        else
            l=mid+1;
    }
    printf("%I64d\n",l);
    return 0;
}
