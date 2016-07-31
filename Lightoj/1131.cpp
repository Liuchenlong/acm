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
const int siz=6;
long long mod;
//int ten[5]={1,10,100,1000,10000};
struct matrix
{
    unsigned long long num[10][10];
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
//    freopen("1.txt","r",stdin);
//    freopen("2.out","w",stdout);
    for(int i=0; i<siz; i++)E.num[i][i]=1;
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        matrix A,X;
        scanf("%lld%lld%lld",&A.num[2][2],&A.num[2][1],&A.num[2][3]);
        scanf("%lld%lld%lld",&A.num[5][5],&A.num[5][4],&A.num[5][0]);
        A.num[0][1]=1;
        A.num[1][2]=1;
        A.num[3][4]=1;
        A.num[4][5]=1;
        for(int i=0;i<6;i++)
            scanf("%lld",&X.num[i][0]);
        scanf("%lld",&mod);
        printf("Case %d:\n",cas);
        int q;
        scanf("%d",&q);
        for(int i=0;i<q;i++)
        {
            long long n;
            scanf("%lld",&n);
            matrix ans=mult(qpow(A,n),X);
            printf("%lld %lld\n",ans.num[0][0],ans.num[3][0]);
        }
    }
    return 0;
}
