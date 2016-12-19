#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
#define eps 1e-8
int n;
vector<int>son[10005];
int siz[10005];
int fa[10005];
void getdp(int rt)
{
    siz[rt]=1;
    for(int i=0; i<son[rt].size(); i++)
    {
        int nxt=son[rt][i];
        if(fa[rt]==nxt)continue;
        fa[nxt]=rt;
        getdp(nxt);
        siz[rt]+=siz[nxt];
    }
}
bool check(int rt)
{
    if(2*(n-siz[rt])>n)
        return false;
    for(int i=0; i<son[rt].size(); i++)
    {
        int nxt=son[rt][i];
        if(fa[rt]==nxt)continue;
        if(2*siz[nxt]>n)
            return false;
    }
    return true;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        memset(siz,0,sizeof(siz));
        memset(fa,-1,sizeof(fa));
        for(int i=1; i<=n; i++)son[i].clear();
        for(int i=1; i<n; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            son[u].push_back(v);
            son[v].push_back(u);
        }
        getdp(1);
        bool none=true;
        for(int i=1; i<=n; i++)
        {
            if(check(i))
            {
                none=false;
                printf("%d\n",i);
            }
        }
        if(none)
            puts("NONE");
    }
    return 0;
}
