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
#define SIZE 50005
bool notprime[SIZE];
int prime[SIZE],prinum;
int mu[SIZE];
int sum[SIZE];
void getmu()
{
    mu[1]=1;
    for(int i=2;i<SIZE;i++)
    {
        if(!notprime[i])
        {
            prime[prinum++]=i;
            mu[i]=-1;
        }
        for(int j=0;j<prinum&&i*prime[j]<SIZE;j++)
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
    for(int i=1;i<SIZE;i++)
        sum[i]=sum[i-1]+mu[i];
}
int k;
long long cal(int a,int b)
{
    long long ans=0;
    a/=k;
    b/=k;
    if(a>b)
        swap(a,b);
    for(int i=1;i<=a;)
    {
        int j=min(a/(a/i),b/(b/i));
        ans+=(long long)(sum[j]-sum[i-1])*(a/i)*(b/i);
        i=j+1;
    }
    return ans;
}
int main()
{
    getmu();
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int a,b,c,d;
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
        printf("%lld\n",cal(b,d)-cal(a-1,d)-cal(b,c-1)+cal(a-1,c-1));
    }
    return 0;
}
