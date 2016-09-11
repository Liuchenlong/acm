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
int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int n,q;
int h[100005];
int dp[100005][20];
int mm[100005];
void init()
{
    for(int i=0; i<20; i++)
        for(int j=0; j<n; j++)
        {
            if(i==0)
                dp[j][i]=h[j];
            else if(j+(1<<i)-1<n)
            {
                dp[j][i]=gcd(dp[j][i-1],dp[j+(1<<(i-1))][i-1]);
            }
        }
}
int query(int l,int r)
{
    int two=mm[r-l+1];
    return gcd(dp[l][two],dp[r-(1<<two)+1][two]);
}
struct qry
{
    int pos;
    int l,r;
    bool operator < (const qry &a)const
    {
        return r<a.r;
    }
};
qry Q[100005];
int ans[100005];
int lowbit(int x)
{
    return x&(-x);
}
struct bit
{
    int siz=1000000;
    int a[1000005];
    void init()
    {
        memset(a,0,sizeof(a));
    }
    void add(int x,int info)
    {
        if(x==0)return ;
        for(int i=x;i<=siz;i+=lowbit(i))
            a[i]+=info;
    }
    int sum(int x)
    {
        int ans=0;
        for(int i=x;i>0;i-=lowbit(i))
            ans+=a[i];
        return ans;
    }
}b;
int pl[1000005];
void update(int v,int pos)
{
    if(pl[v]<pos)
    {
        b.add(pl[v],-1);
        b.add(pos,1);
        pl[v]=pos;
    }
}
int main()
{
    mm[0] = -1;
    for(int i = 1; i < 100005; i++)
    {
        if((i & (i - 1)) == 0) mm[i] = mm[i - 1] + 1;
        else mm[i] = mm[i - 1];
    }
    while(scanf("%d%d",&n,&q)!=EOF)
    {
        for(int i=0;i<n;i++)scanf("%d",&h[i]);
        init();
        for(int i=0;i<q;i++)
        {
            Q[i].pos=i;
            scanf("%d%d",&Q[i].l,&Q[i].r);
        }
        sort(Q,Q+q);
        b.init();
        memset(pl,0,sizeof(pl));
        int tail=0;
        for(int i=0;i<n;i++)
        {
            int nowv=h[i];
            update(h[i],i+1);
            int pr=i-1;
            while(pr>=0)
            {
                int L=-1,R=pr;
                bool ok=false;
                while(L<R)
                {
                    int mid=(L+R+1)/2;
                    if(query(mid,i)<nowv)
                    {
                        ok=true;
                        L=mid;
                    }
                    else
                        R=mid-1;
                }
                if(ok)
                {
                    nowv=query(L,i);
                    update(nowv,L+1);
                    pr=L-1;
                }
                else
                    break;
            }
            while(tail<q&&Q[tail].r==i+1)
            {
                ans[Q[tail].pos]=b.sum(b.siz)-b.sum(Q[tail].l-1);
                tail++;
            }
        }
        for(int i=0;i<q;i++)
            printf("%d\n",ans[i]);
    }
    return 0;
}
