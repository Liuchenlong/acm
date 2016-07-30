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
const long long mod=1e9+7;
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
long long d,x,y;
long long exgcd(long long a,long long b,long long &x,long long &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    else
    {
        long long ret=exgcd(b,a%b,x,y);
        long long temp=x;
        x=y;
        y=temp-a/b*y;
        return ret;
    }
}
long long inv(long long n,long long mod)
{
    d=exgcd(n,mod,x,y);
    x=(x%mod+mod)%mod;
    if(d==1)
        return x;
    return -1;//无逆元
}
int dp[1005];
int maxn;
void init()
{
    dp[1]=1;
    for(int i=2;; i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
        if(dp[i]>1e9)
            break;
        maxn=i;
    }
}
int main()
{
    init();
    for(int i=0; i<siz; i++)E.num[i][i]=1;
    int T;
    scanf("%d",&T);
    matrix A;
    A.num[0][1]=1;
    A.num[1][0]=1;
    A.num[1][1]=1;
    for(int cas=1; cas<=T; cas++)
    {
        long long N,X,M,Y,K;
        scanf("%lld%lld%lld%lld%lld",&N,&X,&M,&Y,&K);
        if(max(N,M)>maxn||X<dp[N]||Y<dp[M])
        {
            printf("Case %d: Impossible\n",cas);
            continue;
        }
        matrix mn=qpow(A,N-1);
        matrix mm=qpow(A,M-1);
        matrix mk=qpow(A,K-1);
        long long equ[2][3];
        matrix x;
        equ[0][0]=(mn.num[0][0]+mn.num[1][0])%mod;
        equ[0][1]=(mn.num[0][1]+mn.num[1][1])%mod;
        equ[0][2]=X;
        equ[1][0]=(mm.num[0][0]+mm.num[1][0])%mod;
        equ[1][1]=(mm.num[0][1]+mm.num[1][1])%mod;
        equ[1][2]=Y;
        for(int i=2; i>=0; i--)equ[0][i]=equ[0][i]*inv(equ[0][0],mod)%mod;
        for(int i=2; i>=0; i--)equ[1][i]=equ[1][i]*inv(equ[1][0],mod)%mod;
        for(int i=0; i<3; i++)
        {
            equ[1][i]=(equ[1][i]-equ[0][i]+mod)%mod;
        }
        if(equ[1][1]==0)
        {
            if(equ[1][2]!=0)
            {
                printf("Case %d: Impossible\n",cas);
                continue;
            }
            else
            {
                x.num[1][0]=0;
                x.num[0][0]=equ[0][2];
            }
        }
        else
        {
            x.num[1][0]=equ[1][2]*inv(equ[1][1],mod)%mod;
            x.num[0][0]=(equ[0][2]-equ[0][1]*x.num[1][0]%mod+mod)%mod;
        }
        long long checkN=(mn.num[0][0]+mn.num[1][0])*x.num[0][0]+(mn.num[0][1]+mn.num[1][1])*x.num[1][0];
        long long checkM=(mm.num[0][0]+mm.num[1][0])*x.num[0][0]+(mm.num[0][1]+mm.num[1][1])*x.num[1][0];
        if(checkN!=X||checkM!=Y)
        {
            printf("Case %d: Impossible\n",cas);
            continue;
        }
        matrix ans=mult(mk,x);
        printf("Case %d: %lld\n",cas,(ans.num[0][0]+ans.num[1][0])%mod);
    }
    return 0;
}
