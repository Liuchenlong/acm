#include<cstdio>
#include<cmath>
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
#define abs(a) (a<0?-a:a)
#define SIZE 500000
#define INF 0x7fffffff
const long long mod=1e9+7;
int n;
long long gcd(long long a,long long b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
long long lcm(long long a,long long b)
{
    return a/gcd(a,b)*b;
}
long long num[20];
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        long long m;
        scanf("%lld%d",&m,&n);
        for(int i=0;i<n;i++)
            scanf("%lld",&num[i]);
        long long ans=0;
        for(int i=0;i<(1<<n);i++)
        {
            int sig=1;
            long long val=1;
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j))
                {
                    sig*=-1;
                    val=lcm(val,num[j]);
                }
            }
            ans+=(m/val)*sig;
        }
        printf("Case %d: %lld\n",cas,ans);
    }
    return 0;
}
