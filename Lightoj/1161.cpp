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
#define SIZE 10005
bool notprime[SIZE];
int prime[SIZE],prinum;
int mu[SIZE];
long long C[SIZE][10];
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
            if(i%prime[j])
                mu[i*prime[j]]=-mu[i];
            else
            {
                mu[i*prime[j]]=0;
                break;
            }
        }
    }
    C[0][0]=1;
    for(int i=1; i<=10000; i++)
    {
        C[i][0]=1;
        for(int j=1; j<=min(4,i); j++)
        {
            C[i][j]=C[i-1][j-1]+C[i-1][j];
        }
    }
}
int cnt[10005];
int main()
{
    init();
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        memset(cnt,0,sizeof(cnt));
        int n;
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
        {
            int x;
            scanf("%d",&x);
            for(int i=1; i*i<=x; i++)
            {
                if(x%i==0)
                {
                    cnt[i]++;
                    if(i*i==x);
                    else cnt[x/i]++;
                }
            }
        }
        long long ans=0;
        for(int i=1; i<=10000; i++)
        {
            ans+=C[cnt[i]][4]*mu[i];
        }
        printf("Case %d: %lld\n",cas,ans);
    }
    return 0;
}
