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
const int maxn=1000005;
bool notprime[maxn];
int prime[maxn],prinum;
void getprime()
{
    for(int i=2; i<maxn; i++)
    {
        if(notprime[i])continue;
        prime[prinum++]=i;
        for(int j=2*i; j<maxn; j+=i)
            notprime[j]=1;
    }
}
bool check(long long x)
{
    for(int i=0; i<prinum; i++)
    {
        if(prime[i]>x/prime[i])
            break;
        if(x%prime[i]==0)
        {
            int tim=0;
            while(x%prime[i]==0)
            {
                tim++;
                x/=prime[i];
            }
            if(tim>1)
                return false;
        }
    }
    return true;
}
int main()
{
    getprime();
    int T;
    scanf("%d",&T);
    while(T--)
    {
        long long x;
        scanf("%lld",&x);
        if(x<=6)
        {
            printf("%lld\n",abs(x-4));
            continue;
        }
        long long ans=1e18;
        long long k=floor(sqrt(x));
        while(true)
        {
            if(check(k))
            {
                ans=min(ans,x-k*k);
                break;
            }
            k--;
        }
        k=ceil(sqrt(x));
        while(true)
        {
            if(check(k))
            {
                ans=min(ans,k*k-x);
                break;
            }
            k++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
