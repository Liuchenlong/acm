#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)<0?-(a):(a))
#define SIZE 10000005
bool isprime[SIZE];
int prime[670000],prinum;
void getprime()//prime
{
    isprime[0]=1;
    isprime[1]=1;
    for(int i=2; i<SIZE; i++)
    {
        if(!isprime[i])
        {
            prime[prinum++]=i;
        }
        for(int j=0; j<prinum; j++)
        {
            if(i*prime[j]>SIZE)
                break;
            isprime[i*prime[j]]=1;
            if(i%prime[j]==0)
                break;
        }
    }
}
int main()
{

    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        long long n;
        scanf("%lld",&n);
        long long ans=0;
        long long r=n;
        for(long long i=2;i*i<=n;i++)
        {

            long long t=n/i;
            ans=ans+(r-t)*(t+1+r)/2*(i-1);
            r=t;

        }

        for(long long i=1;i<=r;i++)
            ans=ans+n/i*i;
        ans=ans-n-n*(n+1)/2+1;
        if(n==0)
            ans=0;
        printf("Case %d: %lld\n",cas,ans);
    }
    return 0;
}
