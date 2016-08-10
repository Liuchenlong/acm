#include<stdio.h>
#include<cmath>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<set>
#include<vector>
#include<map>
using namespace std;
#define eps 1e-9
const double pi=acos(-1.0);
const int maxn=3000;
bool notprime[maxn];
int prime[maxn],prinum;
void getprime()
{
    for(int i=2;i<maxn;i++)
    {
        if(!notprime[i])
            prime[prinum++]=i;
        for(int j=0;j<prinum&&i*prime[j]<maxn;j++)
        {
            notprime[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
}
int fac[10][2];
int facnum;
void getfac(int x)
{
    for(int i=0;i<prinum;i++)
    {
        if(x%prime[i]==0)
        {
            fac[facnum][0]=prime[i];
            while(x%prime[i]==0)
            {
                fac[facnum][1]++;
                x/=prime[i];
            }
            facnum++;
        }
    }
    if(x!=1)
    {
        fac[facnum][0]=x;
        fac[facnum][1]=1;
        facnum++;
    }
}
const int mod=29;
int qpow(int x,int k)
{
    int ans=1;
    while(k)
    {
        if(k&1)
        {
            ans=ans*x%mod;
        }
        k>>=1;
        x=x*x%mod;
    }
    return ans;
}
int inv(int x)
{
    return qpow(x,mod-2);
}
int main()
{
    getprime();
    getfac(2004);
    int x;
    while(scanf("%d",&x),x)
    {
        int ans=1;
        for(int i=0;i<facnum;i++)
        {
            int k=(fac[i][1]*x+1)%(mod-1);
            ans=ans*(qpow(fac[i][0],k)-1)*inv(fac[i][0]-1)%mod;
        }
        printf("%d\n",(ans%mod+mod)%mod);
    }
    return 0;
}
