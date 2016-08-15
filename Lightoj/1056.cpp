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
int a,b;
bool check(double x)
{
    double A=x*a;
    double B=x*b;
    double tht=2.0*atan2(b,a);
    double r=sqrt(a*a+b*b)*x/2;
    double d=r*tht;
    return d+A>=200.0;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        scanf("%d : %d",&a,&b);
        double l=0.0,r=100.0;
        for(int tim=0; tim<100; tim++)
        {
            double mid=(l+r)/2.0;
            if(check(mid))
                r=mid;
            else
                l=mid;
        }
        printf("Case %d: %.10f %.10f\n",cas,l*a,l*b);
    }
    return 0;
}
