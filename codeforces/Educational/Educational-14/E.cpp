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
#include<bitset>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
const long long mod=1e9+7;
int n;
struct matrix
{
    long long num[105][105];
    matrix()
    {
        memset(num,0,sizeof(num));
    }
} E;
matrix mult(matrix a,matrix b)
{
    matrix c;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            for(int k=0; k<n; k++)
            {
                c.num[i][j]+=a.num[i][k]*b.num[k][j]%mod;
            }
            c.num[i][j]%=mod;
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
int cal(long long x)
{
    int ans=0;
    while(x)
    {
        ans+=x%2;
        x/=2;
    }
    return ans;
}
long long k;
long long a[105];
int main()
{
    scanf("%d%I64d",&n,&k);
    for(int i=0; i<n; i++)
        E.num[i][i]=1;
    for(int i=0; i<n; i++)
        scanf("%I64d",&a[i]);
    matrix A;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            if(cal(a[i]^a[j])%3==0)
            {
                A.num[i][j]=1;
            }
        }
    A=qpow(A,k-1);
    matrix X;
    for(int i=0; i<n; i++)
        X.num[0][i]=1;
    X=mult(X,A);
    long long ans=0;
    for(int i=0; i<n; i++)
        ans=(ans+X.num[0][i])%mod;
    printf("%I64d\n",ans);
    return 0;
}
