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
double pi=acos(-1.0);
double S;
double cal(double r)
{
    double Sres=S-pi*r*r;
    double l=Sres/pi/r;
    double h=sqrt(l*l-r*r);
    return pi*r*r*h/3.0;
}
int main()
{
    scanf("%lf",&S);
    double L=0,R=sqrt((S/2.0)/pi);
    for(int i=0; i<100; i++)
    {
        double mid=(L+R)/2;
        double midmid=(mid+R)/2;
        double vm=cal(mid);
        double vmm=cal(midmid);
        if(vm>vmm)
            R=midmid;
        else
            L=mid;
    }
    printf("%f\n",cal(L));
    return 0;
}
