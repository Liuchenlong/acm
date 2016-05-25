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
bool zero(double x)
{
    return fabs(x)<=eps;
}
int sign(double x)
{
    if(zero(x))return 0;
    if(x>0)return 1;
    return -1;
}
int n;
double V,X;
struct water
{
    double c;
    double r;
};
bool cmp(water a,water b)
{
    return a.c<b.c;
}
water p[102];
int main()
{
//    freopen("B-small-practice.in","r",stdin);
//    freopen("B-small-practice.out","w",stdout);
//    freopen("B-large-practice.in","r",stdin);
//    freopen("B-large-practice.out","w",stdout);
//    freopen("data.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        scanf("%d%lf%lf",&n,&V,&X);
        for(int i=0;i<n;i++)
            scanf("%lf%lf",&p[i].r,&p[i].c);
        sort(p,p+n,cmp);
        printf("Case #%d: ",cas);
        if(sign(p[0].c-X)==1||sign(p[n-1].c-X)==-1)
            printf("IMPOSSIBLE\n");
        else if(sign(p[0].c-X)==0||sign(p[n-1].c-X)==0)
        {
            double v=0.0;
            for(int i=0;i<n;i++)
            {
                if(sign(p[i].c-X)==0)
                    v+=p[i].r;
            }
            printf("%.10f\n",V/v);
        }
        else
        {
            double v=0.0;
            double heat=0.0;
            for(int i=0;i<n;i++)
            {
                v+=p[i].r;
                heat+=p[i].r*p[i].c;
            }
            if(sign(heat-v*X)==1)
            {
                for(int i=n-1;i>=0;i--)
                {
                    if(sign(heat-p[i].r*p[i].c-X*(v-p[i].r))!=1)
                    {
                        double dv=(heat-X*v)/(p[i].c-X);
                        v-=dv;
                        break;
                    }
                    heat-=p[i].r*p[i].c;
                    v-=p[i].r;
                }
                printf("%.10f\n",V/v);
            }
            else
            {
                for(int i=0;i<n;i++)
                {
                    if(sign(heat-p[i].r*p[i].c-X*(v-p[i].r))!=-1)
                    {
                        double dv=(heat-X*v)/(p[i].c-X);
                        v-=dv;
                        break;
                    }
                    heat-=p[i].r*p[i].c;
                    v-=p[i].r;
                }
                printf("%.10f\n",V/v);
            }
        }
    }
    return 0;
}
