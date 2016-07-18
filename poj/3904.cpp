/*
Mobius反演
*/
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
#define SIZE 500005
int prime[SIZE],prinum;
bool notprime[SIZE];
int mu[SIZE];
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
}
int n;
int num[10005];
int cnt[10005];
long long cal(long long x)
{
    if(x<4)return 0;
    return x*(x-1)/2*(x-2)/3*(x-3)/4;
}
int main()
{
    init();
    while(scanf("%d",&n)!=EOF)
    {
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;i++)
        {
            scanf("%d",&num[i]);
            for(int j=1;j*j<=num[i];j++)
            {
                if(num[i]%j==0)
                {
                    cnt[j]++;
                    if(j*j==num[i])
                        ;
                    else
                        cnt[num[i]/j]++;
                }
            }
        }
        long long ans=0;
        int i=1;
        for(int j=i;j<=10000;j+=i)
        {
            ans+=cal(cnt[j])*mu[j/i];
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
