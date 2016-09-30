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
const int maxn=100005;
const int maxm=maxn*30;
int n,q,tot,m;
int a[maxn],lson[maxm],rson[maxm],t[maxn];
int rt[maxm],c[maxm];
void inithash()
{
    for(int i=1;i<=n;i++)t[i]=a[i];
    sort(t+1,t+1+n);
    m=unique(t+1,t+1+n)-t-1;
}
int gethash(int x)
{
    return lower_bound(t+1,t+1+m,x)-t;
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
int update(int root,int pos,int val)
{
    int newroot=tot++,tmp=newroot;
    int l=1,r=m;
    c[newroot]=c[root]+val;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(pos<=mid)
        {
            lson[newroot]=tot++;
            rson[newroot]=rson[root];
            newroot=lson[newroot];
            root=lson[root];
            r=mid;
        }
        else
        {
            lson[newroot]=lson[root];
            rson[newroot]=tot++;
            newroot=rson[newroot];
            root=rson[root];
            l=mid+1;
        }
        c[newroot]=c[root]+val;
    }
    return tmp;
}
int query(int lrt,int rrt,int k)
{
    int l=1,r=m;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(c[lson[rrt]]-c[lson[lrt]]>=k)
        {
            lrt=lson[lrt];
            rrt=lson[rrt];
            r=mid;
        }
        else
        {
            k-=(c[lson[rrt]]-c[lson[lrt]]);
            lrt=rson[lrt];
            rrt=rson[rrt];
            l=mid+1;
        }
    }
    return l;
}
int main()
{
    while(scanf("%d%d",&n,&q)!=EOF)
    {
        tot=0;
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        inithash();
        rt[0]=build(1,m);
        for(int i=1;i<=n;i++)
        {
            int pos=gethash(a[i]);
            rt[i]=update(rt[i-1],pos,1);
        }
        for(int i=0;i<q;i++)
        {
            int l,r,k;
            scanf("%d%d%d",&l,&r,&k);
            printf("%d\n",t[query(rt[l-1],rt[r],k)]);
        }
    }
    return 0;
}
