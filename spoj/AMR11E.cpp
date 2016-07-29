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
int prime[216817],prinum;
int cnt[maxn];
vector<int>vec;
void init()
{
    phi[1]=1;
    for(int i=2;i<maxn;i++)
    {
        if(!notprime[i])
        {
            prime[prinum++]=i;
            phi[i]=i-1;
        }
        for(int j=0;j<prinum;j++)
        {
            if(i*prime[j]>=maxn)break;
            notprime[i*prime[j]]=1;
            if(i%prime[j]==0)
            {
                phi[i*prime[j]]=prime[j]*phi[i];
                break;
            }
            else
            {
                phi[i*prime[j]]=phi[i]*(prime[j]-1);
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
        if(cnt[i]>=3)
            vec.push_back(i);
    }
}
int main()
{
    init();
//    printf("%d\n",vec.size());
//    printf("%d\n",prinum);
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        int n;
        scanf("%d",&n);
        printf("%d\n",vec[n-1]);
    }
    return 0;
}
