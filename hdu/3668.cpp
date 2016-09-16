#include<stdio.h>
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
const double pi=acos(-1.0);
bool zero(double x,double eps)
{
    return fabs(x)<=eps;
}
double R,H;
double F2(double x)
{
    return 2.0*min(sqrt(R*R-x*x),H);
}
double simpson2(double L,double R)
{
    double mid=(L+R)/2.0;
    return (F2(L)+4.0*F2(mid)+F2(R))*(R-L)/6.0;
}
double INT2(double L,double R,double eps)
{
    double mid=(L+R)/2.0;
    double sum=simpson2(L,R);
    double sum1=simpson2(L,mid);
    double sum2=simpson2(mid,R);
    if(zero(sum-sum1-sum2,eps))
        return sum;
    else
        return INT2(L,mid,eps)+INT2(mid,R,eps);
}
double F3(double x,double eps)
{
    double l=0,r=sqrt(R*R-x*x);
    return 2.0*INT2(l,r,eps);
}
double simpson3(double L,double R,double eps)
{
    double mid=(L+R)/2.0;
    return (F3(L,eps)+4.0*F3(mid,eps)+F3(R,eps))*(R-L)/6.0;
}
double INT3(double L,double R,double eps)
{
    double mid=(L+R)/2.0;
    double sum=simpson3(L,R,eps);
    double sum1=simpson3(L,mid,eps);
    double sum2=simpson3(mid,R,eps);
    if(zero(sum-sum1-sum2,eps))
        return sum;
    else
        return INT3(L,mid,eps/2.0)+INT3(mid,R,eps/2.0);
}

int main()
{
    while(scanf("%lf%lf",&R,&H)!=EOF)
    {
        H/=2.0;
        double sum=pi*R*R*H*4.0;
        double sum2=2.0*INT3(0,min(R,H),1e-6);
        printf("%.4f\n",sum-sum2);
    }
    return 0;
}
