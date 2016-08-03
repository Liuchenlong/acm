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
int siz=36;
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
vector<int>mask;
matrix A,X;
int ones(int x)
{
    int ans=0;
    while(x)
    {
        ans+=x%2;
        x/=2;
    }
    return ans;
}
bool ok(int m1,int m2)
{
    for(int i=0;i<10;i++)
    {
        if(m1&(1<<i))
        {
            if(i==0);
            else if(m2&(1<<(i-1)))
                return false;
            if(m2&(1<<i))
                return false;
            if(m2&(1<<(i+1)))
                return false;
        }
    }
    return true;
}
void init()
{
    for(int i=0;i<siz;i++)E.num[i][i]=1;
    for(int i=0;i<siz;i++)X.num[0][i]=1;
    for(int i=0;i<(1<<10);i++)
    {
        if(ones(i)==2&&(i&(i<<1))==0)
            mask.push_back(i);
    }
    for(int i=0;i<siz;i++)
    {
        for(int j=0;j<siz;j++)
        {
            if(ok(mask[i],mask[j]))
                A.num[i][j]=1;
        }
    }
}

int main()
{
    init();
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        int n;
        scanf("%d",&n);
        matrix ans=mult(X,qpow(A,n-1));
        unsigned int sum=0;
        for(int i=0;i<siz;i++)
            sum+=ans.num[0][i];
        printf("Case %d: %u\n",cas,sum);
    }
    return 0;
}
