#include <cstdio>
#include <cstring>
#include <map>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
#define eps 1e-8
long long a,b,c,d;
long long ac,adbc,bd;
long long f(long long x,long long y)
{
    return (ac*x*x+adbc*x*y+bd*y*y);
}
int n;
long long x[1000005],y[1000005];
int main()
{
    while(scanf("%I64d%I64d%I64d%I64d",&a,&b,&c,&d)!=EOF)
    {
        ac=a*c;
        adbc=a*d+b*c;
        bd=b*d;
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%I64d%I64d",&x[i],&y[i]);
        long long mx=f(x[0],y[0]);
        long long mn=f(x[0],y[0]);
        for(int i=1;i<n;i++)
        {
            long long val=f(x[i],y[i]);
            mx=max(mx,val);
            mn=min(mn,val);
        }
        printf("%.0f\n",abs(1.0*(mx-mn)/(double)(a*d-b*c)));
    }
    return 0;
}
