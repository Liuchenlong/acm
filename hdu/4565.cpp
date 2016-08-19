#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(a) (a<0?-a:a)

using namespace std;
long long a,b,nn,mod;
int n=2;
struct matrix
{
    long long num[3][3];
} m,E;
matrix mult(matrix a,matrix b)
{
    matrix c;
    memset(c.num,0,sizeof(c.num));
    for(int k=0; k<n; k++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                c.num[i][j]+=a.num[i][k]*b.num[k][j];
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            c.num[i][j]=(c.num[i][j]%mod+mod)%mod;
        }
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
    while(scanf("%I64d%I64d%I64d%I64d",&a,&b,&nn,&mod)!=EOF)
    {
        E.num[0][0]=1;
        E.num[1][1]=1;

        m.num[0][0]=2*a;
        m.num[0][1]=b-a*a;
        m.num[1][0]=1;

        matrix tmp;
        tmp.num[0][0]=ceil(sqrt(b)+a);
        tmp.num[1][0]=2;

        if(nn==1)
            printf("%I64d\n",tmp.num[0][0]%mod);
        else
        {
            matrix term=qpow(m,nn-1);
            matrix ans=mult(term,tmp);
            printf("%I64d\n",(ans.num[0][0])%mod);
        }
    }
    return 0;
}
