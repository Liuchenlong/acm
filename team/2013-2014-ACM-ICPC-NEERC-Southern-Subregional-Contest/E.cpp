#include<bits/stdc++.h>
using namespace std;
const int maxn=1000005;
const int inf=1e9;
int a[maxn];
int g[maxn];
int N=1000002;
int num[1000005];
int lowbit(int x)
{
    return x&(-x);
}
void add(int x,int info)
{
    for(int i=x; i<=N; i+=lowbit(i))
        num[i]+=info;
}
int sum(int x)
{
    int ans=0;
    for(int i=x; i>0; i-=lowbit(i))
        ans+=num[i];
    return ans;
}
struct segtree
{
    int id;
};
segtree seg[maxn*6];
void pushup(int rt)
{
    int lid=seg[rt*2].id;
    int rid=seg[rt*2+1].id;
    if(a[lid]<=a[rid])
        seg[rt].id=lid;
    else
        seg[rt].id=rid;
}
void build(int l,int r,int rt)
{
    if(l==r)
    {
        seg[rt].id=l;
        return ;
    }
    int mid=(l+r)/2;
    build(l,mid,rt*2);
    build(mid+1,r,rt*2+1);
    pushup(rt);
}
void update(int l,int r,int pos,int rt)
{
    if(l==r)
    {
        seg[rt].id=l;
        return ;
    }
    int mid=(l+r)/2;
    if(pos<=mid)update(l,mid,pos,rt*2);
    else update(mid+1,r,pos,rt*2+1);
    pushup(rt);
}
int query(int l,int r,int L,int R,int rt)
{
    if(l>=L&&r<=R)return seg[rt].id;
    int mid=(l+r)/2;
    int ansid=0,ansval=inf+1;
    if(mid>=L)
    {
        int qry=query(l,mid,L,R,rt*2);
        if(a[qry]<ansval)
        {
            ansid=qry;
            ansval=a[qry];
        }
    }
    if(mid+1<=R)
    {
        int qry=query(mid+1,r,L,R,rt*2+1);
        if(a[qry]<ansval)
        {
            ansid=qry;
            ansval=a[qry];
        }
    }
    return ansid;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)scanf("%d",&a[i]);
    long long ans=0;
    for(int i=n; i>0; i--)
    {
        g[i]=sum(a[i]-1);
        ans+=g[i];
        add(a[i],1);
    }
    build(1,n,1);
    printf("%I64d\n",ans);
    for(int i=0; i<m; i++)
    {
        int x;
        scanf("%d",&x);
        if(g[x]==0)
        {
            printf("%I64d\n",ans);
            continue;
        }
        long long tmp=g[x];
        g[x]=0;
        while(1)
        {
            if(x==n)break;
            int pos=query(1,n,x+1,n,1);
            if(a[pos]==inf||a[pos]>a[x])break;
            tmp+=g[pos];
            g[pos]=0;
            a[pos]=inf;
            update(1,n,pos,1);
        }
        a[x]=inf;
        update(1,n,x,1);
        ans-=tmp;
        printf("%I64d\n",ans);
    }
    return 0;
}
