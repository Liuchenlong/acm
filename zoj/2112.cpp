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
const int maxn=60005;
const int maxm=2500010;
int n,q,tot,m;
int a[maxn],lson[maxm],rson[maxm],t[maxn];
int rt[maxn],c[maxm];
int S[maxn];
struct query
{
    int type;
    int l,r,k;
}Q[10010];
void inithash()
{
    sort(t,t+m);
    m=unique(t,t+m)-t;
}
int gethash(int x)
{
    return lower_bound(t,t+m,x)-t;
}
int build(int l,int r)
{
    int root=tot++;
    c[root]=0;
    if(l!=r)
    {
        int mid=(l+r)/2;
        lson[root]=build(l,mid);
        rson[root]=build(mid+1,r);
    }
    return root;
}
int insert(int root,int pos,int val)
{
    int newroot=tot++,tmp=newroot;
    int l=0,r=m-1;
    c[newroot]=c[root]+val;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(pos<=mid)
        {
            lson[newroot]=tot++,rson[newroot]=rson[root];
            newroot=lson[newroot],root=lson[root];
            r=mid;
        }
        else
        {
            rson[newroot]=tot++,lson[newroot]=lson[root];
            newroot=rson[newroot],root=rson[root];
            l=mid+1;
        }
        c[newroot]=c[root]+val;
    }
    return tmp;
}
int use[maxn];
int lowbit(int x)
{
    return x&(-x);
}
int sum(int x)
{
    int ans=0;
    for(int i=x;i>0;i-=lowbit(i))
    {
        ans+=c[lson[use[i]]];
    }
    return ans;
}
int qry(int left,int right,int k)
{
    int lroot=rt[left];
    int rroot=rt[right];
    int l=0,r=m-1;
    for(int i=left;i>0;i-=lowbit(i))use[i]=S[i];
    for(int i=right;i>0;i-=lowbit(i))use[i]=S[i];
    while(l<r)
    {
        int mid=(l+r)/2;
        int tmp=sum(right)-sum(left)+c[lson[rroot]]-c[lson[lroot]];
        if(tmp>=k)
        {
            r=mid;
            for(int i=left;i>0;i-=lowbit(i))use[i]=lson[use[i]];
            for(int i=right;i>0;i-=lowbit(i))use[i]=lson[use[i]];
            lroot=lson[lroot];
            rroot=lson[rroot];
        }
        else
        {
            l=mid+1;
            k-=tmp;
            for(int i=left;i>0;i-=lowbit(i))use[i]=rson[use[i]];
            for(int i=right;i>0;i-=lowbit(i))use[i]=rson[use[i]];
            lroot=rson[lroot];
            rroot=rson[rroot];
        }
    }
    return l;
}
void update(int x,int p,int d)
{
    for(int i=x;i<=n;i+=lowbit(i))
    {
        S[i]=insert(S[i],p,d);
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        scanf("%d%d",&n,&q);
        tot=0;
        m=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            t[m++]=a[i];
        }
        for(int i=0;i<q;i++)
        {
            char str[12];
            scanf("%s",str);
            if(str[0]=='Q')
            {
                Q[i].type=0;
                scanf("%d%d%d",&Q[i].l,&Q[i].r,&Q[i].k);
            }
            else
            {
                Q[i].type=1;
                scanf("%d%d",&Q[i].l,&Q[i].r);
                t[m++]=Q[i].r;
            }
        }
        inithash();
        rt[0]=build(0,m-1);
        for(int i=1;i<=n;i++)
            rt[i]=insert(rt[i-1],gethash(a[i]),1);
        for(int i=1;i<=n;i++)
            S[i]=rt[0];
        for(int i=0;i<q;i++)
        {
            if(Q[i].type==0)
                printf("%d\n",t[qry(Q[i].l-1,Q[i].r,Q[i].k)]);
            else
            {
                update(Q[i].l,gethash(a[Q[i].l]),-1);
                update(Q[i].l,gethash(Q[i].r),1);
                a[Q[i].l]=Q[i].r;
            }
        }
    }
    return 0;
}
