#include<bits/stdc++.h>
using namespace std;
int n,m,t;
int cost[5005][5005];
vector<int>to[5005];
int pre[5005];
vector<int>tosort;

void topo()
{
    queue<int>Q;
    for(int i=0;i<n;i++)
    {
        if(pre[i]==0)Q.push(i);
    }
    while(!Q.empty())
    {
        int head=Q.front();
        tosort.push_back(head);
        Q.pop();
        for(int i=0;i<to[head].size();i++)
        {
            int nxt=to[head][i];
            pre[nxt]--;
            if(pre[nxt]==0)
            Q.push(nxt);
        }
    }
}
int dp[5005][5005];
int main()
{
    memset(cost,0x3f,sizeof(cost));
    scanf("%d%d%d",&n,&m,&t);
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        u--;
        v--;
        to[u].push_back(v);
        cost[u][v]=w;
        pre[v]++;
    }
    topo();
    int head=0,tail=n-1;
    while(tosort[head]!=0)head++;
    while(tosort[tail]!=n-1)tail--;
    memset(dp,-1,sizeof(dp));
    dp[tosort[head]][1]=0;
    for(int i=head;i<tail;i++)
    {
        int now=tosort[i];
        for(int j=1;j<=n;j++)
        {
            if(dp[now][j]==-1)continue;
            for(int k=0;k<to[now].size();k++)
            {
                int nxt=to[now][k];
                if(dp[nxt][j+1]==-1&&dp[now][j]+cost[now][nxt]<=t)dp[nxt][j+1]=dp[now][j]+cost[now][nxt];
                else if(dp[now][j]+cost[now][nxt]<=t) dp[nxt][j+1]=min(dp[nxt][j+1],dp[now][j]+cost[now][nxt]);
            }
        }
    }
    int has;
    for(int i=n;i>=1;i--)
    {
        if(dp[n-1][i]!=-1&&dp[n-1][i]<=t)
        {
            has=i;
            break;
        }
    }
    vector<int>ans;
    ans.push_back(n-1);
    int now=n-1;
    for(int i=tail-1;i>=head;i--)
    {
        if(dp[tosort[i]][has-1]+cost[tosort[i]][now]==dp[now][has])
        {
            ans.push_back(tosort[i]);
            now=tosort[i];
            has--;
        }
    }
    printf("%d\n",ans.size());
    for(int i=ans.size()-1;i>=0;i--)
    printf("%d ",ans[i]+1);
    return 0;
}
