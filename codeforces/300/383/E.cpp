#include <bits/stdc++.h>

using namespace std;
int n;
vector<int>to[200005];
bool vis[200005];
int ans[200005];
void bfs(int x)
{
    queue<int>q;
    q.push(x);
    vis[x]=1;
    ans[x]=0;
    while(!q.empty())
    {
        int head=q.front();
        q.pop();
        for(int i=0;i<to[head].size();i++)
        {
            int nxt=to[head][i];
            if(vis[nxt])continue;
            vis[nxt]=1;
            ans[nxt]=1^ans[head];
            q.push(nxt);
        }
    }
}
int l[100005],r[100005];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=2*n;i+=2)
    {
        to[i].push_back(i+1);
        to[i+1].push_back(i);
    }
    for(int i=0;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        l[i]=u,r[i]=v;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    memset(ans,-1,sizeof(ans));
    for(int i=1;i<=2*n;i++)
    {
        if(vis[i])continue;
        bfs(i);
    }
    for(int i=0;i<n;i++)
    {
        printf("%d %d\n",ans[l[i]]+1,ans[r[i]]+1);
    }
    return 0;
}
