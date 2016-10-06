#include<stdio.h>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
const long long mod=1e9+7;
long long two[66];
long long cnt[66];
long long sumcnt[66];
long long ans[66];
void init()
{
    for(int i=0;i<62;i++)two[i]=(1LL<<i);
    cnt[0]=sumcnt[0]=ans[0]=0;
    cnt[1]=sumcnt[1]=ans[1]=1;
    for(int i=2;i<62;i++)
    {
        cnt[i]=(sumcnt[i-1]+(1LL<<(i-1)%mod)%mod)%mod;
        sumcnt[i]=(sumcnt[i-1]+cnt[i])%mod;
        ans[i]=(ans[i-1]*2LL+(1LL<<(i-1)%mod)%mod*sumcnt[i]%mod)%mod;
    }
}
long long calcnt(long long n)///0~n
{
    if(n==0)return 0;
    if(n==1)return 1;
    int pos=upper_bound(two,two+62,n)-two-1;
    return (sumcnt[pos]+calcnt(n-two[pos])+(n-two[pos]+1)%mod)%mod;
}
long long cal(long long n)///0~n
{
    if(n==0)return 0;
    if(n==1)return 1;
    int pos=upper_bound(two,two+62,n)-two-1;
    return (ans[pos]+cal(n-two[pos])
            +(n-two[pos]+1)%mod*sumcnt[pos]%mod
            +two[pos]%mod*((n-two[pos]+1)%mod+calcnt(n-two[pos]))%mod)%mod;
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        long long n;
        scanf("%I64d",&n);
        printf("Case #%d: %I64d\n",cas,(cal(n)%mod+mod)%mod);
    }
    return 0;
}
