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
const int maxn=1000000;
bool notprime[maxn];
int prime[maxn],prinum;
void getprime()
{
    for(int i=2; i<maxn; i++)
    {
        if(notprime[i])continue;
        prime[prinum++]=i;
        for(int j=2*i; j<maxn; j+=i)
            notprime[j]=1;
    }
}
int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
long long num[33][33];
int main()
{
    freopen("elegant.in","r",stdin);
    freopen("elegant.out","w",stdout);
    getprime();
    long long val=1;
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            num[i][j]=1;
        }
    }
    int x=0;
    for(int i=1;i<n;i++)
    {
        if(i==1||i==n-1)
        for(int j=0;j<n;j++)
        {
            int nowi=0,nowj=j;
            for(int k=0;k<n;k++)
            {
                num[nowi][nowj]*=prime[j+x*n];
                nowi++;
                nowj+=i;
                nowj%=n;
            }
        }
        x++;
    }
    if(n%2==0)
    {
        int t=n/2;
        int det=0;
        for(int j=0;j<n;j++)
        {
            det=0;
            int nowi=0,nowj=j;
            for(int k=0;k<n;k+=2)
            {
                num[nowi][(nowj+det)%n]*=prime[j+x*n];
                num[nowi+1][(nowj+t+det)%n]*=prime[j+x*n];
                det++;
                nowi+=2;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%I64d ",num[i][j]);
        }
        printf("\n");
    }
    return 0;
}

