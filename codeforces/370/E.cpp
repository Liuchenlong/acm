#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
using namespace std;
#define eps 1e-8
const int maxn=100005;
double p[maxn];
struct st
{
    double a;
    double b;
}seg[maxn*4];
void pushup(int rt)
{
    seg[rt].a=seg[rt*2].a*seg[rt*2+1].a;
    seg[rt].b=seg[rt*2].b+seg[rt*2].a*seg[rt*2+1].b;
}
void build(int l,int r,int rt)
{
    if(l==r)
    {
        seg[rt].a=(1-p[l])/p[l];
        seg[rt].b=(1-p[l])/p[l];
        return ;
    }
    int mid=(l+r)/2;
    build(l,mid,rt*2);
    build(mid+1,r,rt*2+1);
    pushup(rt);
}
void update(int l,int r,int rt,int pos)
{
    if(l==r&&l==pos)
    {
        seg[rt].a=(1-p[l])/p[l];
        seg[rt].b=(1-p[l])/p[l];
        return ;
    }
    int mid=(l+r)/2;
    if(pos<=mid)update(l,mid,rt*2,pos);
    else update(mid+1,r,rt*2+1,pos);
    pushup(rt);
}
double querya(int rt,int l,int r,int L,int R)
{
    if(l>=L&&r<=R)
    {
        return seg[rt].a;
    }
    int mid=(l+r)/2;
    if(R<=mid)return querya(rt*2,l,mid,L,R);
    if(L>mid)return querya(rt*2+1,mid+1,r,L,R);
    return querya(rt*2,l,mid,L,R)*querya(rt*2+1,mid+1,r,L,R);
}
double queryb(int rt,int l,int r,int L,int R)
{
    if(l>=L&&r<=R)
    {
        return seg[rt].b;
    }
    int mid=(l+r)/2;
    if(R<=mid)return queryb(rt*2,l,mid,L,R);
    if(L>mid)return queryb(rt*2+1,mid+1,r,L,R);
    return queryb(rt*2,l,mid,L,R)+querya(rt*2,l,mid,L,R)*queryb(rt*2+1,mid+1,r,L,R);
}
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        p[i]=1.0*a/b;
    }
    build(1,n,1);
    for(int i=0;i<q;i++)
    {
        int type;
        scanf("%d",&type);
        if(type==1)
        {
            int x;
            int a,b;
            scanf("%d%d%d",&x,&a,&b);
            p[x]=1.0*a/b;
            update(1,n,1,x);
        }
        else
        {
            int l,r;
            scanf("%d%d",&l,&r);
            double qry=queryb(1,1,n,l,r)+1;
            printf("%.10f\n",1.0/qry);
        }
    }
    return 0;
}
