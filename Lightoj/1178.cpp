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
double sqr(double x)
{
    return x*x;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        double a,b,c,d;
        scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
        if(a<c)swap(a,c);
        double h=sqrt(sqr(b)-sqr((sqr(d)-sqr(b)-sqr(a-c))/(2*(a-c))));
        printf("Case %d: %.10f\n",cas,0.5*(a+c)*h);
    }
    return 0;
}
