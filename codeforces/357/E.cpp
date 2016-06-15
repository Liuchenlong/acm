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
#define eps 1e-12
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
    point operator *(const double &b)
    {
        return point(b*x,b*y);
    }
};
double dist(point p1,point p2)
{
    return sqrt((p1-p2)*(p1-p2));
}
struct xishu//直线ax+by+c=0的系数
{
    double a,b,c;
};
xishu getline(point x,point y)
{
    struct xishu w;
    w.a=y.y-x.y;
    w.b=x.x-y.x;
    w.c=y.x*x.y-x.x*y.y;
    return w;
}
point getnode(xishu l1,xishu l2)
{
    point CrossP;
    CrossP.x=(l1.c*l2.b-l1.b*l2.c)/(l1.a*l2.b-l1.b*l2.a)*(-1.0);
    CrossP.y=(l1.c*l2.a-l1.a*l2.c)/(l1.b*l2.a-l1.a*l2.b)*(-1.0);
    return CrossP;
}
void intersection_line_circle(point c,double r,point l1,point l2,point &p1,point &p2)
{
    point p=c;
    double t;
    p.x+=l1.y-l2.y;
    p.y+=l2.x-l1.x;
    p=getnode(getline(p,c),getline(l1,l2));
    t=sqrt(r*r-dist(p,c)*dist(p,c))/dist(l1,l2);
    p1.x=p.x+(l2.x-l1.x)*t;
    p1.y=p.y+(l2.y-l1.y)*t;
    p2.x=p.x-(l2.x-l1.x)*t;
    p2.y=p.y-(l2.y-l1.y)*t;
}
void intersection_circle_circle(point c1,double r1,point c2,double r2,point& p1,point& p2)
{
    point u,v;
    double t;
    t=(1+(r1*r1-r2*r2)/dist(c1,c2)/dist(c1,c2))/2;
    u.x=c1.x+(c2.x-c1.x)*t;
    u.y=c1.y+(c2.y-c1.y)*t;
    v.x=u.x+c1.y-c2.y;
    v.y=u.y-c1.x+c2.x;
    intersection_line_circle(c1,r1,u,v,p1,p2);
}
int n;
point p[100005];
double R[100005];
point O;
vector<pair<double,double> >vec;
vector<pair<double,double> >ans;
int main()
{
    O.input();
    double v,t;
    scanf("%lf%lf",&v,&t);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        p[i].input();
        scanf("%lf",&R[i]);
        p[i]=p[i]-O;
    }
    O=O-O;
    double r=v*t;
    for(int i=0;i<n;i++)
    {
        if(sign(dist(O,p[i])-R[i])<=0)
        {
            printf("1.00000000000\n");
            return 0;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(sign(dist(O,p[i])-r-R[i])>=0)
            ;
        else if(sign(dist(O,p[i])-fabs(r-R[i]))<=0)
        {
            double tht=atan2(p[i].y,p[i].x);
            double tht2=(pi/2.0)-acos(R[i]/dist(O,p[i]));
            vec.push_back(make_pair(tht-tht2,tht+tht2));
        }
        else
        {
            vector<double>tmp;
            double tht=atan2(p[i].y,p[i].x);
            double tht2=(pi/2.0)-acos(R[i]/dist(O,p[i]));
            point p1=O+point(cos(tht-tht2),sin(tht-tht2))*r;
            if(sign((p1-O)*(p[i]-p1))<=0)
            {
                if(tht-tht2<-pi)
                    tmp.push_back(tht-tht2+2*pi);
                else
                    tmp.push_back(tht-tht2);
            }
            p1=O+point(cos(tht+tht2),sin(tht+tht2))*r;
            if(sign((p1-O)*(p[i]-p1))<=0)
            {
                if(tht+tht2>pi)
                    tmp.push_back(tht+tht2-2*pi);
                else
                    tmp.push_back(tht+tht2);
            }

            point pc1,pc2;
            intersection_circle_circle(O,r,p[i],R[i],pc1,pc2);
            tmp.push_back(atan2(pc1.y,pc1.x));
            tmp.push_back(atan2(pc2.y,pc2.x));
            sort(tmp.begin(),tmp.end());
            double L=tmp[0],R=tmp[tmp.size()-1];
            double tl=L,tr=R;
            if(R-L>pi)
            {
                for(int j=0;j<tmp.size();j++)
                {
                    if(tmp[j]>0)
                        tr=min(tr,tmp[j]);
                    else
                        tl=max(tl,tmp[j]);
                }
                vec.push_back(make_pair(-pi,tl));
                vec.push_back(make_pair(tr,pi));
            }
            else
            {
                vec.push_back(make_pair(L,R));
            }
        }
    }
    for(int i=0;i<vec.size();i++)
    {
        pair<double,double>pr=vec[i];
        double l=pr.first;
        double r=pr.second;
        if(l<-pi)
        {
            ans.push_back(make_pair(l+2*pi,pi));
            l=-pi;
        }
        if(r>pi)
        {
            ans.push_back(make_pair(-pi,r-2*pi));
            r=pi;
        }
        ans.push_back(make_pair(l,r));
    }
    sort(ans.begin(),ans.end());
    double sum=0.0;
    double L=0,R=0;
    for(int i=0;i<=ans.size();i++)
    {
        if(i==ans.size())
        {
            sum+=R-L;
            break;
        }

        else if(i==0)
        {
            L=ans[i].first;
            R=ans[i].second;
        }
        else
        {
            if(sign(ans[i].first-R)<=0)
                R=max(R,ans[i].second);
            else
            {
                sum+=R-L;
                L=ans[i].first;
                R=ans[i].second;
            }
        }
    }
    printf("%.10f\n",sum/(2*pi));
    return 0;
}
