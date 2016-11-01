#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
using namespace std;
const long long mod=1e9+7;
int n;
int nxt[200005];
int res;
long long qpow(long long x,long long k)
{
    long long ans=1;
    while(k)
    {
        if(k&1)
            ans=ans*x%mod;
        k>>=1;
        x=x*x%mod;
    }
    return ans;
}
long long sum;
long long ans=1;
int step[200005];
int pos[200005];
void dfs(int rt,int stp,int cor)
{
    step[rt]=stp;
    pos[rt]=cor;
    int nt=nxt[rt];
    if(pos[nt]==pos[rt])
    {
        sum=sum-(step[rt]-step[nt]+1);
        ans=ans*(qpow(2,step[rt]-step[nt]+1)+mod-2)%mod;
        return ;
    }
    else if(pos[nt]==0)
        dfs(nt,stp+1,cor);
}
int main()
{
    scanf("%d",&n);
    sum=n;
    for(int i=1;i<=n;i++)scanf("%d",&nxt[i]);
    for(int i=1;i<=n;i++)
    {
        if(pos[i]==0)dfs(i,1,i);
    }
    ans=ans*qpow(2,sum)%mod;
    printf("%I64d\n",(ans%mod+mod)%mod);
    return 0;
}
