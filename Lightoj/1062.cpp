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
        double x,y,c;
        scanf("%lf%lf%lf",&x,&y,&c);
        double l=0.0,r=min(x,y);
        for(int tim=0;tim<100;tim++)
        {
            double mid=(l+r)/2;
            double hl=sqrt(x*x-mid*mid);
            double hr=sqrt(y*y-mid*mid);
            double C=hl*hr/(hl+hr);
            if(C>c)
                l=mid;
            else
                r=mid;
        }
        printf("Case %d: %.10f\n",cas,l);
    }
    return 0;
}
