#include <cstdio>
#include <cstring>
#include <map>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
#define eps 1e-8
int siz;
struct query
{
    int id;
    int type;
    int l,r;
}q[200005];
int tot;
void add(int l,int r,int type,int pos)
{
    if(l==0||r==0)return ;
    q[tot].l=l;
    q[tot].r=r;
    q[tot].type=type;
    q[tot].id=pos;
    tot++;
}
bool cmp(query a,query b)
{
    if(a.l/siz==b.l/siz)return a.r<b.r;
    return a.l/siz<b.l/siz;
}
int a[50005];
int cnt1[50005];
int cnt2[50005];
long long ans[50005];
void solve()
{
    long long cnt=0;
    int l=1,r=0;
    cnt1[a[1]]++;
    for(int i=0;i<tot;i++)
    {
        while(r<q[i].r)
        {
            r++;
            cnt+=cnt1[a[r]];
            cnt2[a[r]]++;
        }
        while(l>q[i].l)
        {
            cnt-=cnt2[a[l]];
            cnt1[a[l]]--;
            l--;
        }
        while(r>q[i].r)
        {
            cnt-=cnt1[a[r]];
            cnt2[a[r]]--;
            r--;
        }
        while(l<q[i].l)
        {
            l++;
            cnt+=cnt2[a[l]];
            cnt1[a[l]]++;
        }
        ans[q[i].id]+=cnt*q[i].type;
    }
}
int n;
int m;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        int l1,r1,l2,r2;
        scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
        add(r1,r2,1,i);
        add(r1,l2-1,-1,i);
        add(l1-1,r2,-1,i);
        add(l1-1,l2-1,1,i);
    }
    siz=(int)sqrt(tot);
    sort(q,q+tot,cmp);
    solve();
    for(int i=0;i<m;i++)
        printf("%I64d\n",ans[i]);
    return 0;
}
