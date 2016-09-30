#include<stdio.h>
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
const int maxn=50005;
struct segtree
{
    int l,r;
    int lazy;
    int llen;
    int rlen;
    int tlen;
    int len()
    {
        return r-l+1;
    }
    void update()
    {
        llen=rlen=tlen=(lazy?0:r-l+1);
    }
    void output()
    {
        printf("%d %d\n",l,r);
        printf("\t%d %d %d\n",llen,tlen,rlen);
    }
};
segtree seg[maxn*4];
void pushup(int rt)
{
    seg[rt].tlen=max(seg[rt*2].tlen,seg[rt*2+1].tlen);
    seg[rt].tlen=max(seg[rt].tlen,seg[rt*2].rlen+seg[rt*2+1].llen);
    seg[rt].llen=seg[rt*2].llen+(seg[rt*2].llen==seg[rt*2].len()?seg[rt*2+1].llen:0);
    seg[rt].rlen=seg[rt*2+1].rlen+(seg[rt*2+1].rlen==seg[rt*2+1].len()?seg[rt*2].rlen:0);
}
void build(int l,int r,int rt)
{
    seg[rt].l=l;
    seg[rt].r=r;
    seg[rt].lazy=0;
    if(l==r)
    {
        seg[rt].lazy=0;
        seg[rt].update();
        return ;
    }
    int mid=(l+r)/2;
    build(l,mid,rt*2);
    build(mid+1,r,rt*2+1);
    pushup(rt);
}
void pushdown(int rt)
{
    if(seg[rt].lazy!=-1)
    {
        seg[rt*2].lazy=seg[rt].lazy;
        seg[rt*2].update();
        seg[rt*2+1].lazy=seg[rt].lazy;
        seg[rt*2+1].update();
        seg[rt].lazy=-1;
    }
}
void update(int l,int r,int L,int R,int val,int rt)
{
    if(l>=L&&r<=R)
    {
        seg[rt].lazy=val;
        seg[rt].update();
        return ;
    }
    pushdown(rt);
    int mid=(l+r)/2;
    if(mid>=L)update(l,mid,L,R,val,rt*2);
    if(mid+1<=R)update(mid+1,r,L,R,val,rt*2+1);
    pushup(rt);
}
int query(int l,int r,int w,int rt)
{
    if(l==r&&seg[rt].tlen==w)return l;
    pushdown(rt);
    int mid=(l+r)/2;
    int ans=0;
    if(seg[rt*2].tlen>=w)ans=query(l,mid,w,rt*2);
    else if(seg[rt*2].rlen+seg[rt*2+1].llen>=w)ans=seg[rt*2].r-seg[rt*2].rlen+1;
    else if(seg[rt*2+1].tlen>=w)ans=query(mid+1,r,w,rt*2+1);
    pushup(rt);
    return ans;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    build(1,n,1);
    for(int i=0;i<m;i++)
    {
        int type;
        scanf("%d",&type);
        if(type==1)
        {
            int len;
            scanf("%d",&len);
            int qry=query(1,n,len,1);
            printf("%d\n",qry);
            if(qry)
                update(1,n,qry,qry+len-1,1,1);
        }
        else
        {
            int x,len;
            scanf("%d%d",&x,&len);
            update(1,n,x,x+len-1,0,1);
        }
    }
    return 0;
}
