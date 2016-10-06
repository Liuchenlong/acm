#include <bits/stdc++.h>

using namespace std;
int n,m;
int s,t,ds,dt;
struct edge
{
    int u,v;
} E[400005];
vector<int>vecr[200005];
int pre[200005];
int find(int x)
{
    if(x!=pre[x])
        pre[x]=find(pre[x]);
    return pre[x];
}
void Union(int x,int y)
{
    pre[find(x)]=find(y);
}
int cpts[200005];
int tot;
int conts[200005];
int contt[200005];
map<int,int>to;
vector<int>dhas;
vector<int>ans;
void output(int pos)
{
    int siz=vecr[pos].size();
    for(int i=0; i<siz; i++)
    {
        int u=E[vecr[pos][i]].u;
        int v=E[vecr[pos][i]].v;
        if(find(u)==find(v))
            continue;
        else
        {
            Union(u,v);
            ans.push_back(vecr[pos][i]);
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)pre[i]=i;
    for(int i=0; i<m; i++)scanf("%d%d",&E[i].u,&E[i].v);
    scanf("%d%d%d%d",&s,&t,&ds,&dt);
    for(int i=0; i<m; i++)
    {
        if(E[i].u==s||E[i].u==t||E[i].v==s||E[i].v==t)continue;
        else if(find(E[i].u)!=find(E[i].v))
        {
            Union(E[i].u,E[i].v);
        }
    }
    for(int i=1; i<=n; i++)if(i!=s&&i!=t)cpts[tot++]=find(i);
    sort(cpts,cpts+tot);
    tot=unique(cpts,cpts+tot)-cpts;
    cpts[tot++]=s;
    cpts[tot++]=t;
    for(int i=0; i<tot; i++)to[cpts[i]]=i;
    memset(conts,-1,sizeof(conts));
    memset(contt,-1,sizeof(contt));
    for(int i=0; i<m; i++)
    {
        if(E[i].u==s)conts[to[find(E[i].v)]]=i;
        if(E[i].v==s)conts[to[find(E[i].u)]]=i;
        if(E[i].u==t)contt[to[find(E[i].v)]]=i;
        if(E[i].v==t)contt[to[find(E[i].u)]]=i;
        if(find(E[i].u)==find(E[i].v))
            vecr[to[find(E[i].u)]].push_back(i);
    }
    for(int i=1; i<=n; i++)pre[i]=i;
    for(int i=0; i<tot-2; i++)
    {
        output(i);
        if(conts[i]>=0&&contt[i]>=0)dhas.push_back(i);
        else if(conts[i]>=0)
        {
            ans.push_back(conts[i]);
            ds--;
        }
        else if(contt[i]>=0)
        {
            ans.push_back(contt[i]);
            dt--;
        }
    }
    if(dhas.size()==0)
    {
        ds--;
        dt--;
        ans.push_back(conts[tot-1]);
        if(ds<0||dt<0)
            printf("No\n");
        else
        {
            printf("Yes\n");
            for(int i=0; i<ans.size(); i++)
            {
                printf("%d %d\n",E[ans[i]].u,E[ans[i]].v);
            }
        }
    }
    else
    {
        for(int i=0; i<dhas.size(); i++)
        {
            if(i==0)
            {
                ans.push_back(conts[dhas[i]]);
                ans.push_back(contt[dhas[i]]);
                ds--;
                dt--;
            }
            else
            {
                if(ds<dt)
                {
                    ans.push_back(contt[dhas[i]]);
                    dt--;
                }
                else
                {
                    ans.push_back(conts[dhas[i]]);
                    ds--;
                }
            }
        }
        if(ds<0||dt<0)
            printf("No\n");
        else
        {
            printf("Yes\n");
            for(int i=0; i<ans.size(); i++)
            {
                printf("%d %d\n",E[ans[i]].u,E[ans[i]].v);
            }
        }
    }
    return 0;
}
