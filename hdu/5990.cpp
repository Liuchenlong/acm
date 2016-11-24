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
    if(zero(x))return 0;
    if(x>0)return 1;
    return -1;
}
int n;
double w[100005];
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
    if(zero(a.x-b.x))
        return sign(a.y-b.y)==-1;
    return sign(a.x-b.x)==-1;
}
point ttt;
bool cmp2(point a,point b)
{
    if(zero(a.tht-b.tht))
        return dist2(ttt,a)<dist2(ttt,b);
    return a.tht<b.tht;
}
point tubao[100050];
int tbnum;
point p[100005];
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
pair<double,double>pr[100005];
int main()
{
    int T;
    while(~scanf("%d",&T))
    {
        while(T--)
        {
            scanf("%d",&n);
            for(int i=0; i<n; i++)scanf("%lf",&w[i]);
            double sum=0;
            for(int i=0; i<n; i++)
            {
                sum+=w[i];
                pr[i]=make_pair(w[i],sum);
            }
            for(int i=0; i<n; i++)
                p[i]=(point(pr[i].second/pr[i].first,pr[i].second));
            gettubao();
            double ans=0.0;
            for(int i=0; i<tbnum; i++)
            {
                ans+=((tubao[i]-tubao[0])^(tubao[(i+1)%tbnum]-tubao[0]));
            }
            printf("%.5f\n",fabs(ans)/2.0);
        }
    }
    return 0;
}
