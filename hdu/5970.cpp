#include <cstdio>
#include <cstring>
#include <map>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
#define eps 1e-8
int f(int a,int b)
{
    if(b==0)return 0;
    return 1+f(b,a%b);
}
int c[667][667];
long long val[667][667][20];
int n,m;
long long p;
int GCD[667][667];
int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
long long cal(long long a0,long long n,long long d)
{
    return (n*(a0+a0+(n-1)*d)/2);
}
int main()
{
    for(int i=0; i<=666; i++)for(int j=0; j<=666; j++)
        {
            GCD[i][j]=gcd(i,j);
            c[i][j]=f(i,j);
        }
    int T;
    scanf("%d",&T);
    for(int i=1; i<=666; i++)for(int j=0; j<i; j++)
        {
            for(int k=0; k<c[i][j]+1; k++)
                if(k)
                    val[i][j][k]=val[i][j][k-1]+((1LL*i*(k*i+j))/(c[i][j]+1));
                else
                    val[i][j][k]=(1LL*i*(k*i+j))/(c[i][j]+1);
        }
    while(T--)
    {
        scanf("%d%d%I64d",&n,&m,&p);
        long long ans=0;
        for(int d=1; d<=m; d++)
        {
            for(int j=1; j<=m/d; j++)for(int i=0; i<j; i++)
                {
                    int res=n/d;
                    if(res<i)continue;
                    if(j>1&&(i==0||GCD[i][j]!=1))continue;
                    int len=c[i][j];
                    int cnt=(res-i)/j+1;
                    int num=cnt/len;
                    ans+=cal(val[j][i][len-1],num,len*j*j);
                    cnt%=len;
                    ans+=(1LL*num*j*j*cnt);
                    ans+=val[j][i][cnt-1];
                    ans%=p;
                }
        }
        printf("%I64d\n",ans%p);
    }
    return 0;
}
