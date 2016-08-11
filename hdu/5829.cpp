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

const long long MOD=998244353;
const int g=3;
long long qp[30];
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

///雷德算法，2^M=len，将第i位的数与“i的二进制反转之后的位”的数交换
void rader(long long F[],int len)
{
    int j=len/2;///模拟二进制反转进位的的位置
    for(int i=1;i<len-1;i++)
    {
        if(i<j)swap(F[i],F[j]);///该出手时就出手
        int k=len/2;
        while(j>=k)
        {
            j-=k;
            k>>=1;
        }
        if(j<k)j+=k;
    }
}
void NTT(long long F[],int len,int t)
{
    int id=0;
    rader(F,len);
    for(int h=2;h<=len;h<<=1)
    {
        id++;
        for(int j=0;j<len;j+=h)
        {
            long long E=1;///原根次幂
            for(int k=j;k<j+h/2;k++)
            {
                long long u=F[k];///蝶型操作
                long long v=(E*F[k+h/2])%MOD;
                F[k]=(u+v)%MOD;///前半部分
                F[k+h/2]=((u-v)%MOD+MOD)%MOD;///后半部分
                E=(E*qp[id])%MOD;
            }
        }
    }
    //p(F);
    if(t==-1)///插值
    {
        for(int i=1;i<len/2;i++)swap(F[i],F[len-i]);///i+lne-i=i;
        long long inv=qpow(len,MOD-2,MOD);///逆元
        for(int i=0;i<len;i++)F[i]=(F[i]%MOD*inv)%MOD;
    }
    //p(F);
}

long long fac[100005];
long long inv[100005];
long long ifac[100005];
long long two[100005];
void init()
{
    for(int i=0;i<21;i++)
    {
        int t=1<<i;
        if((MOD-1)%t==0)
        {
            qp[i]=qpow(g,(MOD-1)/t,MOD);
        }
        else
            break;
    }
    fac[0]=inv[0]=ifac[0]=1;
    fac[1]=inv[1]=ifac[1]=1;
    two[0]=1;
    two[1]=2;
    for(int i=2;i<100005;i++)
    {
        two[i]=two[i-1]*2%MOD;
        fac[i]=fac[i-1]*i%MOD;
        inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;
        ifac[i]=ifac[i-1]*inv[i]%MOD;
    }
}
long long a[400000];
long long b[400000];
long long num[100005];
long long ans[100005];
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%I64d",&num[i]);
        sort(num+1,num+n+1);
        reverse(num+1,num+n+1);
        int len=1;
        while(len<n+1)len<<=1;
        len<<=1;
        a[0]=0;
        b[0]=0;
        for(int i=1;i<len;i++)
        {
            if(i<=n)
            {
                a[i]=fac[i-1]*num[i]%MOD*two[n-i]%MOD;
                b[i]=ifac[n-i];
            }
            else
            {
                a[i]=0;
                b[i]=0;
            }
        }
        NTT(a,len,1);
        NTT(b,len,1);
        for(int i=0;i<len;i++)
            a[i]=a[i]*b[i]%MOD;
        NTT(a,len,-1);
        for(int i=1;i<=n;i++)
        {
            ans[i]=a[i+n]*ifac[i-1]%MOD;
            ans[i]=(ans[i]+ans[i-1])%MOD;
        }
        for(int i=1;i<=n;i++)
        {
            printf("%I64d ",ans[i]);
        }
        printf("\n");
    }
    return 0;
}
