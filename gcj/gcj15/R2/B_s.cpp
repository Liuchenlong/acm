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
water p[102];
int main()
{
    freopen("B-small-practice.in","r",stdin);
    freopen("B-small-practice.out","w",stdout);
//    freopen("A-large-practice.in","r",stdin);
//    freopen("A-large-practice.out","w",stdout);
//    freopen("data.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        scanf("%d%lf%lf",&n,&V,&X);
        for(int i=0;i<n;i++)
            scanf("%lf%lf",&p[i].r,&p[i].c);
        printf("Case #%d: ",cas);
        if(n==1)
        {
            if(zero(p[0].c-X))
            {
                printf("%.10f\n",V/p[0].r);
            }
            else
                printf("IMPOSSIBLE\n");
        }
        else
        {
            if(sign(p[0].c-p[1].c)==1)
                swap(p[0],p[1]);
            if(sign(p[0].c-X)==1||sign(p[1].c-X)==-1)
                printf("IMPOSSIBLE\n");
            else if(sign(p[0].c-X)==0&&sign(p[1].c-X)==0)
            {
                printf("%.10f\n",V/(p[0].r+p[1].r));
            }
            else if(sign(p[0].c-X)==0)
            {
                printf("%.10f\n",V/(p[0].r));
            }
            else if(sign(p[1].c-X)==0)
            {
                printf("%.10f\n",V/(p[1].r));
            }
            else
            {
                double lmd=(X-p[1].c)/(p[0].c-p[1].c);
                double v1=lmd*V;
                double v2=(1-lmd)*V;
                printf("%.10f\n",max(v1/p[0].r,v2/p[1].r));
            }
        }
    }
    return 0;
}
