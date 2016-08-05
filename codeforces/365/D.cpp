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
#define eps 1e-12
int n;
int a[1000005];
int lowbit(int x)
{
    return x&(-x);
}
void add(int x,int info)
{
    for(int i=x; i<=n; i+=lowbit(i))
        a[i]^=info;
}
int query(int x)
{
    int ans=0;
    for(int i=x; i>0; i-=lowbit(i))
        ans^=a[i];
    return ans;
}
int num[1000005];
map<int,int>nxt;
struct qry
{
    int id;
    int l,r;
} q[1000005];
int ans[1000005];
bool cmp(qry a,qry b)
{
    return a.l>b.l;
}
int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&num[i]);
    int m;
    scanf("%d",&m);
    for(int i=0; i<m; i++)
    {
        scanf("%d%d",&q[i].l,&q[i].r);
        q[i].id=i;
    }
    sort(q,q+m,cmp);
    int pos=n;
    for(int i=0; i<m; i++)
    {
        while(pos>=q[i].l)
        {
            if(nxt.find(num[pos])==nxt.end())nxt[num[pos]]=pos;
            else
            {
                add(nxt[num[pos]],num[pos]);
                nxt[num[pos]]=pos;
            }
            pos--;
        }
        ans[q[i].id]=query(q[i].r);
    }
    for(int i=0;i<m;i++)
        printf("%d\n",ans[i]);
    return 0;
}
