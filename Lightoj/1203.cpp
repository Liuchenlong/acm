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
#define eps 1e-9
const double pi=acos(-1.0);
bool zero(double x)
{
    if(fabs(x)<=eps)
        return 1;
    return 0;
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
double gettht(point p0,point p1,point p2)
{
    return acos((p1-p0)*(p2-p0)/(dist(p0,p1)*dist(p0,p2)));
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        int n;
        scanf("%d",&n);
        vector<point>vec;
        for(int i=0;i<n;i++)
        {
            point t;
            t.input();
            vec.push_back(t);
        }
        gettubao(vec);
        double sum=2*pi;
        if(tbnum<3)
            sum=0;
        else
        for(int i=0;i<tbnum;i++)
        {
            sum=min(sum,gettht(tubao[i],tubao[(i+1)%tbnum],tubao[(i+tbnum-1)%tbnum]));
        }
        printf("Case %d: %.10f\n",cas,sum/pi*180);
    }
    return 0;
}
