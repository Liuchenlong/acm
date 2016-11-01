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
#include<bitset>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
long long cal(long long x)
{
    long long ans=0;
    for(long long i=2;i*i*i<=x;i++)
    {
        ans+=x/(i*i*i);
    }
    return ans;
}
int main()
{
    long long m;
    scanf("%I64d",&m);
    long long l=8,r=1e18;
    bool flag=false;
    while(l<r)
    {
        long long mid=(l+r)/2;
        long long num=cal(mid);
        if(num>=m)
        {
            if(num==m)
                flag=true;
            r=mid;
        }
        else
            l=mid+1;
    }
    if(flag)
        printf("%I64d\n",r);
    else
        printf("-1\n");
    return 0;
}
