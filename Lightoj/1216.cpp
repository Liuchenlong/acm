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
struct cube
{
    int l[3];
    int r[3];
    void input()
    {
        for(int i=0;i<3;i++)scanf("%d",&l[i]);
        for(int i=0;i<3;i++)scanf("%d",&r[i]);
    }
};
cube c[105];
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        double r1,r2,h,p;
        scanf("%lf%lf%lf%lf",&r1,&r2,&h,&p);
        double x=h*r2/(r1-r2);
        double r3=r2*(x+p)/x;
        double ans=pi*(r2*r2+r3*r3+r2*r3)*p/3.0;
        printf("Case %d: %.10f\n",cas,ans);
    }
    return 0;
}
