#include <bits/stdc++.h>

using namespace std;
int mod=100000073;
int l[5000006],r[5000006];
int dp[5000006];
int cnt[5000006];
int sum[5000006];
int f(int x,int y)
{
    return max(y-1,dp[x-y]);
}
int main()
{
    l[1]=r[1]=dp[1]=cnt[1]=sum[0]=1;
    sum[1]=2;
    for(int i=2;i<=5000000;i++)
    {
        for(l[i]=l[i-1];l[i]<i&&f(i,l[i]+1)<=f(i,l[i]);l[i]++);
        dp[i]=f(i,l[i])+1;
        for(r[i]=r[i-1];r[i]<i&&f(i,r[i])>f(i,l[i]);r[i]++);
        for(;r[i]<i&&f(i,r[i]-1)==f(i,l[i]);r[i]--);
        cnt[i]=(sum[i-r[i]]-sum[i-l[i]-1]+mod)%mod;
        sum[i]=(sum[i-1]+cnt[i])%mod;
    }
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        printf("%d %d\n",dp[b-a+1],cnt[b-a+1]);
    }
    return 0;
}
