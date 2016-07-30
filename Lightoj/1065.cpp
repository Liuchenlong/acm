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
#define eps 1e-12
const int siz=2;
long long mod;
int ten[5]={1,10,100,1000,10000};
struct matrix
{
    long long num[10][10];
    matrix()
    {
        memset(num,0,sizeof(num));
    }
    void output()
    {
        for(int i=0; i<siz; i++)
        {
            for(int j=0; j<siz; j++)
                printf("%lld ",num[i][j]);
            printf("\n");
        }
    }
} E;
matrix mult(matrix a,matrix b)
{
    matrix c;
    for(int i=0; i<siz; i++)
    {
        for(int j=0; j<siz; j++)
        {
            for(int k=0; k<siz; k++)
            {
                c.num[i][j]+=a.num[i][k]*b.num[k][j]%mod;
            }
            c.num[i][j]%=mod;
        }
    }
    return c;
}
matrix qpow(matrix x,long long k)
{
    matrix ans=E;
    while(k)
    {
        if(k&1)
            ans=mult(ans,x);
        k>>=1;
        x=mult(x,x);
    }
    return ans;
}
int main()
{
    for(int i=0; i<siz; i++)E.num[i][i]=1;
    int T;
    scanf("%d",&T);
    matrix A;
    A.num[0][1]=1;
    A.num[1][0]=1;
    A.num[1][1]=1;
    for(int cas=1; cas<=T; cas++)
    {
        long long a,b,n,m;
        scanf("%lld%lld%lld%lld",&a,&b,&n,&m);
        mod=ten[m];
        matrix X;
        X.num[0][0]=a;
        X.num[1][0]=b;
        X=mult(qpow(A,n),X);
        printf("Case %d: %lld\n",cas,X.num[0][0]);
    }
    return 0;
}
