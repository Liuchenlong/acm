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
const long long mod=1e9+7;
const int maxn = 1000000+20;
int phi[maxn];
bool notprime[maxn];
int prime[maxn/10],prinum;
void init()
{
    phi[1]=1;
    for(int i=2; i<maxn; i++)
    {
        if(!notprime[i])
        {
            prime[prinum++]=i;
            phi[i]=i-1;
        }
        for(int j=0; j<prinum; j++)
        {
            if(i*prime[j]>=maxn)break;
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
}
int main()
{
    init();
//    int T;
//    scanf("%d",&T);
//    for(int cas=1;cas<=T;cas++)
//    {
    int n;
    scanf("%d",&n);
    bool flag=false;
    for(int i=0; i<prinum; i++)
    {
        if(prime[i]>n)
            break;
        if(flag)
            printf(" * ");
        int tim=0;
        int now=prime[i];
        while(now<=n)
        {
            tim+=n/now;
            now*=prime[i];
        }
        printf("%d^%d",prime[i],tim);
        flag=true;
    }
    printf("\n");
//    }
    return 0;
}
