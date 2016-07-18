/*
Mobius反演+分块加速
*/

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
#define eps 1e-8
const int mod=10007;
#define SIZE 500005
int prime[SIZE],prinum;
bool notprime[SIZE];
int mu[SIZE];
int num[SIZE];
long long F[SIZE][20];
void init()
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
    for(int i=2; i<SIZE; i++)
    {
        int t=i;
        for(int j=0; j<prinum; j++)
        {
            if(prime[j]*prime[j]>t)
                break;
            if(t%prime[j]==0)
            {
                while(t%prime[j]==0)
                {
                    num[i]++;
                    t/=prime[j];
                }
            }
        }
        if(t!=1)
            num[i]++;
    }
    for(int i=1; i<SIZE; i++)
    {
        for(int j=i; j<SIZE; j+=i)
        {
            F[j][num[i]]+=mu[j/i];
        }
        for(int j=1;j<20;j++)
            F[i][j]+=F[i][j-1];
    }
    for(int i=1;i<SIZE;i++)
    {
        for(int j=0;j<20;j++)
            F[i][j]+=F[i-1][j];
    }
}
int main()
{
    init();
    int Q;
    scanf("%d",&Q);
    while(Q--)
    {
        int n,m,P;
        scanf("%d%d%d",&n,&m,&P);
        if(P>18||(1<<P)>=max(n,m))
        {
            printf("%I64d\n",(long long)n*m);
            continue;
        }
        long long ans=0;
        int j;
        P=min(P,19);
        for(int i=1; i<=min(n,m); i=j+1)
        {
            j=min(n/(n/i),m/(m/i));
            ans+=(F[j][P]-F[i-1][P])*(n/i)*(m/i);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
