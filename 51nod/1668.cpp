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
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
#define LL long long
#define pii pair<int,int>
int siz=5;
long long mod=1e9+7;
struct matrix
{
    long long num[10][10];
    matrix()
    {
        memset(num,0,sizeof(num));
    }
}E;
matrix mult(matrix a,matrix b)
{
    matrix c;
    for(int i=0;i<siz;i++)
    {
        for(int j=0;j<siz;j++)
        {
            for(int k=0;k<siz;k++)
                c.num[i][j]+=a.num[i][k]*b.num[k][j]%mod;
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
        if(k&1)
            ans=mult(ans,X);
        k>>=1;
        X=mult(X,X);
    }
    return ans;
}
long long qpow(long long x,long long k)
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
matrix A;
matrix X;
int main()
{
    for(int i=0;i<siz;i++)E.num[i][i]=1;
    A.num[0][1]=A.num[0][3]=1;
    A.num[1][2]=1;
    A.num[2][0]=A.num[2][2]=1;
    A.num[3][1]=A.num[3][3]=1;
    A.num[4][0]=1;
    A.num[4][4]=2;
    X.num[0][0]=X.num[1][0]=X.num[2][0]=X.num[3][0]=1;
    long long n;
    scanf("%I64d",&n);
    if(n==1)puts("2");
    else if(n==2)puts("4");
    else
    {
        long long ans=qpow(2,n);
        matrix as=mult(qpow(A,n-2),X);
        ans-=as.num[4][0];
        printf("%I64d\n",(ans%mod+mod)%mod);
    }
    return 0;
}
