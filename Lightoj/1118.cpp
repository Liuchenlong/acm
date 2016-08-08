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
struct point
{
    double x,y;
    void input()
    {
        scanf("%lf%lf",&x,&y);
    }
};
double dist(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double area_of_overlap(point c1, double r1, point c2, double r2)
{
    double a=dist(c1,c2),b=r1,c=r2;
    //相交关系
    if(dist(c1,c2)<r1+r2-eps&&dist(c1,c2)>fabs(r1-r2)+eps)
    {
        double cta1=acos((a*a+b*b-c*c)/2/(a*b));
        double cta2=acos((a*a+c*c-b*b)/2/(a*c));
        double s1=r1*r1*cta1-r1*r1*sin(cta1)*(a*a+b*b-c*c)/2/(a*b);
        double s2=r2*r2*cta2-r2*r2*sin(cta2)*(a*a+c*c-b*b)/2/(a*c);
        return s1+s2;
    }
    //包含及内切
    else if(dist(c1,c2)<=fabs(r1-r2)+eps)
    {
        double big=max(r1,r2);
        double sml=min(r1,r2);
        return pi*sml*sml;
    }
    //相离及外切
    else
        return 0.0;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        point p1,p2;
        double r1,r2;
        p1.input();scanf("%lf",&r1);
        p2.input();scanf("%lf",&r2);
        printf("Case %d: %.10f\n",cas,area_of_overlap(p1,r1,p2,r2));
    }
    return 0;
}
