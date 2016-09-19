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
const long long mod=9973;
int n,m,k;
struct matrix
{
    long long num[14][14];
    matrix()
    {
        memset(num,0,sizeof(num));
    }
}E;
matrix mult(matrix a,matrix b)
{
    matrix c;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
                c.num[i][j]+=a.num[i][k]*b.num[k][j];
            c.num[i][j]%=mod;
        }
    }
    return c;
}
matrix qpow(matrix X,long long k)
{
    matrix ans=E;
    while(k)
    {
        if(k&1)ans=mult(ans,X);
        k>>=1;
        X=mult(X,X);
    }
    return ans;
}
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
            if(i*prime[j]>SIZE)
                break;
            notprime[i*prime[j]]=1;
            if(i%prime[j]==0)
                break;
        }
    }
}
long long getphi(long long x)//get phi(x)
{
    if(x==0)
        return 0;
    long long res=1,t=x;
    for(int i=0; i<prinum; i++)
    {
        if(prime[i]*prime[i]>x)
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
    return res;
}
long long cal(matrix X,int k)
{
    matrix ans=qpow(X,k);
    long long sum=0;
    for(int i=0;i<n;i++)sum+=ans.num[i][i];
    return sum%mod;
}
long long qpow(long long x,long long k,long long mod)
{
    long long ans=1;
    while(k)
    {
        if(k&1)ans=ans*x%mod;
        k>>=1;
        x=x*x%mod;
    }
    return ans;
}
long long inv(long long x)
{
    return qpow(x,mod-2,mod);
}
int main()
{
    getprime();
    for(int i=0;i<12;i++)E.num[i][i]=1;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        matrix A;
        scanf("%d%d%d",&m,&n,&k);
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)A.num[i][j]=1;
        for(int i=0;i<k;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            a--;b--;
            A.num[a][b]=0;
            A.num[b][a]=0;
        }
        long long ans=0;
        for(int i=1;i*i<=m;i++)
        {
            if(m%i==0)
            {
                ans+=cal(A,i)*getphi(m/i);
                if(i*i==m);
                else ans+=cal(A,m/i)*getphi(i);
            }
        }
        printf("%I64d\n",ans%mod*inv(m)%mod);
    }
    return 0;
}
