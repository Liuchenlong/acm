#include<stdio.h>
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
long long len[65];
long long sum[65];
void init()
{
    len[1]=1;
    sum[1]=1;
    for(int i=2;i<=61;i++)
    {
        len[i]=2LL*len[i-1]+1LL;
        sum[i]=1+len[i-1];
    }
}
long long cal(long long r)
{
    if(r<=0)
        return 0;
    int pos=upper_bound(len,len+61,r)-len-1;
    long long x=len[pos];
    if(r==x)
        return sum[pos];
    else if(r==x+1)
        return sum[pos]+1;
    else
        return sum[pos]+1+(len[pos]-(len[pos+1]-r))-(sum[pos]-cal(len[pos+1]-r));
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while(T--)
    {
        long long l,r;
        scanf("%I64d%I64d",&l,&r);
        printf("%I64d\n",cal(r)-cal(l-1));
    }
    return 0;
}
