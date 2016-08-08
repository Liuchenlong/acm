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
    long double x,y;
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
        double X,Y;
        scanf("%lf%lf",&X,&Y);
        x=X;
        y=Y;
    }
    point operator -(const point &b)
    {
        return point(x - b.x, y - b.y);
    }
    point operator +(const point &b)
    {
        return point(x + b.x, y + b.y);
    }
    long double operator ^(const point &b)
    {
        return x*b.y - y*b.x;
    }
    long double operator *(const point &b)
    {
        return x*b.x + y*b.y;
    }
};

long double dist(point p1,point p2)
{
    return sqrt((p1-p2)*(p1-p2));
}

long double gettht(point p0,point p1,point p2)
{
    return acos((p1-p0)*(p2-p0)/(dist(p0,p1)*dist(p0,p2)));
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        point O,A,B;
        O.input();
        A.input();
        B.input();
        long double r=dist(O,A);
        long double tht=gettht(O,A,B);
        tht=min(tht,2*pi-tht);
        printf("Case %d: %.10f\n",cas,(double)(tht*r));
    }
    return 0;
}
