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
//bool zero(double x)
//{
//    return fabs(x)<=eps;
//}
int sign(int x)
{
    if(x==0)return 0;
    if(x>0)return 1;
    return -1;
}
struct point
{
    int x,y;
    point(){}
    point(int xx,int yy)
    {
        x=xx;
        y=yy;
    }
    void output()
    {
        printf("(%d,%d)\n",x,y);
    }
    void input()
    {
        scanf("%d%d",&x,&y);
    }
    point operator -(const point &b)
    {
        return point(x - b.x, y - b.y);
    }
    point operator +(const point &b)
    {
        return point(x + b.x, y + b.y);
    }
    int operator ^(const point &b)
    {
        return x*b.y - y*b.x;
    }
    int operator *(const point &b)
    {
        return x*b.x + y*b.y;
    }
};
int dots_inline(point p1,point p2,point p3)
{
    return ((p2-p1)^(p3-p1))==0;
}
int dot_online_in(point p,point l1,point l2)
{
    if(dots_inline(p,l1,l2))
        return ((l1-p)*(l2-p))<=0;
    return 0;
}
int point_inside_polygon(point cp,point p[],int n)
{
    int i,k,d1,d2,wn=0;
  //  double sum=0;
    p[n]=p[0];
    for(i=0;i<n;i++)
    {
        if(dot_online_in(cp,p[i],p[i+1])) return 2;//在边上
        k=sign((p[i+1]-p[i])^(cp-p[i+1]));
        d1=sign(p[i+0].y-cp.y);
        d2=sign(p[i+1].y-cp.y);
        if(k>0&&d1<=0&&d2>0)wn++;
        if(k<0&&d2<=0&&d1>0)wn--;
    }
    //1:在内部
    //0:在外部
    return wn!=0;
}
int n;
point p[333];
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)p[i].input();
        int q;
        scanf("%d",&q);
        printf("Case %d:\n",cas);
        for(int i=0;i<q;i++)
        {
            point chk;
            chk.input();
            if(point_inside_polygon(chk,p,n))
                printf("Yes\n");
            else
                printf("No\n");

        }
    }
    return 0;
}
