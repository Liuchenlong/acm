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
int siz;
//long long mod;
struct matrix
{
    unsigned int num[55][55];
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
                c.num[i][j]+=a.num[i][k]*b.num[k][j];//%mod;
            }
            //c.num[i][j]%=mod;
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
unsigned int C[55][55];
void init()
{
    C[0][0]=1;
    for(int i=1;i<=50;i++)
    {
        C[i][0]=1;
        for(int j=1;j<=i;j++)
            C[i][j]=C[i-1][j]+C[i-1][j-1];
    }
}
int main()
{
    init();
    for(int i=0;i<55;i++)E.num[i][i]=1;
//    freopen("1.txt","r",stdin);
//    freopen("2.out","w",stdout);
    for(int i=0; i<siz; i++)E.num[i][i]=1;
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        long long n;
        int k;
        scanf("%lld%d",&n,&k);
        siz=k+2;
        matrix A;
        for(int i=0;i<=k;i++)
        {
            for(int j=0;j<=i;j++)
            {
                A.num[i][j]=C[i][j];
            }
        }
        A.num[k+1][k+1]=1;
        A.num[k+1][k]=1;
        matrix X;
        for(int i=0;i<=k;i++)
            X.num[i][0]=1;
        matrix ans=mult(qpow(A,n),X);
        printf("Case %d: %u\n",cas,ans.num[k+1][0]);
    }
    return 0;
}
