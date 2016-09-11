#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
using namespace std;
#define eps 1e-8

const long long mod=1e9+7;
struct matrix
{
    long long num[2][2];
    matrix()
    {
        memset(num,0,sizeof(num));
    }
}A,E,X;
matrix mult(matrix a,matrix b)
{
    matrix c;
    for(int i=0;i<2;i++)for(int j=0;j<2;j++)
    {
        for(int k=0;k<2;k++)
        {
            c.num[i][j]+=a.num[i][k]*b.num[k][j]%mod;
        }
        c.num[i][j]%=mod;
    }
    return c;
}
matrix qpow(matrix x,int k)
{
    matrix ans=E;
    while(k)
    {
        if(k&1)ans=mult(ans,x);
        k>>=1;
        x=mult(x,x);
    }
    return ans;
}
long long f(int x)
{
    matrix ans=mult(qpow(A,x-1),X);
    return ans.num[0][0];
}
long long qpow(long long x,long long k)
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
long long inv(int x)
{
    return qpow(x,mod-2);
}
const int maxn=100005;
bool notprime[maxn];
int prime[maxn],prinum;
void getprime()
{
    for(int i=2;i<maxn;i++)
    {
        if(!notprime[i])
            prime[prinum++]=i;
        for(int j=0;j<prinum&&prime[j]*i<maxn;j++)
        {
            notprime[j*prime[i]]=true;
            if(i%prime[j]==0)break;
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
int main()
{
    getprime();
    for(int i=0;i<2;i++)E.num[i][i]=1;
    A.num[0][1]=1;
    A.num[1][0]=1;
    A.num[1][1]=1;
    X.num[0][0]=1;
    X.num[1][0]=3;
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==1)
        {
            printf("2\n");
            continue;
        }
        long long ans=0;
        for(int i=1;i*i<=n;i++)
        {
            if(n%i==0)
            {
                ans+=f(i)*getphi(n/i)%mod;
                if(i*i==n);
                else ans+=f(n/i)*getphi(i);
                ans%=mod;
            }
        }
        ans=ans*inv(n)%mod;
        printf("%I64d\n",ans);
    }
    return 0;
}
