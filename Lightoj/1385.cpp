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
    if(fabs(x)<=eps)return 1;
    return 0;
}
int sign(double x)
{
    if(zero(x))return 0;
    if(x>0)return 1;
    return -1;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        double a,b,c;
        scanf("%lf%lf%lf",&b,&a,&c);
        double d1,d2;
        d2=(a*b*c+b*c*c)/(a*a-b*c);
        d1=(b*c+b*d2)/a;
        double ans=d1+d2;
        if(sign(a*a-b*c)<=0)
            ans=-1;
        printf("Case %d: %.10f\n",cas,ans);
    }
    return 0;
}
