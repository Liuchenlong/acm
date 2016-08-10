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
#define SIZE 1000005
bool isprime[SIZE];
int prime[SIZE],prinum;
int num[SIZE];
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
bool pri(int n)
{
    if(n==1&&n==2)
        return true;
    for(int i=2; i*i<=n; i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}
int main()
{
    getprime();
    long long n;
    int cas=0;
    while(scanf("%lld",&n),n)
    {
        cas++;
        if(n==1)
        {
            printf("Case %d: 2\n",cas);
            continue;
        }
        int numyz=0;
        long long ans=0;
        for(int i=0; i<prinum; i++)
        {
            if((long long)prime[i]*(long long)prime[i]>n)
                break;
            if(n%prime[i]==0)
            {
                long long tt=n;
                while(n%prime[i]==0)
                {
                    n/=prime[i];
                }
                numyz++;
                ans+=(tt/n);
            }
        }
        if(n!=1)
        {
            numyz++;
            ans+=n;
        }
        if(numyz==1)
            ans++;
        printf("Case %d: %lld\n",cas,ans);
    }
    return 0;
}
