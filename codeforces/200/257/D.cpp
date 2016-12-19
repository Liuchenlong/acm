#include <bits/stdc++.h>
using namespace std;
int n,m,k;
vector<pair<int,int> >to[100005];
long long inf=1e15;
long long d[100005];
bool vis[100005];
bool inq[100005];
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++)
    {
        int u,v,x;
        scanf("%d%d%d",&u,&v,&x);
        to[u].push_back(make_pair(v,x));
        to[v].push_back(make_pair(u,x));
    }
    for(int i=1;i<=n;i++)d[i]=inf;
    d[1]=0;
    queue<int>q;
    int ans=k;
    q.push(1);
    inq[1]=1;
    for(int i=0;i<k;i++)
    {
        int s,y;
        scanf("%d%d",&s,&y);
        if(d[s]>y)
        {
            d[s]=y;
            vis[s]=1;
            if(inq[s]==0)
            {
                inq[s]=1;
                q.push(s);
            }
        }
    }
    while(!q.empty())
    {
        int head=q.front();
        q.pop();
        inq[head]=0;
        for(int i=0;i<to[head].size();i++)
        {
            int v=to[head][i].first,x=to[head][i].second;
            if(d[v]>=d[head]+x&&vis[v])
            vis[v]=0;
            if(d[v]>d[head]+x)
            {
                d[v]=d[head]+x;
                if(inq[v]==0)
                {
                    inq[v]=1;
                    q.push(v);
                }
            }

        }
    }
    for(int i=1;i<=n;i++)
        ans-=vis[i];
    printf("%d\n",ans);
    return 0;
}
