#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

bool isprime[1000005];
int prime[1000005],num;
int sum[1000005];
bool dprime(int n)
{
    int term=0;
    int t=n;
    while(t)
    {
        term+=t%10;
        t/=10;
    }
    if(!isprime[term])
        return true;
    return false;
}
int main()
{
    for(int i=2; i<1000005; i++)
    {
        if(isprime[i])
            continue;
        prime[num++]=i;
        for(int j=2*i; j<1000005; j+=i)
        {
            isprime[j]=1;
        }
    }
    for(int i=2;i<1000005;i++)
    {
        if(!isprime[i]&&dprime(i))
            sum[i]=sum[i-1]+1;
        else
            sum[i]=sum[i-1];
    }
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",sum[r]-sum[l-1]);
    }
    return 0;
}
