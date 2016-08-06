#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<unordered_map>
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
#define eps 1e-14
const int maxn=100005;
bool notprime[maxn];
int prime[maxn],prinum;
void getprime()
{
    for(int i=2;i<maxn;i++)
    {
        if(!notprime[i])
            prime[prinum++]=i;
        for(int j=0;j<prinum&&i*prime[j]<maxn;j++)
        {
            notprime[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
}
long long gcd(long long a,long long b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
bool vis[1005][10005];
int dp[1005][10005];
long long sum[1005][10005];
pair<int,int>pre[1005][10005];
int n;
long long k;
long long fac[30][2];
int facnum;
long long facs[10005];
int facsnum;
void dfs(int pos,long long val)
{
    if(pos==facnum)
    {
        facs[facsnum++]=val;
        return ;
    }
    for(int i=0;i<=fac[pos][1];i++)
    {
        dfs(pos+1,val);
        val*=fac[pos][0];
    }
}
void getfac(long long x)
{
    for(int i=0;i<prinum;i++)
    {
        if(prime[i]>x/prime[i])break;
        if(x%prime[i]==0)
        {
            fac[facnum][0]=prime[i];
            while(x%prime[i]==0)
            {
                x/=prime[i];
                fac[facnum][1]++;
            }
            facnum++;
        }
    }
    if(x!=1)
    {
        fac[facnum][0]=x;
        fac[facnum][1]=1;
        facnum++;
    }
}
unordered_map<long long,int>mp;
long long a[1005];
long long b[1005];
int main()
{
    getprime();
    memset(dp,0x3f,sizeof(dp));
    memset(sum,0x3f,sizeof(sum));
    scanf("%d%I64d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%I64d",&a[i]);
        b[i]=gcd(a[i],k);
    }
    if(k==1)
    {
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]<a[ans])
            ans=i;
        }
        printf("1\n%d\n",ans+1);
        return 0;
    }
    getfac(k);
    dfs(0,1LL);
    sort(facs,facs+facsnum);
    for(int i=0;i<facsnum;i++)
        mp[facs[i]]=i;
    dp[0][0]=0;
    sum[0][0]=0;
    vis[0][0]=1;
    pre[0][0]=make_pair(-1,-1);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<facsnum;j++)
        {
            if(vis[i][j]==0)continue;
            if(dp[i+1][j]>dp[i][j]||(dp[i+1][j]==dp[i][j]&&sum[i+1][j]>sum[i][j]))
            {
                vis[i+1][j]=1;
                dp[i+1][j]=dp[i][j];
                sum[i+1][j]=sum[i][j];
                pre[i+1][j]=pre[i][j];
            }
            int nxt=mp[gcd(k/b[i],facs[j])*b[i]];
            if(dp[i+1][nxt]>dp[i][j]+1||(dp[i+1][nxt]==dp[i][j]+1&&sum[i+1][nxt]>sum[i][j]+a[i]))
            {
                vis[i+1][nxt]=1;
                dp[i+1][nxt]=dp[i][j]+1;
                sum[i+1][nxt]=sum[i][j]+a[i];
                pre[i+1][nxt]=make_pair(i,j);
            }
        }
    }
    if(vis[n][facsnum-1])
    {
        printf("%d\n",dp[n][facsnum-1]);
        vector<int>ans;
        int nowi=n,nowj=facsnum-1;
        while(nowi>0)
        {
            pair<int,int>pr=pre[nowi][nowj];
            nowi=pr.first;
            nowj=pr.second;
            if(nowi==-1)
                break;
            ans.push_back(nowi+1);

        }
        for(int i=0;i<ans.size();i++)
            printf("%d ",ans[i]);
        printf("\n");
    }
    else
    {
        printf("-1\n");
    }

    return 0;
}
