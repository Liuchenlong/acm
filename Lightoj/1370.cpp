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
const int maxn=1000000+100;

bool notprime[maxn];
int phi[maxn];
int prime[664585],prinum;
int val[maxn];
void init()
{
    for(int i=2; i<maxn; i++)
    {
        if(!notprime[i])
        {
            prime[prinum++]=i;
            phi[i]=i-1;
        }
        for(int j=0; j<prinum; j++)
        {
            if(i*prime[j]>maxn)
                break;
            notprime[i*prime[j]]=1;
            if(i%prime[j]==0)
            {
                phi[i*prime[j]]=phi[i]*prime[j];
                break;
            }
            else
            {
                phi[i*prime[j]]=phi[i]*(prime[j]-1);
            }
        }
    }
    for(int i=1; i<maxn; i++)
        val[i]=1e9;
    for(int i=maxn-1; i>=2; i--)
        val[phi[i]]=i;
    for(int i=maxn-2; i>=1; i--)
    {
        if(val[i])
            val[i]=min(val[i],val[i+1]);
        else
            val[i]=val[i+1];
    }
}

int main()
{
    init();
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        int n;
        scanf("%d",&n);
        long long ans=0;
        for(int i=0; i<n; i++)
        {
            int x;
            scanf("%d",&x);
            ans+=val[x];
        }
        printf("Case %d: %lld Xukha\n",cas,ans);
    }
    return 0;
}
