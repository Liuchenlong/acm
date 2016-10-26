#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;
const double eps=1e-8;
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
double sqr(double x)
{
    return x*x;
}
double dist(double x1,double y1,double x2,double y2)
{
    return sqrt(sqr(x1-x2)+sqr(y1-y2));
}
struct point
{
    double x,y;
    double s,r,d;
    double t;
    void input()
    {
        scanf("%lf%lf%lf%lf%lf",&x,&y,&s,&r,&d);
        t=max((dist(x,y,100,0)-r),0.0);
    }
    bool operator <(const point a)const
    {
        return t<a.t;
    }
};

int n;
point p[105];
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)p[i].input();
        double hp;
        scanf("%lf",&hp);
        double tim=100.0;
        sort(p,p+n);
        for(int i=0;i<n;i++)
        {
            if(sign(p[i].t-tim)<=0)
            {
                hp-=p[i].d;
                tim+=p[i].s;
            }
        }
        if(sign(hp)<=0)
        {
            printf("Danger!\n");
        }
        else
            printf("Safe!\n");
    }
    return 0;
}
