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
const int maxn=1000005;
bool notprime[maxn];
int prime[78599],prinum;
void getprime()
{
    for(int i=2;i<maxn;i++)
    {
        if(!notprime[i])
        {
            prime[prinum++]=i;
        }
        for(int j=0;j<prinum&&i*prime[j]<maxn;j++)
        {
            notprime[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
}
int dis[maxn];
void initdis()
{
    for(int i=0;i<prinum;i++)
    {
        int x=1;
        int now=0;
        while(x<=maxn/prime[i])
        {
            x*=prime[i];
            for(int j=x;j<maxn;j+=x)
            {
                dis[j]++;
            }
        }

    }
}
int vsiz;
int vpos[maxn];
bool vis[maxn];
vector<int>vec[300005];
int sizv[300005];
struct qry
{
    char str[3];
    int x;
};
int n;
qry q[50005];
int fac[20][2];
int facnum;
void getfac(int x)
{
    facnum=0;
    for(int i=0;i<prinum;i++)
    {
        if(prime[i]*prime[i]>x)
            break;
        if(x%prime[i]==0)
        {
            fac[facnum][1]=0;
            fac[facnum][0]=prime[i];
            while(x%prime[i]==0)
            {
                fac[facnum][1]++;
                x/=prime[i];
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
int pnow;
int dp[maxn][33];
int num[maxn];
void dfs(int pos,int val)
{
    if(pos==facnum)
    {
        vec[pnow].push_back(val);
        sizv[pnow]++;
        return ;
    }
    for(int j=0;j<=fac[pos][1];j++)
    {
        dfs(pos+1,val);
        val*=fac[pos][0];
    }
}
int main()
{
    getprime();
    initdis();
    int cas=0;
    while(scanf("%d",&n),n)
    {
        cas++;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            scanf("%s%d",&q[i].str,&q[i].x);
            num[q[i].x]=0;
            if(vis[q[i].x])
                ;
            else
            {
                vis[q[i].x]=1;
                vpos[q[i].x]=vsiz++;
                if(q[i].x==1)
                {
                    vec[vpos[q[i].x]].push_back(1);
                    sizv[vpos[q[i].x]]=1;
                    continue;
                }
                pnow=vpos[q[i].x];
                getfac(q[i].x);
                dfs(0,1);
            }
        }
        printf("Case #%d:\n",cas);
        for(int i=0;i<n;i++)
        {
            if(q[i].str[0]=='I')
            {
                if(num[q[i].x])continue;
                else
                {
                    num[q[i].x]++;
                    int pp=vpos[q[i].x];
                    for(int j=0;j<sizv[pp];j++)
                    {
                        int val=vec[pp][j];
                        dp[val][dis[q[i].x/val]]++;
                    }
                }
            }
            if(q[i].str[0]=='D')
            {
                if(num[q[i].x]==0)continue;
                else
                {
                    num[q[i].x]--;
                    int pp=vpos[q[i].x];
                    for(int j=0;j<sizv[pp];j++)
                    {
                        int val=vec[pp][j];
                        dp[val][dis[q[i].x/val]]--;
                    }
                }
            }
            if(q[i].str[0]=='Q')
            {
                int ans=100;
                int pp=vpos[q[i].x];
                for(int j=0;j<sizv[pp];j++)
                {
                    int val=vec[pp][j];
                    for(int k=0;k<=20;k++)
                    {
                        if(dp[val][k])
                        {
                            ans=min(ans,k+dis[q[i].x/val]);
                        }
                    }
                }
                if(ans==100)
                    printf("-1\n");
                else
                    printf("%d\n",ans);
            }
        }
    }
    return 0;
}
