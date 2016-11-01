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
#include<bitset>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-7
#define SIZE 2005
bool notprime[SIZE];
int prime[SIZE],prinum;
const long long mod=(1<<30);
int mu[SIZE];
int sum[SIZE];
int GCD[SIZE][SIZE];
int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
void getmu()
{
    mu[1]=1;
    for(int i=2; i<SIZE; i++)
    {
        if(!notprime[i])
        {
            prime[prinum++]=i;
            mu[i]=-1;
        }
        for(int j=0; j<prinum&&i*prime[j]<SIZE; j++)
        {
            notprime[i*prime[j]]=1;
            if(i%prime[j])mu[i*prime[j]]=-mu[i];
            else
            {
                mu[i*prime[j]]=0;
                break;
            }
        }
    }
    for(int i=1; i<SIZE; i++)
        sum[i]=sum[i-1]+mu[i];
    for(int i=1;i<SIZE;i++)for(int j=1;j<SIZE;j++)
        GCD[i][j]=gcd(i,j);
}
long long cal(int a,int n)
{
    long long ans=0;
    for(int i=1;i<=n;i++)
        if(GCD[i][a]==1)
        ans+=n/i;
    return ans;
}
int main()
{
    getmu();
    long long ans=0;
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    for(int i=1;i<=a;i++)
    {
        long long sum=0;
        for(int d=1;d<=min(b,c);d++)
        {
            if(GCD[i][d]==1)
                sum+=(long long)mu[d]*cal(i,b/d)*cal(i,c/d)%mod;
        }
        ans+=sum*(a/i)%mod;
    }
    printf("%I64d\n",ans%mod);
    return 0;
}
