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
struct point3
{
    double x,y,z;
    point3() {}
    point3(double xx,double yy,double zz)
    {
        x=xx;
        y=yy;
        z=zz;
    }
    void output()
    {
        printf("(%.2f %.2f %.2f)\n",x,y,z);
    }
};
struct line3
{
    point3 a,b;
    line3() {}
    line3(point3 aa,point3 bb)
    {
        a=aa;
        b=bb;
    }
};
struct plane3
{
    point3 a,b,c;
    plane3() {}
    plane3(point3 aa,point3 bb,point3 cc)
    {
        a=aa;
        b=bb;
        c=cc;
    }
    void output()
    {
        printf("{\n");
        a.output();
        b.output();
        c.output();
        printf("}\n");
    }
};
//计算 cross product U x V
point3 xmult(point3 u,point3 v)
{
    point3 ret;
    ret.x=u.y*v.z-v.y*u.z;
    ret.y=u.z*v.x-u.x*v.z;
    ret.z=u.x*v.y-u.y*v.x;
    return ret;
}
//计算 dot product U . V
double dmult(point3 u,point3 v)
{
    return u.x*v.x+u.y*v.y+u.z*v.z;
}
point3 addt(point3 u,point3 v)
{
    point3 ret;
    ret.x=u.x+v.x;
    ret.y=u.y+v.y;
    ret.z=u.z+v.z;
    return ret;
}
//矢量差 U - V
point3 subt(point3 u,point3 v)
{
    point3 ret;
    ret.x=u.x-v.x;
    ret.y=u.y-v.y;
    ret.z=u.z-v.z;
    return ret;
}
//取平面法向量
point3 pvec(plane3 s)
{
    return xmult(subt(s.a,s.b),subt(s.b,s.c));
}
point3 pvec(point3 s1,point3 s2,point3 s3)
{
    return xmult(subt(s1,s2),subt(s2,s3));
}
//两点距离,单参数取向量大小
double dist(point3 p1,point3 p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)+(p1.z-p2.z)*(p1.z-p2.z));
}
//向量大小
double vlen(point3 p)
{
    return sqrt(p.x*p.x+p.y*p.y+p.z*p.z);
}
//计算直线与平面交点 ,注意事先判断是否平行 ,并保证三点不共线!
//线段和空间三角形交点请另外判断
point3 intersection(line3 l,point3 s,double d)
{
    point3 ret=s;
    double t=(d-dmult(ret,l.a))/(dmult(ret,subt(l.b,l.a)));
    ret.x=l.a.x+(l.b.x-l.a.x)*t;
    ret.y=l.a.y+(l.b.y-l.a.y)*t;
    ret.z=l.a.z+(l.b.z-l.a.z)*t;
    return ret;
}
//点到平面距离
double ptoplane(point3 p,plane3 s)
{
    return fabs(dmult(pvec(s),subt(p,s.a)))/vlen(pvec(s));
}
point3 get(double a,double b,double c,double d)
{
    point3 A,B,C;
    if(zero(a))
    {
        A.x=rand();
        B.x=rand();
        C.x=rand();
        if(zero(b))
        {
            A.y=rand();
            B.y=rand();
            C.y=rand();
            A.z=(d-a*A.x-b*A.y)/c;
            B.z=(d-a*B.x-b*B.y)/c;
            C.z=(d-a*C.x-b*C.y)/c;
        }
        else
        {
            A.z=rand();
            B.y=rand();
            C.y=rand();
            A.y=(d-a*A.x-c*A.z)/b;
            B.y=(d-a*B.x-c*B.z)/b;
            C.y=(d-a*C.x-c*C.z)/b;
        }
    }
    else
    {
        A.y=rand();
        B.y=rand();
        C.y=rand();
        A.z=rand();
        B.y=rand();
        C.y=rand();
        A.x=(d-b*A.y-c*A.z)/a;
        B.x=(d-b*B.y-c*B.z)/a;
        C.x=(d-b*C.y-c*C.z)/a;
    }
    return A;
}
int n;
point3 p[105];
point3 pv[105];
point3 rot(double x,double y,double z,double d,point3 now)
{
    double l=sqrt(x*x+y*y+z*z);
    if(zero(l))
        return now;
    x/=l;
    y/=l;
    z/=l;
    point3 ans;
    ans.x=(x*x+(1.0-x*x)*cos(d))*now.x+(x*y*(1.0-cos(d))-z*sin(d))*now.y+(x*z*(1.0-cos(d))+y*sin(d))*now.z;
    ans.y=(x*y*(1.0-cos(d))+z*sin(d))*now.x+(y*y+(1.0-y*y)*cos(d))*now.y+(y*z*(1.0-cos(d))-x*sin(d))*now.z;
    ans.z=(x*z*(1.0-cos(d))-y*sin(d))*now.x+(y*z*(1.0-cos(d))+x*sin(d))*now.y+(z*z+(1.0-z*z)*cos(d))*now.z;
    return ans;
}

struct point
{
    double x,y;
    double tht;
    point() {}
    point(double xx,double yy)
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
//两点距离
double dist(point p1,point p2)
{
    return sqrt((p1-p2)*(p1-p2));
}
//两点距离平方
double dist2(point p1,point p2)
{
    return (p1-p2)*(p1-p2);
}
bool cmp1(point a,point b)
{
    if(a.y==b.y)
        return a.x<b.x;
    return a.y<b.y;
}
point ttt;
bool cmp2(point a,point b)
{
    if(zero(a.tht-b.tht))
        return dist2(ttt,a)<dist2(ttt,b);
    return a.tht<b.tht;
}
point tubao[50050];
int tbnum;

void gettubao(vector <point> p)
{
    int siz=p.size();
    if(siz==0)
    {
        tbnum=0;
        return ;
    }
    memset(tubao,0,sizeof(tubao));
    sort(p.begin(),p.end(),cmp1);
    for(int i=1; i<siz; i++)
        p[i].tht=atan2(p[i].y-p[0].y,p[i].x-p[0].x);
    ttt=p[0];
    sort(++p.begin(),p.end(),cmp2);
    if(siz==1)
    {
        tbnum=1;
        tubao[0]=p[0];
        return ;
    }
    else if(siz==2)
    {
        tbnum=2;
        tubao[0]=p[0];
        tubao[1]=p[1];
        return ;
    }
    tbnum=2;
    tubao[0]=p[0];
    tubao[1]=p[1];
    for(int i=2; i<siz; i++)
    {
        while(tbnum>1)
        {
            if(((tubao[tbnum-1]-tubao[tbnum-2])^(p[i]-tubao[tbnum-2]))<=eps)
            {
                tbnum--;
            }
            else
                break;
        }
        tubao[tbnum++]=p[i];
    }
}
point3 p2[101];
int tot;
bool check(point3 v,point3 v2)
{
    if(sign(dmult(v,v2))==-1)return false;
    return true;
}
int main()
{
    srand(time(NULL));
    while(1)
    {
        double a,b,c,d;
        scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
        point3 p3d_O=get(a,b,c,d);
        if(zero(a)&&zero(b)&&zero(c)&&zero(d))
            break;
        scanf("%d",&n);
        for(int i=0; i<n; i++)scanf("%lf%lf%lf",&p[i].x,&p[i].y,&p[i].z);
        point3 O;
        scanf("%lf%lf%lf",&O.x,&O.y,&O.z);

        point3 p3d_v=point3(a,b,c);
        tot=0;
        for(int i=0; i<n; i++)
        {
            if(zero(dmult(subt(p[i],O),p3d_v)))continue;
            point3 crs=intersection(line3(O,p[i]),p3d_v,d);
            if(check(subt(p[i],O),subt(crs,O)))
                p2[tot++]=crs;
        }
        if(!tot) puts("0.00");
        else if(tot < n) puts("Infi");
        else
        {
            point3 axis=xmult(p3d_v,point3(0,0,1));
            double tht=acos(p3d_v.z/vlen(p3d_v));
            for(int i=0; i<n; i++)
                p2[i]=rot(axis.x,axis.y,axis.z,tht,subt(p2[i],O));
            vector<point>vec;
            for(int i=0; i<n; i++)vec.push_back(point(p2[i].x,p2[i].y));
            gettubao(vec);
            double ans=0;
            for(int i=1; i<tbnum; i++)
                ans+=(tubao[i]-tubao[0])^(tubao[(i+1)%tbnum]-tubao[0]);
            printf("%.2f\n",fabs(ans)/2.0);
        }
    }
    return 0;
}
