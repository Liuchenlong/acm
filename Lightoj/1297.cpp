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
double w,h;
double cal(double x)
{
    return (w-2*x)*(h-2*x)*x;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {

        scanf("%lf%lf",&w,&h);
        double l=0,r=min(w,h)/2;
        for(int tim=0;tim<100;tim++)
        {
            double mid=(l+r)/2;
            double midmid=(mid+r)/2;
            if(cal(mid)>cal(midmid))
                r=midmid;
            else
                l=mid;
        }
        printf("Case %d: %.10f\n",cas,cal(l));
    }
    return 0;
}
