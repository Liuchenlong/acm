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
long long d,x,y;
long long gcd(long long a,long long b)
{
    if(b==0)
        return a;
    else return gcd(b,a%b);
}
long long lcm(long long a,long long b)
{
    return a/gcd(a,b)*b;
}
//扩展欧几里得
//ax+by=d;
//x'=x+b/d;
//y'=y-a/d;
long long exgcd(long long a,long long b,long long &x,long long &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    else
    {
        long long ret=exgcd(b,a%b,x,y);
        long long temp=x;
        x=y;
        y=temp-a/b*y;
        return ret;
    }
}

long long a,b;
bool isprime[SIZE];
int prime[SIZE],prinum;
void getprime()
{
    for(int i=2; i<SIZE; i++)
    {
        if(isprime[i])
            continue;
        prime[prinum++]=i;
        for(int j=2*i; j<SIZE; j+=i)
            isprime[j]=1;
    }
}
long long qpow(long long x,long long k)
{
    long long b = 1;
    while (k > 0)
    {
        if (k & 1)
            b = (b*x)%mod;
        k = k >> 1 ;
        x = (x*x)%mod;
    }
    return b;
}
long long inv(long long x)
{
    return qpow(x,mod-2);
}
long long num[101][2];
int facnum;
int main()
{
    getprime();
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        memset(num,0,sizeof(num));
        facnum=0;
        scanf("%lld%lld",&a,&b);
        if(a==0)
        {
            printf("0\n");
            return 0;
        }
        for(int i=0; i<prinum; i++)
        {
            if(prime[i]>a/prime[i])
                break;
            if(a%prime[i]==0)
            {
                num[facnum][0]=prime[i];
                while(a%prime[i]==0)
                {
                    num[facnum][1]++;
                    a/=prime[i];
                }
                facnum++;
            }
        }
        if(a!=1)
        {
            num[facnum][0]=a;
            num[facnum][1]=1;
            facnum++;
        }
        long long ans=1;
        for(int i=0; i<facnum; i++)
        {
            num[i][1]*=b;
            num[i][0]%=mod;
        }
        for(int i=0; i<facnum; i++)
        {
            if(num[i][0]==1)
            {
                ans*=(num[i][1]+1);
                ans%=mod;
                continue;
            }

            long long fz=qpow(num[i][0],(num[i][1]+1))-1+mod;
            fz%=mod;
            fz*=inv((num[i][0]-1+mod)%mod);
            fz%=mod;
            ans*=fz;
            ans%=mod;
        }
        printf("Case %d: %lld\n",cas,ans);
    }
    return 0;
}
