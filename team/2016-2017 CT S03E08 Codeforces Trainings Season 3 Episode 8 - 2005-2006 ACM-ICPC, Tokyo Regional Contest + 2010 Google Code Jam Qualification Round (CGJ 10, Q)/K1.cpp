#include <cstdio>
#include <cstring>
#include <map>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
#define eps 1e-8

long long gcd(long long a,long long b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
long long a[1005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%I64d",&a[i]);
    bool flag=false;
    sort(a,a+n);
    long long ans;
    for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)
    {
        if(!flag)
        {
            flag=true;
            ans=a[j]-a[i];
        }
        else
            ans=gcd(ans,a[j]-a[i]);
    }
    printf("%I64d\n",(ans-a[0]%ans)%ans);
    return 0;
}
