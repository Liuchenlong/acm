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
#define SIZE 1000005
bool notprime[SIZE];
int prime[SIZE],prinum;
const long long mod=1e9+7;
int mu[SIZE];
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
}
bool check(int m,int k,int x)
{
    int ans=0;
    for(int i=1;i*i<=m;i++)
    {
        if(m%i==0)
        {
            ans+=mu[i]*(x/i);
            if(i*i==m);
            else ans+=mu[m/i]*(x/(m/i));
        }
    }
    return ans>=k;
}
int main()
{
    getmu();
    int m,k;
    while(scanf("%d%d",&m,&k)!=EOF)
    {
        int l=1,r=1e9;
        while(l<r)
        {
            int mid=(l+r)/2;
            if(check(m,k,mid))
                r=mid;
            else
                l=mid+1;
        }
        printf("%d\n",r);
    }

    return 0;
}
