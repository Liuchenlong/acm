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
point tubao[10];
int tbnum;
void gettubao(vector <point> p)
{
    int siz=p.size();
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

int main()
{
    point p[4];
    while(1)
    {
        for(int i=0;i<4;i++)p[i].input();
        bool flag=false;
        for(int i=0;i<4;i++)
        {
            if(p[i].x!=-1)
                flag=true;
            if(p[i].y!=-1)
                flag=true;
        }
        if(flag==0)break;
        vector<point>vec;
        for(int i=0;i<4;i++)
        {
            vec.push_back(p[i]);
        }
        gettubao(vec);
        double ans;
        if(tbnum==4)
        {
            ans=0.0;
            point fermat=getnode(getline(tubao[0],tubao[2]),getline(tubao[1],tubao[3]));
            for(int i=0;i<4;i++)ans+=sqrt(dist2(fermat,p[i]));
        }
        else
        {
            ans=1e9;
            for(int i=0;i<4;i++)
            {
                double sum=0.0;
                for(int j=0;j<4;j++)
                {
                    sum+=sqrt(dist2(p[i],p[j]));
                }
                ans=min(ans,sum);
            }
        }
        printf("%.4f\n",ans);
    }
    return 0;
}
