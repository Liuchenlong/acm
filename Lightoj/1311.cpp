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

int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        double v1,v2,v3,a1,a2;
        scanf("%lf%lf%lf%lf%lf",&v1,&v2,&v3,&a1,&a2);
        double t1=v1/a1;
        double t2=v2/a2;
        double d=v1*t1-0.5*a1*t1*t1+v2*t2-0.5*a2*t2*t2;
        double d2=v3*max(t1,t2);
        printf("Case %d: %.10f %.10f\n",cas,d,d2);
    }
    return 0;
}
