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

int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        double L,n,C;
        scanf("%lf%lf%lf",&L,&n,&C);
        if(fabs(n)<=eps||fabs(C)<=eps||fabs(L)<=eps)
        {
            printf("Case %d: 0\n",cas);
            continue;
        }
        double ll=0,rr=pi/2;
        double tl=L*(1.0+n*C);
        for(int tim=0;tim<100;tim++)
        {
            double mid=(ll+rr)/2;
            double r=(L/2.0)/sin(mid);
            double tL=r*mid*2;
            if(tL>tl)
                rr=mid;
            else
                ll=mid;
        }
        double r=(L/2.0)/sin(ll);
        printf("Case %d: %.10f\n",cas,r-r*cos(ll));
    }
    return 0;
}
