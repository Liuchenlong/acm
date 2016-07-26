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
#define eps 1e-7

long long gcd(long long a,long long b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
long long w[100005];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0; i<n; i++)scanf("%I64d",&w[i]);
        long long sum=0,sum2=0;
        for(int i=0; i<n; i++)
        {
            sum+=abs(w[i]);
            sum2+=w[i]*w[i];
        }
        sum=sum*sum;
        long long fz=sum2*n-sum;
        long long fm=n;
        long long GD=gcd(fz,fm);
        fz/=GD;
        fm/=GD;
        printf("%I64d/%I64d\n",fz,fm);
    }
    return 0;
}
