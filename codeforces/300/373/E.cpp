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
const long long mod=1e9+7;
int siz=2;
struct matrix
{
    long long num[3][3];
    matrix()
    {
        memset(num,0,sizeof(num));
    }
    void output()
    {
        for(int i=0;i<siz;i++)
        {
            for(int j=0;j<siz;j++)
                printf("%I64d ",num[i][j]);
            printf("\n");
        }
    }
}E,A,X;
void init()
{
    for(int i=0;i<siz;i++)E.num[i][i]=1;
    A.num[0][1]=1;
    A.num[1][0]=1;
    A.num[1][1]=1;
    X.num[0][0]=0;
    X.num[1][0]=1;
}
matrix add(matrix a,matrix b)
{
    matrix ans;
    for(int i=0;i<siz;i++)
    {
        for(int j=0;j<siz;j++)
        {
            ans.num[i][j]=(a.num[i][j]+b.num[i][j]);
            if(ans.num[i][j]>=mod)
                ans.num[i][j]-=mod;
        }
    }
    return ans;
}
matrix mult(matrix a,matrix b)
{
    matrix ans;
    for(int i=0;i<siz;i++)
    {
        for(int j=0;j<siz;j++)
        {
            for(int k=0;k<siz;k++)
            {
                ans.num[i][j]+=a.num[i][k]*b.num[k][j];
            }
            ans.num[i][j]%=mod;
        }
    }
    return ans;
}
matrix qpow(matrix x,long long k)
{
    matrix ans=E;
    while(k)
    {
        if(k&1)ans=mult(ans,x);
        k>>=1;
        x=mult(x,x);
    }
    return ans;
}
const int maxn=100005;
struct segtree
{
    bool flag;
    matrix sum,lazy;
    void update(matrix up)
    {
        sum=mult(up,sum);
        lazy=mult(up,lazy);
        flag=1;
    }
};
segtree seg[maxn*4];
int a[maxn];
inline void pushup(int rt)
{
    seg[rt].sum=add(seg[rt*2].sum,seg[rt*2+1].sum);
}
inline void build(int l,int r,int rt)
{
    seg[rt].flag=0;
    seg[rt].lazy=E;
    if(l==r)
    {
        seg[rt].sum=mult(qpow(A,a[l]-1),X);
        return ;
    }
    int mid=(l+r)/2;
    build(l,mid,rt*2);
    build(mid+1,r,rt*2+1);
    pushup(rt);
}
inline void pushdown(int rt)
{
    if(seg[rt].flag)
    {
        seg[rt*2].update(seg[rt].lazy);
        seg[rt*2+1].update(seg[rt].lazy);
        seg[rt].flag=0;
        seg[rt].lazy=E;
    }
}
inline void update(int l,int r,int L,int R,matrix info,int rt)
{
    if(l>=L&&r<=R)
    {
        seg[rt].update(info);
        return ;
    }
    pushdown(rt);
    int mid=(l+r)/2;
    if(mid>=L)update(l,mid,L,R,info,rt*2);
    if(mid+1<=R)update(mid+1,r,L,R,info,rt*2+1);
    pushup(rt);
}
inline matrix query(int l,int r,int L,int R,int rt)
{
    if(l>=L&&r<=R)
    {
        return seg[rt].sum;
    }
    pushdown(rt);
    int mid=(l+r)/2;
    matrix ans;
    if(mid>=L)ans=add(ans,query(l,mid,L,R,rt*2));
    if(mid+1<=R)ans=add(ans,query(mid+1,r,L,R,rt*2+1));
    pushup(rt);
    return ans;
}
int main()
{
    init();
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    build(1,n,1);
    for(int i=0;i<m;i++)
    {
        int type;
        scanf("%d",&type);
        if(type==1)
        {
            int l,r,x;
            scanf("%d%d%d",&l,&r,&x);
            update(1,n,l,r,qpow(A,x),1);
        }
        else
        {
            int l,r;
            scanf("%d%d",&l,&r);
            matrix ans=query(1,n,l,r,1);
            printf("%I64d\n",ans.num[1][0]);
        }
    }
    return 0;
}
