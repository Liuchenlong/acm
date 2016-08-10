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
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define SIZE 10005
bool isprime[SIZE];
int prime[SIZE],prinum;
int num[SIZE];
void getprime()
{
    for(int i=2; i<SIZE; i++)
    {
        if(isprime[i])
            continue;
        prime[prinum++]=i;
        for(int j=2*i; j<SIZE; j+=i)
            isprime[j]=1;
    }
}
void cal(int n,int sig)
{
    for(int i=0; i<prinum; i++)
    {
        if(prime[i]>n)
            break;
        int t=0;
        int tnum=prime[i];
        while(tnum<=n)
        {
            t+=n/tnum;
            tnum*=prime[i];
        }
        num[prime[i]]+=sig*t;
    }
}
void solve(int m,int n,int sig)
{
    cal(m,sig);
    cal(n,-1*sig);
    cal(m-n,-1*sig);
}
double qpow(double x,int k)
{
    if(k==0)
        return 1.0;
    if(k%2==0)
    {
        double t=qpow(x,k/2);
        return t*t;
    }
    else
    {
        double t=qpow(x,(k-1)/2);
        return t*t*x;
    }
}
int main()
{

    getprime();
    int fzm,fzn,fmm,fmn;
    while(scanf("%d%d%d%d",&fzm,&fzn,&fmm,&fmn)!=EOF)
    {
        memset(num,0,sizeof(num));
        solve(fzm,fzn,1);
        solve(fmm,fmn,-1);
        double ans=1.0;
        for(int i=0; i<prinum; i++)
        {
            if(num[prime[i]]<0)
            {
                ans/=qpow((double)prime[i],-num[prime[i]]);
            }
            else if(num[prime[i]]>0)
            {
                ans*=qpow((double)prime[i],num[prime[i]]);
            }
        }
        printf("%.5f\n",ans);
    }
    return 0;
}
