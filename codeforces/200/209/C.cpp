#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
#define eps 1e-8
int n,x;
int a[100005];
long long qpow(long long x,long long k,long long mod)
{
    long long ans=1;
    while(k)
    {
        if(k&1)
            ans=ans*x%mod;
        k>>=1;
        x=x*x%mod;
    }
    return ans;
}
int b[100005];
int main()
{
    scanf("%d%d",&n,&x);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    sort(a,a+n);
    long long sum=0;
    for(int i=0;i<n;i++)sum+=a[i];
    sum-=a[n-1];
    int cnt=0;
    long long has=0;
    for(int i=0;i<n;i++)b[i]=a[n-1]-a[i];
    sort(b,b+n);
    for(int i=0;i<n;i++)
    {
        bool flag=true;
        while(b[i]-cnt>0)
        {
            if(has%x==0)
            {
                has/=x;
                cnt++;
            }
            else
            {
                flag=false;
                break;
            }
        }
        if(!flag)
            break;
        has++;
    }
    while(has%x==0)
    {
        has/=x;
        cnt++;
    }
    cnt=min(cnt,a[n-1]);
    sum+=cnt;
    printf("%I64d\n",qpow(x,sum,(1e9+7)));
    return 0;
}
