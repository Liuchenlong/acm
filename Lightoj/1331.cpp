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
const double pi=acos(-1.0);
double cal(double c,double a,double b)
{
    return acos(-(c*c-a*a-b*b)/(2*a*b));
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        double r1,r2,r3;
        scanf("%lf%lf%lf",&r1,&r2,&r3);
        double tht1=cal(r2+r3,r1+r2,r1+r3);
        double tht2=cal(r1+r3,r2+r1,r2+r3);
        double tht3=cal(r1+r2,r3+r1,r3+r2);
        double sum=0.5*(r1+r2)*(r1+r3)*sin(tht1);
        sum-=tht1*0.5*r1*r1;
        sum-=tht2*0.5*r2*r2;
        sum-=tht3*0.5*r3*r3;
        printf("Case %d: %.10f\n",cas,sum);
    }
    return 0;
}
