#include<stdio.h>
#include<cmath>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<set>
#include<vector>
#include<map>
using namespace std;
#define eps 1e-9
const double pi=acos(-1.0);

int n;
struct tree
{
    int x,h;
};
bool cmp(tree a,tree b)
{
    return a.h<b.h;
}
tree t[100005];
int x[100005];
int h[100005];
int lowbit(int x)
{
    return x&(-x);
}
struct BIT
{
    int siz;
    long long a[100005];
    void init(int x)
    {
        siz=x;
        memset(a,0,sizeof(a));
    }
    void add(int x,long long info)
    {
        for(int i=x; i<=siz; i+=lowbit(i))
            a[i]+=info;
    }
    long long qry(int x)
    {
        long long ans=0;
        for(int i=x; i>0; i-=lowbit(i))
            ans+=a[i];
        return ans;
    }
};
BIT b1,b2;
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        map<int,int>mpx,mph;
        for(int i=0; i<n; i++)
        {
            scanf("%d%d",&t[i].x,&t[i].h);
            x[i]=t[i].x;
            h[i]=t[i].h;
        }
        sort(x,x+n);
        sort(h,h+n);
        for(int i=n-1;i>=0;i--)
        {
            mpx[x[i]]=i+1;
            mph[h[i]]=i+1;
        }
        for(int i=0; i<n; i++)
        {
            t[i].x=mpx[t[i].x];
            t[i].h=mph[t[i].h];
        }
        b1.init(n);
        b2.init(n);
        sort(t,t+n,cmp);
        long long ans=0;
        for(int i=n-1; i>=0; i--)
        {
            long long sum=b2.qry(n)-b2.qry(t[i].x);
            long long cnt=b1.qry(n)-b1.qry(t[i].x);
            ans+=(sum-cnt*t[i].x)*t[i].h;
            sum=b2.qry(t[i].x-1);
            cnt=b1.qry(t[i].x-1);
            ans+=(cnt*t[i].x-sum)*t[i].h;
            b1.add(t[i].x,1);
            b2.add(t[i].x,t[i].x);
        }
        printf("%I64d\n",ans);

    }
    return 0;
}
