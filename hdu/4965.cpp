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

int mod=6;
int n;
struct matrix
{
    int num[11][11];
    matrix()
    {
        memset(num,0,sizeof(num));
    }
} E;
matrix mult(matrix a,matrix b)
{
    matrix c;
    for(int k=0; k<n; k++)
        for(int i=0; i<n; i++)
        {
            if(a.num[i][k])
                for(int j=0; j<n; j++)
                {
                    c.num[i][j]+=(a.num[i][k]*b.num[k][j]);
                }
        }
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            c.num[i][j]%=mod;
    return c;
}
matrix qpow(matrix x,int t)
{
    matrix b = E;
    while (t > 0)
    {
        if (t & 1)b=mult(b,x);
        t = t >> 1 ;
        x=mult(x,x);
    }
    return b;
}
int numa[1005][1005];
int numb[1005][1005];
int numc[1005][1005];
int numd[1005][1005];
int main()
{
    for(int i=0; i<11; i++)
        E.num[i][i]=1;
    int m,k;
    while(1)
    {
        scanf("%d%d",&m,&k);
        if(m==0&&k==0)
            break;
        for(int i=0; i<m; i++)
            for(int j=0; j<k; j++)
                scanf("%d",&numa[i][j]);
        for(int i=0; i<k; i++)
            for(int j=0; j<m; j++)
                scanf("%d",&numb[i][j]);
        n=max(m,k);
        mod=6;
        matrix C;
        for(int i=0; i<k; i++)
        {
            for(int j=0; j<k; j++)
            {
                for(int w=0; w<m; w++)
                {
                    C.num[i][j]+=numb[i][w]*numa[w][j];
                }
            }
        }
        n=k;
        C=qpow(C,m*m-1);
        n=m;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<k; j++)
            {
                numc[i][j]=0;
                for(int w=0; w<k; w++)
                {
                    numc[i][j]+=numa[i][w]*C.num[w][j];
                }
            }
        }
        int aans=0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<m; j++)
            {
                numd[i][j]=0;
                for(int w=0; w<k; w++)
                {
                    numd[i][j]+=numc[i][w]*numb[w][j];
                }
                aans+=numd[i][j]%6;
            }
        }
        printf("%d\n",aans);
    }
    return 0;
}
