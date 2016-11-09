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
#define MAX(a,b) ((a)>(b)?(a):(b))
#define ABS(a) ((a)<0?-(a):(a))
#define eps 1e-8
bool zero(double x)
{
    if(fabs(x)<=eps)
        return true;
    return false;
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
    point(double xx=0.0,double yy=0.0)
    {
        x=xx;
        y=yy;
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
struct xishu//直线ax+by+c=0的系数
{
    double a,b,c;
};
//两点距离
double dist(point p1,point p2)
{
    return sqrt((p1-p2)*(p1-p2));
}
xishu getline(point x,point y)
{
    struct xishu w;
    w.a=y.y-x.y;
    w.b=x.x-y.x;
    w.c=y.x*x.y-x.x*y.y;
    return w;
}
int dots_inline(point p1,point p2,point p3)
{
    return zero((p2-p1)^(p3-p1));
}
//先判共线
//判点是否在线段上,包括端点
int dot_online_in(point p,point l1,point l2)
{
    return ((l1-p)*(l2-p))<=eps;
}
point getnode(xishu l1,xishu l2)
{
    point CrossP;
    CrossP.x=(l1.c*l2.b-l1.b*l2.c)/(l1.a*l2.b-l1.b*l2.a)*(-1.0);
    CrossP.y=(l1.c*l2.a-l1.a*l2.c)/(l1.b*l2.a-l1.a*l2.b)*(-1.0);
    return CrossP;
}
point p[1005];
int n;
bool dir(point A,point B)
{
    if(zero(A.x-B.x))
        return A.y<B.y;
    return A.x<B.x;
}
double dist2(point A,point B)
{
    double dis=dist(A,B);
    if(dir(A,B))
        ;
    else
        dis*=-1;
    return dis;
}

bool cross(point l1,point l2,point s1,point s2)
{
    point AB = l2 - l1;
    point AC = s1 - l1;
    point AD = s2 - l1;
    point CD = s2 - s1;

    point vec1=l2-l1;
    point vec2=s2-s1;
    if(ABS(vec1^vec2)<eps)
        return false;
    if ((AB^AC) >= -eps && (AB^AD) >= -eps)
        return false;
    if ((AB^AC) < -eps && (AB^AD) < -eps)
        return false;
    return true;
}
bool collinear(point l1,point l2,point s1,point s2)
{
    if(dots_inline(l1,l2,s1)&&dots_inline(l1,l2,s2))
        return true;
    return false;
}
double solve(point l1,point l2)
{
    vector <double>crs;
    vector <pair<double,double> >seg;
    for(int i=0; i<n; i++)
    {
        int j=i+1;
        if(cross(l1,l2,p[i],p[j]))
        {
            point CROSS=getnode(getline(l1,l2),getline(p[i],p[j]));
            crs.push_back(dist2(l1,CROSS));
        }
        if(collinear(l1,l2,p[i],p[j]))
        {
            double d1=dist2(l1,p[i]);
            double d2=dist2(l1,p[j]);
            if(d1>d2)
                swap(d1,d2);
            seg.push_back(make_pair(d1,d2));
        }
    }
    sort(crs.begin(),crs.end());
    for(int j=0; j+1<crs.size(); j+=2)
        seg.push_back(make_pair(crs[j],crs[j+1]));
    sort(seg.begin(),seg.end());
    double ans=0.0;
    double last=-1e18;
    for(int i=0; i<seg.size(); i++)
    {
        if(seg[i].first>last)
            last=seg[i].first;
        if(seg[i].second>last)
        {
            ans=ans+seg[i].second-last;
            last=seg[i].second;
        }
    }
    return ans;
}
int main()
{
    int k;
    scanf("%d",&n);
    scanf("%d",&k);
    memset(p,0,sizeof(p));
    for(int i=0; i<n; i++)
        p[i].input();
    p[n]=p[0];
    point s1,s2;
    for(int i=0; i<k; i++)
    {
        s1.input();
        s2.input();
        double ans=solve(s1,s2);
        printf("%.12f\n",ans);
    }
    return 0;
}
