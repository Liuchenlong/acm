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
#define SIZE 10005
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
int cnt[SIZE];
int main()
{
    init();
    while(scanf("%d",&n)!=EOF)
    {
        memset(cnt,0,sizeof(cnt));
        for(int i=0; i<n; i++)
        {
            int x;
            scanf("%d",&x);
            for(int j=1; j*j<=x; j++)
            {
                if(x%j==0)
                {
                    cnt[j]++;
                    if(j*j==x)
                        ;
                    else
                        cnt[x/j]++;
                }
            }
        }
        int ans=0;
        for(int i=1; i<=10000; i++)
        {
            int f=0;
            for(int j=i; j<=10000; j+=i)
            {
                f+=mu[j/i]*cnt[j]*cnt[j]%mod;
            }
            ans=ans+f*i%mod*(i-1)%mod;
            ans=(ans%mod+mod)%mod;
        }
        printf("%d\n",ans);
    }
    return 0;
}
