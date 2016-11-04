#include <cstdio>
#include <cstring>
#include <map>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
#define eps 1e-8
int siz=4;
long long mod=10007;
struct matrix
{
    long long num[10][10];
    matrix()
    {
        memset(num,0,sizeof(num));
    }
    void output()
    {
        for(int i=0;i<siz;i++)
        {
            for(int j=0;j<siz;j++)
                printf("%I64d ",num[i][j]);
            puts("");
        }
    }
}E,A,X;
matrix mult(matrix a,matrix b)
{
    matrix c;
    for(int i=0;i<siz;i++)
    {
        for(int j=0;j<siz;j++)
        {
            for(int k=0;k<siz;k++)
            {
                c.num[i][j]+=a.num[i][k]*b.num[k][j];
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
    for(int i=0;i<4;i++)E.num[i][i]=1;
    A.num[0][0]=2;
    A.num[1][0]=1;A.num[1][2]=1;
    A.num[2][1]=1;A.num[2][2]=1;
    A.num[3][1]=1;A.num[3][3]=1;
    X.num[0][3]=2;
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        matrix ans=mult(X,qpow(A,n-1));
        printf("%I64d\n",ans.num[0][0]);
    }
    return 0;
}
