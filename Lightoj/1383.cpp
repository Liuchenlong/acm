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
struct seg
{
    double l,r;
    bool operator < (const seg &a)const
    {
        if(l==a.l)return r<a.r;
        return l<a.l;
    }
};
seg s[10005];
int k,d;
int n,m;
struct point
{
    double x,y;
};
point p[10005];
bool check(double Y)
{
    for(int i=0;i<n;i++)
    {
        double r=sqrt(d*d-(p[i].y-Y)*(p[i].y-Y));
        s[i].l=p[i].x-r;
        s[i].r=p[i].x+r;
    }
    sort(s,s+n);
    int need=1;
    seg now=s[0];
    for(int i=1;i<n;i++)
    {
        double ll=max(now.l,s[i].l);
        double rr=min(now.r,s[i].r);
        if(rr>=ll)
        {
            now.l=ll;
            now.r=rr;
        }
        else
        {
            need++;
            now=s[i];
        }
    }
    return need<=m;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {

        scanf("%d%d%d%d",&k,&n,&m,&d);
        int dis=0;
        for(int i=0;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            p[i].x=x;
            p[i].y=y;
            dis=max(dis,y-k);
        }
        if(dis>=d)
        {
            printf("Case %d: impossible\n",cas);
            continue;
        }
        bool ok=false;
        int L=1,R=d-dis;
        while(L<R)
        {
            int mid=(L+R+1)/2;
            if(check(k-mid))
            {
                ok=true;
                L=mid;
            }
            else
            {
                R=mid-1;
            }
        }
        if(ok)
            printf("Case %d: %d\n",cas,L);
        else
            printf("Case %d: impossible\n",cas);
    }
    return 0;
}

