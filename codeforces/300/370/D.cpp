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
#define eps 1e-8
long long mod=1e9+7;
long long dp[2][404005];
const int tail=404010;
long long pre[tail];
long long suf[tail];
long long sum[tail];
int main()
{
    int a,b,k,t;
    scanf("%d%d%d%d",&a,&b,&k,&t);
    dp[0][2000*(t+1)+1]=1;
    int mid=2000*(t+1)+1;
    int now=0,next=1;
    for(int i=1;i<=t;i++)
    {
        memset(pre,0,sizeof(pre));
        memset(suf,0,sizeof(suf));
        memset(sum,0,sizeof(sum));
        for(int j=mid-i*k*2;j<=mid+i*k*2;j++)
        {
            pre[j]=dp[now][j]*j%mod;
            suf[j]=dp[now][j]*(tail-j+1)%mod;
            sum[j]=dp[now][j];
        }
        for(int j=mid-i*k*2;j<=tail;j++)
        {
            pre[j]=(pre[j-1]+pre[j]);
            suf[j]+=suf[j-1];
            sum[j]=(sum[j-1]+sum[j]);
            if(pre[j]>=mod)pre[j]-=mod;
            if(suf[j]>=mod)suf[j]-=mod;
            if(sum[j]>=mod)sum[j]-=mod;
        }
        for(int j=mid-i*k*2;j<=mid+i*k*2;j++)
        {
            long long val=pre[j]-pre[j-2*k-1]-(sum[j]-sum[j-2*k-1])*(j-2*k-1);
            val+=suf[j+2*k]-suf[j]-(sum[j+2*k]-sum[j])*(tail-(j+2*k));
            val=(val%mod+mod)%mod;
            dp[next][j]=val;
        }
        swap(now,next);
    }
    long long ans=0;
    for(int i=mid+b-a+1;i<=mid+t*k*2;i++)
    {
        ans+=dp[now][i];
    }
    ans%=mod;
    printf("%I64d\n",ans);
    return 0;
}
