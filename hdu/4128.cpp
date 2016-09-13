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
struct node
{
    int pos;
    long long s,t;
};
node p[10005];
node p2[10005];
int siz;
bool cmp(node a,node b)
{
    if(a.s==b.s)
    {
        return a.t<b.t;
    }
    return a.s<b.s;
}
int n;
long long d,l,w;
int pos1[10005],tl1;
int pos2[10005],tl2;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%I64d%I64d%I64d",&n,&d,&l,&w);
        double ans=0.0;
        for(int i=0; i<n; i++)
        {
            p[i].pos=i;
            scanf("%I64d%I64d",&p[i].s,&p[i].t);
            ans+=d*p[i].t;
            l-=d;
            w-=d*p[i].s;
        }
        siz=0;
        sort(p,p+n,cmp);
        p2[siz++]=p[0];
        for(int i=1;i<n;i++)
        {
            if(p[i].t<p2[siz-1].t)
                p2[siz++]=p[i];
        }
        tl1=0;
        tl2=0;
        for(int i=0;i<siz;i++)
        {
            if(l*p2[i].s<=w)
                pos1[tl1++]=i;
            else
                pos2[tl2++]=i;
        }
        if(l<0||w<0)
        {
            printf("No solution\n");
            continue;
        }
        if(tl1)
        {
            double det=(1LL<<60);
            for(int i=0;i<tl1;i++)
            {
                det=min(det,1.0*l*p2[i].t);
            }
            for(int i=0;i<tl1;i++)for(int j=0;j<tl2;j++)
            {
                int ps1=pos1[i];
                int ps2=pos2[j];
                det=min(det,1.0*((w-l*p2[ps2].s)*p2[ps1].t+(l*p2[ps1].s-w)*p2[ps2].t)/(p2[ps1].s-p2[ps2].s));
            }
            printf("%.2f\n",ans+det);
        }
        else
            printf("No solution\n");
    }
    return 0;
}
