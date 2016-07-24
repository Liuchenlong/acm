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
#define SIZE 10000005
const int mod=1e9+7;
bool isprime[SIZE];
int prime[SIZE/10],prinum;
int phi[SIZE];
int sump[SIZE];
void getboth()
{
    isprime[0]=1;
    isprime[1]=1;
    phi[1]=1;
    for(int i=2; i<SIZE; i++)
    {
        if(!isprime[i])
        {
            prime[prinum++]=i;
            phi[i]=i-1;
        }
        for(int j=0; j<prinum; j++)
        {
            if(i*prime[j]>SIZE)break;
            isprime[i*prime[j]]=1;
            if(i%prime[j]==0)
            {
                phi[i*prime[j]]=phi[i]*prime[j];
                break;
            }
            else
            {
                phi[i*prime[j]]=phi[i]*(prime[j]-1);
            }
        }
    }
    for(int i=1; i<SIZE; i++)
    {
        sump[i]=sump[i-1]+phi[i];
        while(sump[i]>=mod)sump[i]-=mod;
    }
}
int fac[20];
int fnum;
long long cal(int pos,int n,int m)
{
    if(m==0)return 0;
    if(n==1)return sump[m];
    return (cal(pos+1,n/fac[pos],m)*phi[fac[pos]]%mod+cal(pos,n,m/fac[pos]))%mod;
}
long long qpow(long long x,long long k,long long mod)
{
    long long ans=1;
    bool flag=0;
    while(k)
    {
        if(k&1)
        {
            ans=ans*x;
            if(ans>=mod)
            {
                flag=1;
                ans%=mod;
            }
        }
        k>>=1;
        x=x*x;
        if(x>=mod)
        {
            flag=1;
            x%=mod;
        }
    }
    if(flag)
        ans+=mod;
    return ans;
}
long long solve(long long k,long long p,bool flag)
{
    if(flag==0)
    {
        if(p==1)return 0;
        return qpow(k,solve(k,phi[p],1),p)%p;
    }
    else
    {
        if(p==1)return 1;
        return qpow(k,solve(k,phi[p],1),p);
    }
}
int main()
{
    getboth();
    int n,m,p;
    while(scanf("%d%d%d",&n,&m,&p)!=EOF)
    {
        fnum=0;
        int t=n;
        for(int i=0; i<prinum; i++)
        {
            if(prime[i]*prime[i]>t)
                break;
            if(t%prime[i]==0)
            {
                fac[fnum++]=prime[i];
                t/=prime[i];
            }
        }
        if(t!=1)
        {
            fac[fnum++]=t;
        }
        long long k=cal(0,n,m)%mod;
        long long ans=solve(k,p,0);
        printf("%I64d\n",ans);
    }
    return 0;
}
