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
int qpow(int x,int k,int mod)
{
    x%=mod;
    int ans=1;
    while(k)
    {
        if(k&1)
            ans=ans*x%mod;
        k>>=1;
        x=x*x%mod;
    }
    return ans;
}
int d,x,y;
int exgcd(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    else
    {
        int ret=exgcd(b,a%b,x,y);
        int temp=x;
        x=y;
        y=temp-a/b*y;
        return ret;
    }
}
int inv(int n,int mod)
{
    d=exgcd(n,mod,x,y);
    x=(x%mod+mod)%mod;
    if(d==1)
        return x;
    return -1;//无逆元
}
//中国剩余定理(m[i]两两互素)
//n个方程:x=a[i](mod m[i]) (0<=i<n)
//返回x
int china(int n,int a[],int m[])
{
    int M=1,d,y,x;
    int ans=0;
    for(int i=0; i<n; i++)
        M*=m[i];
    for(int i=0; i<n; i++)
    {
        int w=M/m[i];
        d=exgcd(m[i],w,x,y);
        y=(y%(m[i]/d)+m[i]/d)%(m[i]/d);
        ans=(ans+y*w%M*a[i]%M)%M;
    }
    return ans;
}
int N;
int a[10],m[10],p[10];
const int maxn=100005;
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

int getp(int x,int p)
{
    int ans=0;
    while(x)
    {
        ans+=x/p;
        x/=p;
    }
    return ans;
}
int res[10005];
void init(int p,int pk)
{
    res[0]=1;
    for(int i=1;i<pk;i++)
    {
        if(i%p==0)res[i]=res[i-1];
        else res[i]=res[i-1]*i%pk;
    }
}
int f(int n,int p)
{
    return qpow(res[p-1],n/p,p)*res[n%p]%p;
}
int cal(int n,int p,int pk)
{
    if(n<=1)return 1;
    return f(n,pk)*cal(n/p,p,pk)%pk;
}

int C(int n,int m,int p,int pk)
{
    int nump=getp(n,p)-getp(m,p)-getp(n-m,p);
    int numpk=1;
    int tmp=p;
    for(int i=1;;i++)
    {
        if(tmp==pk)break;
        tmp*=p;
        numpk++;
    }
    if(nump>=numpk)return 0;
    int p_n=1;
    for(int i=0;i<nump;i++)p_n*=p;
    int pk_n=pk/p_n;
    init(p,pk_n);
    int fac_n=cal(n,p,pk_n);
    int fac_m=cal(m,p,pk_n);
    int fac_nm=cal(n-m,p,pk_n);
    int ans=fac_n;
    ans=ans*inv(fac_m,pk_n)%pk_n*inv(fac_nm,pk_n)%pk_n;
    ans=ans*p_n%pk;
    return ans;
}

int main()
{
    getprime();
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        int n,k,l,M;
        scanf("%d%d%d%d",&n,&k,&l,&M);
        if(M==0)
        {
            printf("Case %d: %d\n",cas,qpow(k,l,n)+1);
            continue;
        }
        int ans=1;
        if(k%2==0)
        {
            ans=ans*(k/2)%n*qpow(k,l-1,n)%n*qpow(k-1,M,n)%n;
        }
        else
        {
            ans=ans*qpow(k,l,n)%n*(((k-1)/2)%n)%n*qpow(k-1,M-1,n)%n;
        }
        N=0;
        int t=n;
        for(int i=0;i<prinum;i++)
        {
            if(prime[i]*prime[i]>t)break;
            if(t%prime[i]==0)
            {
                p[N]=prime[i];
                m[N]=1;
                while(t%prime[i]==0)
                {
                    t/=prime[i];
                    m[N]*=prime[i];
                }
                a[N]=C(l,M,p[N],m[N]);
                N++;
            }
        }
        if(t!=1)
        {
            p[N]=t;
            m[N]=t;
            a[N]=C(l,M,p[N],m[N]);
            N++;
        }
        ans=ans*china(N,a,m)%n;
        printf("Case %d: %d\n",cas,ans+1);
    }
    return 0;
}
