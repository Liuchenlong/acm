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

const long long MOD=(479<<21)+1; 
const int MOD=998244353;
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
void initqp()
{
    for(int i=0;i<21;i++)  
    {  
        int t=1<<i;  
        qp[i]=qpow(g,(MOD-1)/t,MOD);  
    }  
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
