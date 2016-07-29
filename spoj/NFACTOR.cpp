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
int cnt[maxn];
int sum[11][maxn];
void init()
{
    for(int i=2; i<maxn; i++)
    {
        if(!notprime[i])
        {
            prime[prinum++]=i;
        }
        for(int j=0; j<prinum; j++)
        {
            if(i*prime[j]>=maxn)break;
            notprime[i*prime[j]]=1;
            if(i%prime[j]==0)
            {
//                phi[i*prime[j]]=phi[i]*prime[j];
                break;
            }
            else
            {
//                phi[i*prime[j]]=phi[i]*(prime[j]-1);
            }
        }
    }
    for(int i=0;i<prinum;i++)
    {
        for(int j=prime[i];j<maxn;j+=prime[i])
            cnt[j]++;
    }
    for(int i=1;i<maxn;i++)
    {
        for(int j=0;j<=10;j++)
            sum[j][i]+=sum[j][i-1];
        sum[cnt[i]][i]++;
    }
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        int n,a,b;
        scanf("%d%d%d",&a,&b,&n);
        printf("%d\n",sum[n][b]-sum[n][a-1]);
    }
    return 0;
}
