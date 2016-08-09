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
#define eps 1e-9
const double pi=acos(-1.0);
long long gcd(long long a,long long b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int main()
{
    long long n,m;
    while(true)
    {
        scanf("%I64d%I64d",&n,&m);
        if(n==0&&m==0)
            break;
        long long fz=n*(m-1);
        long long fm=m*m;
        long long GD=gcd(fz,fm);
        fz/=GD;
        fm/=GD;
        printf("%I64d/%I64d\n",fz,fm);
    }
    return 0;
}
