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
const double pi=acos(-1.0);
bool zero(double x)
{
    return fabs(x)<=eps;
}
int sign(double x)
{
    if(zero(x))
        return 0;
    if(x>0)
        return 1;
    return -1;
}
struct point
{
    double x,y;
    double tht;
    point(){}
    point(double xx,double yy)
    {
        x=xx;
        y=yy;
    }
    void output()
    {
        printf("(%f,%f)\n",x,y);
    }
    void input()
    {
        scanf("%lf%lf",&x,&y);
    }
    point operator -(const point &b)
    {
        return point(x - b.x, y - b.y);
    }
    point operator +(const point &b)
    {
        return point(x + b.x, y + b.y);
    }
    double operator ^(const point &b)
    {
        return x*b.y - y*b.x;
    }
    double operator *(const point &b)
    {
        return x*b.x + y*b.y;
    }
};
double dist(point p1,point p2)
{
    return sqrt((p1-p2)*(p1-p2));
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
    while(T--)
    {
        double L;
        scanf("%lf",&L);
        point O1=point(0,0);
        double R1=L/2.0;
        point O2=point(L/2.0,-L/2.0);
        double R2=L;
        double sum=pi*L*L/4.0;
        sum=sum-area_of_overlap(O1,R1,O2,R2);
        printf("%.2f\n",sum*2.0);
    }
    return 0;
}
