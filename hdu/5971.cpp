#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
#define eps 1e-8
bool vis[1005];
int d[1005];
vector<int>vec[1005];
int n,m,x,y;
int type[1005];
bool bfs(int pos)
{
    queue<int>Q;
    Q.push(pos);
    vis[pos]=1;
    while(!Q.empty())
    {
        int head=Q.front();
        Q.pop();
        for(int i=0;i<vec[head].size();i++)
        {
            int nxt=vec[head][i];
            if(vis[nxt])
            {
                if(type[nxt]==1^type[head])continue;
                else
                    return false;
            }
            if(type[nxt]!=-1)
            {
                if(type[nxt]!=1^type[head])
                    return false;
            }
            vis[nxt]=1;
            type[nxt]=1^type[head];
            Q.push(nxt);
        }
    }
    return true;
}
int main()
{
    while(scanf("%d%d%d%d",&n,&m,&x,&y)!=EOF)
    {
        memset(vis,0,sizeof(vis));
        memset(type,-1,sizeof(type));
        for(int i=1;i<=n;i++)vec[i].clear();
        for(int i=0;i<m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            d[u]++;
            d[v]++;
            vec[u].push_back(v);
            vec[v].push_back(u);
        }
        for(int i=0;i<x;i++)
        {
            int pos;
            scanf("%d",&pos);
            type[pos]=1;
        }
        for(int i=0;i<y;i++)
        {
            int pos;
            scanf("%d",&pos);
            type[pos]=0;
        }
        bool flag=true;
        for(int i=1;i<=n;i++)
        {
            if(vis[i])continue;
            if(type[i]!=-1)
            {
                if(bfs(i)==0)
                    flag=false;
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(vis[i])continue;
            if(d[i]>0)
            {
                type[i]=1;
                if(bfs(i)==0)
                    flag=false;
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(type[i]==-1)
            {
                flag=false;
                break;
            }
        }
        if(!flag)puts("NO");
        else puts("YES");
    }
    return 0;
}
