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
#define SIZE 300005
bool notprime[SIZE];
int prime[SIZE],prinum;
const long long mod=1e9+7;
int mu[SIZE];
int sum[SIZE];
long long fac[SIZE];
long long inv[SIZE];
long long ifac[SIZE];
void init()
{
    fac[0]=1;
    inv[0]=1;
    ifac[0]=1;
    fac[1]=1;
    inv[1]=1;
    ifac[1]=1;
    for(int i=2; i<SIZE; i++)
    {
        fac[i]=fac[i-1]*i%mod;
        inv[i]=(mod-mod/i)*inv[mod%i]%mod;
        ifac[i]=ifac[i-1]*inv[i]%mod;
    }
}
long long C(int n,int m)
{
    return fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
void getmu()
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
int N,M,K;
int cnt[SIZE];
int a[SIZE];
long long F[SIZE];
long long qpow(long long x,long long k,long long mod)
{
    long long ans=1;
    while(k)
    {
        if(k&1)
            ans=ans*x%mod;
        k>>=1;
        x=x*x%mod;
    }
    return ans;
}
int factor[20][2],facnum;
void getfac(int x)
{
    facnum=0;
    memset(factor,0,sizeof(factor));
    for(int i=0;i<prinum;i++)
    {
        if(prime[i]*prime[i]>x)
            break;
        if(x%prime[i]==0)
        {
            factor[facnum][0]=prime[i];
            while(x%prime[i]==0)
            {
                x/=prime[i];
                factor[facnum][1]++;
            }
            facnum++;
        }
    }
    if(x!=1)
    {
        factor[facnum][0]=x;
        factor[facnum][1]=1;
        facnum++;
    }
}
void dfs(int pos,int val)
{
    if(pos==facnum)
    {
        cnt[val]++;
        return ;
    }
    for(int i=0;i<=factor[pos][1];i++)
    {
        dfs(pos+1,val);
        val*=factor[pos][0];
    }
}
int main()
{
    getmu();
    init();
    while(scanf("%d%d%d",&N,&M,&K)!=EOF)
    {
        memset(cnt,0,sizeof(cnt));
        memset(F,0,sizeof(F));
        for(int i=0; i<N; i++)
        {
            scanf("%d",&a[i]);
            getfac(a[i]);
            dfs(0,1);
        }
        for(int i=1; i<=M; i++)
        {
            if(N-cnt[i]>K)
                F[i]=0;
            else
            {
                F[i]=C(cnt[i],K-(N-cnt[i]))*qpow(M/i-1,K-(N-cnt[i]),mod)%mod*qpow(M/i,N-cnt[i],mod)%mod;
            }
        }
        for(int i=1; i<=M; i++)
        {
            if(i-1)printf(" ");
            long long sum=0;
            for(int j=i; j<=M; j+=i)
                sum+=F[j]*mu[j/i];
            printf("%I64d",(sum%mod+mod)%mod);
        }
        printf("\n");
    }
    return 0;
}
