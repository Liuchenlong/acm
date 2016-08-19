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
struct node
{
    int pos;
    int val;
};
struct qry
{
    int l,r;
    int pos;
    int h;
};
bool cmp1(node a,node b)
{
    return a.val<b.val;
}
bool cmp2(qry a,qry b)
{
    return a.h<b.h;
}
const int maxn=100005;
int seg[maxn*4];
void pushup(int rt)
{
    seg[rt]=seg[rt*2]+seg[rt*2+1];
}
void build(int l,int r,int rt)
{
    if(l==r)
    {
        seg[rt]=0;
        return ;
    }
    int mid=(l+r)/2;
    build(l,mid,rt*2);
    build(mid+1,r,rt*2+1);
    pushup(rt);
}
void add(int pos,int l,int r,int rt)
{
    if(l==r&&l==pos)
    {
        seg[rt]++;
        return ;
    }
    int mid=(l+r)/2;
    if(pos<=mid)
        add(pos,l,mid,rt*2);
    if(pos>mid)
        add(pos,mid+1,r,rt*2+1);
    pushup(rt);
}
int query(int L,int R,int l,int r,int rt)
{
    if(L<=l&&R>=r)
        return seg[rt];
    int ans=0;
    int mid=(l+r)/2;
    if(L<=mid)
        ans+=query(L,R,l,mid,rt*2);
    if(R>mid)
        ans+=query(L,R,mid+1,r,rt*2+1);
    return ans;
}
node p[maxn];
qry q[maxn];
int ans[maxn];
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&p[i].val);
            p[i].pos=i+1;
        }
        build(1,n,1);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&q[i].l,&q[i].r,&q[i].h);
            q[i].l++;
            q[i].r++;
            q[i].pos=i;
        }
        sort(p,p+n,cmp1);
        sort(q,q+m,cmp2);
        int pos=0;
        for(int i=0;i<m;i++)
        {
            while(pos<n&&p[pos].val<=q[i].h)
            {
                add(p[pos].pos,1,n,1);
                pos++;
            }
            ans[q[i].pos]=query(q[i].l,q[i].r,1,n,1);
        }
        printf("Case %d:\n",cas);
        for(int i=0;i<m;i++)
            printf("%d\n",ans[i]);
    }
    return 0;
}
