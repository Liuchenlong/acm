#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
using namespace std;
const double eps=1e-8;
bool zero(double x)
{
    return fabs(x)<=eps;
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
    void output()
    {
        printf("(%f,%f)\n",x,y);
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
point p[2005];
int n;
void gettubao()
{
    int siz=n;
    memset(tubao,0,sizeof(tubao));
    sort(p,p+n,cmp1);
    for(int i=1; i<siz; i++)
        p[i].tht=atan2(p[i].y-p[0].y,p[i].x-p[0].x);
    ttt=p[0];
    sort(p+1,p+n,cmp2);
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
            if(((tubao[tbnum-1]-tubao[tbnum-2])^(p[i]-tubao[tbnum-2]))<-eps)
            {
                tbnum--;
            }
            else
                break;
        }
        tubao[tbnum++]=p[i];
    }
    for(int i=siz-2,t=tbnum;i>=0;i--)
    {
        while(tbnum>t&&((tubao[tbnum-1]-tubao[tbnum-2])^(p[i]-tubao[tbnum-2]))<-eps)
            tbnum--;
        tubao[tbnum++]=p[i];
    }
    tbnum--;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)p[i].input();
        gettubao();
        int ans=0;
        if(tbnum==1)
        {
            ans=0;
        }
        else if(tbnum==2)
        {
            ans=n-1;
        }
        else
        {
            ans=3*n-3-tbnum;
        }
        if(ans&1)puts("T^T");
        else puts("OwO");
    }
    return 0;
}
