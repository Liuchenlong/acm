#include<stdio.h>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
const int SIZE=100005;
//素数,欧拉函数
bool notprime[SIZE];
int prime[SIZE],prinum;
void getprime()//prime
{
    notprime[0]=1;
    notprime[1]=1;
    for(int i=2; i<SIZE; i++)
    {
        if(!notprime[i])
        {
            prime[prinum++]=i;
        }
        for(int j=0; j<prinum; j++)
        {
            if(i*prime[j]>=SIZE)
                break;
            notprime[i*prime[j]]=1;
            if(i%prime[j]==0)
                break;
        }
    }
}
int getphi(int x,int p)//get phi(x)
{
    if(x==0)
        return 0;
    int res=1,t=x;
    for(int i=0; i<prinum; i++)
    {
        if(prime[i]*prime[i]>t)
            break;
        if(t%prime[i]==0)
        {
            res*=(prime[i]-1);
            t/=prime[i];
            while(t%prime[i]==0)
            {
                res*=prime[i];
                t/=prime[i];
            }
        }
    }
    if(t>1)
    {
        res*=(t-1);
    }
    return res%p;
}
int qpow(int x,int k,int mod)
{
    x%=mod;
    int ans=1;
    while(k)
    {
        if(k&1)ans=ans*x%mod;
        k>>=1;
        x=x*x%mod;
    }
    return ans;
}
int main()
{
    getprime();
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,p;
        scanf("%d%d",&n,&p);
        int ans=0;
        for(int i=1;i*i<=n;i++)
        {
            if(n%i==0)
            {
               ans=(ans+getphi(n/i,p)*qpow(n,i-1,p)%p)%p;
               if(i*i==n);
               else ans=(ans+getphi(i,p)*qpow(n,n/i-1,p)%p)%p;
            }
        }
        printf("%d\n",ans%p);
    }
    return 0;
}
