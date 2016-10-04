#include <bits/stdc++.h>
using namespace std;

struct road
{
    int u,v;
    bool use;
    road() {}
    road(int a,int b)
    {
        use=false;
        u=a;
        v=b;
    }
};
int nxt[40002];
int head[202];
road edge[40002];
int tot;
void add(int u,int v)
{
    nxt[tot]=head[u];
    head[u]=tot;
    edge[tot++]=road(u,v);
}

int pre[202];
void init()
{
    tot=0;
    memset(head,-1,sizeof(head));
    memset(nxt,-1,sizeof(nxt));
    for(int i=0; i<202; i++)pre[i]=i;
}
int find(int x)
{
    if(pre[x]!=x)
    {
        int fx=find(pre[x]);
        pre[x]=fx;
    }
    return pre[x];
}
void Union(int x,int y)
{
    int fx=find(x);
    int fy=find(y);
    pre[fx]=fy;
}
vector<int>vec[205];
int d[205];
int que[202];
int tail;
vector<int>ans;

void eular(int cur)
{
    for(int i=head[cur]; i!=-1; i=nxt[i])
    {
        if(edge[i].use)continue;
        ans.push_back(i);
        edge[i].use=edge[i^1].use=true;
        eular(edge[i].v);
    }
}
bool vis[205][205];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(d,0,sizeof(d));
        memset(vis,0,sizeof(vis));
        init();
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++)vec[i].clear();
        for(int i=0; i<m; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            d[a]++;
            d[b]++;
            if(find(a)==find(b));
            else Union(a,b);
            add(a,b);
            add(b,a);
        }

        int sum=0;
        for(int i=1; i<=n; i++)
        {
            if(d[i]%2==0)sum++;
            vec[find(i)].push_back(i);
        }
        printf("%d\n",sum);
        ans.clear();
        for(int i=1; i<=n; i++)
        {
            int siz=vec[i].size();
            if(siz==1)
            {
                continue;
            }
            if(siz)
            {
                tail=0;
                for(int j=0; j<siz; j++)
                {
                    if(d[vec[i][j]]&1)
                        que[tail++]=vec[i][j];
                }
                for(int j=0; j<tail-1; j+=2)
                {
                    vis[que[j]][que[j+1]]=1;
                    vis[que[j+1]][que[j]]=1;
                    add(que[j],que[j+1]);
                    add(que[j+1],que[j]);
                }
                eular(vec[i][0]);
            }
        }
        for(int i=0; i<ans.size(); i++)
        {
            if(ans[i]==-1)continue;
            int u=edge[ans[i]].u;
            int v=edge[ans[i]].v;
            if(vis[u][v])
            {
                vis[u][v]=0;
                vis[v][u]=0;
                continue;
            }
            else
                printf("%d %d\n",u,v);
        }
    }
    return 0;
}
