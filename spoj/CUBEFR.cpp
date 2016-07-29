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
bool notprime[maxn];
int prime[maxn/10],prinum;
bool cube[maxn];
int sum[maxn];
void init()
{
    for(int i=2;i<maxn;i++)
    {
        if(!notprime[i])
        {
            prime[prinum++]=i;
        }
        for(int j=0;j<prinum;j++)
        {
            if(i*prime[j]>=maxn)break;
            notprime[i*prime[j]]=1;
            if(i%prime[j]==0)
            {
                break;
            }
        }
    }
    for(int i=0;i<prinum;i++)
    {
        long long x=prime[i]*prime[i]*prime[i];
        if(x>maxn)break;
        for(int j=x;j<maxn;j+=x)
            cube[j]=true;
    }
    for(int i=1;i<maxn;i++)
        sum[i]=sum[i-1]+(cube[i]==0);
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
        printf("Case %d: ",cas);
        if(cube[n])printf("Not Cube Free\n");
        else printf("%d\n",sum[n]);
    }
    return 0;
}
