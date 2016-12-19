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

long long mod=1000000007;
int n=2;
//¾ØÕó¿ìËÙÃÝ
struct matrix
{
    long long num[55][55];
    matrix()
    {
        memset(num,0,sizeof(num));
    }
} m,E;
matrix mult(matrix a,matrix b)
{
    matrix c;
    for(int k=0; k<n; k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                c.num[i][j]+=a.num[i][k]*b.num[k][j];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            c.num[i][j]=(c.num[i][j]%mod+mod)%mod;
        }
    return c;
}
matrix qpow(matrix x,int t)
{
    matrix b = E;
    while (t > 0)
    {
        if (t & 1)
            b = mult(b,x);
        t = t >> 1 ;
        x = mult(x,x);
    }
    return b;
}
int main()
{
    int x,y,t;
    scanf("%d%d%d",&x,&y,&t);
    x=(x%mod+mod)%mod;
    y=(y%mod+mod)%mod;
    for(int i=0; i<2; i++)
        E.num[i][i]=1;
    matrix ans;
    ans.num[0][0]=x;
    ans.num[1][0]=y;
    matrix m;
    m.num[0][1]=1;
    m.num[1][0]=-1;
    m.num[1][1]=1;
    if(t==1)
        printf("%d\n",x);
    else if(t==2)
        printf("%d\n",y);
    else
    {
        m=qpow(m,t-1);
        ans=mult(m,ans);
        printf("%I64d\n",(ans.num[0][0]%mod+mod)%mod);
    }
    return 0;
}
