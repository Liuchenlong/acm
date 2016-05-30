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
long long c[22][22];
long long three[22];
void init()
{
    c[0][0]=1;
    three[0]=1;
    for(int i=1; i<=20; i++)
    {
        c[i][0]=1;
        three[i]=three[i-1]*3LL;
        for(int j=1; j<=i; j++)
        {
            c[i][j]=c[i-1][j-1]+c[i-1][j];
        }
    }
}
long long mod;
long long d,x,y;
long long exgcd(long long a,long long b,long long &x,long long &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    else
    {
        long long ret=exgcd(b,a%b,x,y);
        long long tmp=x;
        x=y;
        y=tmp-a/b*y;
        return ret;
    }
}
long long inv(long long n,long long mod)
{
    exgcd(n,mod,x,y);
    x=(x%mod+mod)%mod;
    return x;
}
long long qpow(long long x,long long k,long long mod)
{
    long long ans=1;
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
long long cal(long long x)
{
    long long ans=0;
    while(x)
    {
        ans+=x/3;
        x/=3;
    }
    return ans;
}
struct polynomial
{
    int len;
    long long coe[20];
    polynomial()
    {
        len = 0;
        memset(coe,0,sizeof(coe));
    }
};
polynomial get_polynomial(long long n,int p,int q)
{
    if(n<2*p)
    {
        polynomial ans;
        ans.coe[0]=ans.len=1;
        for(long long i=1; i<=n; i++)
        {
            if(i%p==0)continue;
            long long x=i%mod;
            for(int j=ans.len; j>0; j--)
                ans.coe[j]=ans.coe[j-1]+ans.coe[j]*x;
            ans.coe[0]=ans.coe[0]*x%mod;
            if(ans.len<q)
                ans.len++;
            for(int j=0; j<ans.len; j++)
                if(ans.coe[j]>=mod)
                    ans.coe[j]%=mod;
        }
        return ans;
    }
    else
    {
        long long mid=(n+1)/(p*2)*p;
        polynomial ans1=get_polynomial(mid-1,p,q);
        polynomial ans,ans2;
        ans2.len=ans1.len;
        long long pw[22];
        pw[0]=1;
        long long md=mid%mod;
        for(int i=1; i<ans2.len; i++)
            pw[i]=pw[i-1]*md%mod;
        for(int i=0; i<ans2.len; i++)
        {
            for(int j=0; j<=i; j++)
                ans2.coe[j]=ans2.coe[j]+c[i][j]*ans1.coe[i]%mod*pw[i-j];
        }
        for(int j=0; j<ans2.len; j++)
            if(ans2.coe[j]>=mod)
                ans2.coe[j]%=mod;
        for(int i=0; i<ans1.len; i++)
            for(int j=0; j<ans1.len&&i+j<q; j++)
                ans.coe[i+j]=ans.coe[i+j]+ans1.coe[i]*ans2.coe[j];
        ans.len=min(q,ans1.len*2);

        while(ans.len&&ans.coe[ans.len-1]==0)ans.len--;
        if(ans.len==0)
            ans.len++;
        for(int i=0; i<ans.len; i++)ans.coe[i]%=mod;
        for(long long i=mid*2+1; i<=n; i++)
        {
            if(i%p==0)
                continue;
            long long x=i%mod;
            for(int j=ans.len; j>0; j--)
                ans.coe[j]=ans.coe[j-1]+ans.coe[j]*x%mod;
            ans.coe[0]=ans.coe[0]*x%mod;
            if(ans.len<q)
                ans.len++;
            for(int j=0; j<ans.len; j++)
                if(ans.coe[j]>=mod)
                    ans.coe[j]%=mod;
        }

        return ans;
    }
}
long long fac(long long x,int p,int q)
{
    long long ans=1;
    while(x)
    {
        ans=ans*get_polynomial(x,p,q).coe[0]%mod;
        x/=p;
    }
    return ans;
}
long long C(long long n,long long m,long long pk)
{
    if(n==m||m==0)
        return 1;
    if(m==1)
        return n%three[pk];
    long long pn=0;
    pn+=cal(n);
    pn-=cal(m);
    pn-=cal(n-m);
    if(pn>=pk)
        return 0;
    mod=three[pk];
    long long ans1=fac(n,3,pk);
    long long ans_1=fac(m,3,pk);
    long long ans_2=fac(n-m,3,pk);
    long long ans=1;
    ans=ans*ans1%mod;
    ans=ans*inv(ans_1,mod)%mod;
    ans=ans*inv(ans_2,mod)%mod;
    return ans*three[pn]%mod;
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while(T--)
    {
        long long n,m;
        int k;
        scanf("%I64d%I64d%d",&n,&m,&k);
        printf("%I64d\n",C(n,m,k));
    }
    return 0;
}


