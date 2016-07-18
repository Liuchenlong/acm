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
const int mod=10007;
#define SIZE 10000005
int prime[SIZE],prinum;
bool notprime[SIZE];
int mu[SIZE];
long long f[SIZE];
void init()
{
    mu[1]=1;
    for(int i=2; i<SIZE; i++)
    {
        if(!notprime[i])
        {
            prime[prinum++]=i;
            mu[i]=-1;
        }
        for(int j=0; j<prinum&&i*prime[j]<SIZE; j++)
        {
            notprime[i*prime[j]]=1;
            if(i%prime[j])mu[i*prime[j]]=-mu[i];
            else
            {
                mu[i*prime[j]]=0;
                break;
            }
        }
    }
    for(int i=2;i<SIZE;i++)
    {
        if(!notprime[i])
        {
            for(int j=i;j<SIZE;j+=i)
                f[j]+=mu[j/i];
        }
    }
    for(int i=2;i<SIZE;i++)
    {
        f[i]+=f[i-1];
    }
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        long long ans=0;
        int j;
        for(int i=1;i<=min(a,b);i=j+1)
        {
            j=min(a/(a/i),b/(b/i));
            ans+=(f[j]-f[i-1])*(a/i)*(b/i);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
