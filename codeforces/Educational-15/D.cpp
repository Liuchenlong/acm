#include<stdio.h>
#include<cmath>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<set>
#include<vector>
#include<map>
using namespace std;
#define eps 1e-12

int main()
{
    long long d,k,a,b,t;
    scanf("%I64d%I64d%I64d%I64d%I64d",&d,&k,&a,&b,&t);
    if(d<=k)
    {
        printf("%I64d\n",d*a);
    }
    else
    {
        d-=k;
        long long ans=k*a;
        long long t1=t+k*a;
        long long t2=k*b;
        if(t1<t2)
        {
            ans+=(d/k)*t1;
            d%=k;
            ans+=min(d*b,t+d*a);
        }
        else
        {
            ans+=d*b;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
