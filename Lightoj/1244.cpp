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
const int mod=10007;
int siz=3;
struct matrix
{
    int num[3][3];
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
            {
                c.num[i][j]+=a.num[i][k]*b.num[k][j]%mod;
            }
            c.num[i][j]%=mod;
        }
    }
    return c;
}
matrix qpow(matrix x,int k)
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
    for(int i=0;i<siz;i++)E.num[i][i]=1;
    matrix A;
    A.num[0][1]=1;
    A.num[1][2]=1;
    A.num[2][0]=1;
    A.num[2][2]=2;
    matrix X;
    X.num[0][0]=1;
    X.num[1][0]=2;
    X.num[2][0]=5;
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        int n;
        scanf("%d",&n);
        int ans;
        matrix res=mult(qpow(A,n-1),X);
        printf("Case %d: %d\n",cas,res.num[0][0]);
    }
    return 0;
}
