#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
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
#define eps 1e-8
const int maxn=400005;
int n,m;
vector <int>connect[maxn];
int color[maxn];
int tim;
int L[maxn],R[maxn];
bool vis[maxn];
int pos[2*maxn];
struct segtree
{
    bool flag;
    long long ans;
}seg[8*maxn];
void dfs(int x)
{
    vis[x]=1;
    L[x]=(++tim);
    pos[tim]=x;
    for(int i=0; i<connect[x].size(); i++)
        if(!vis[connect[x][i]])
            dfs(connect[x][i]);
    R[x]=tim;
}
void pushup(int rt)
{
   seg[rt].ans=seg[2*rt].ans|seg[2*rt+1].ans;
}
void pushdown(int rt)
{
    if(seg[rt].flag)
    {
        seg[rt*2].flag=seg[rt*2+1].flag=seg[rt].flag;
        seg[rt*2].ans=seg[rt*2+1].ans=seg[rt].ans;
        seg[rt].flag=0;
    }
}
void build(int l,int r,int rt)
{
    if(l==r)
    {
        seg[rt].flag=0;
        seg[rt].ans=(1LL<<color[pos[l]]);
        return ;
    }
    int mid=(l+r)/2;
    build(l,mid,rt*2);
    build(mid+1,r,rt*2+1);
    pushup(rt);
}
long long query(int l,int r,int L,int R,int rt)
{
    if(l<=L&&R<=r)
    {
        return seg[rt].ans;
    }
    long long ans=0;
    pushdown(rt);
    int mid=(L+R)/2;
    if(l<=mid)
        ans|=query(l,r,L,mid,rt*2);
    if(r>mid)
        ans|=query(l,r,mid+1,R,rt*2+1);
    pushup(rt);
    return ans;
}
void update(int l,int r,int L,int R,int rt,int info)
{
    if(l<=L&&R<=r)
    {
        seg[rt].flag=info;
        seg[rt].ans=(1LL<<info);
        return ;
    }
    pushdown(rt);
    int mid=(L+R)/2;
    if(l<=mid)
        update(l,r,L,mid,rt*2,info);
    if(r>mid)
        update(l,r,mid+1,R,rt*2+1,info);
    pushup(rt);
}
int cal(long long x)
{
    int num=0;
    while(x)
    {
        num+=(x%2);
        x/=2;
    }
    return num;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
        scanf("%d",&color[i]);
    for(int i=0; i<n-1; i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        connect[a].push_back(b);
        connect[b].push_back(a);
    }
    dfs(1);
    build(1,n,1);
    for(int i=0;i<m;i++)
    {
        int type;
        scanf("%d",&type);
        if(type==1)
        {
            int v,c;
            scanf("%d%d",&v,&c);
            update(L[v],R[v],1,n,1,c);
        }
        else
        {
            int v;
            scanf("%d",&v);
            long long ans=query(L[v],R[v],1,n,1);
            printf("%d\n",cal(ans));
        }
    }
    return 0;
}
