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
#define eps 1e-8
const double pi=acos(-1.0);
const bool debug = false;
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
    point() {}
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
    point operator /(const double &k)
    {
        return point(x/k,y/k);
    }
    double len()
    {
        return sqrt(x*x+y*y);
    }
};
struct xishu
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
typedef point Vector;
double getdet(point p,Vector to)
{
    if(!zero(to.x))
        return p.x/to.x;
    else
        return p.y/to.y;
}
int dot_online_ex(point p,point l1,point l2)
{
    return ((l1-p)*(l2-p))<-eps;
}
double cald(point O,Vector to,point A,point B)
{
    point O2=O+to;
    if(sign(to^(B-A))==0)return -1;
    else
    {
        point crs=getnode(getline(O,O2),getline(A,B));
        if(dot_online_ex(crs,A,B))
            return getdet(crs-O,to);
        else
            return -1;
    }
}
point rotate_nod(point a,point b,double tht)
{
    point pp1;
    pp1.x=b.x+cos(tht)*(a.x-b.x)-sin(tht)*(a.y-b.y);
    pp1.y=b.y+sin(tht)*(a.x-b.x)+cos(tht)*(a.y-b.y);
    return pp1;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        point O;
        point to;
        O.input();
        to.input();
        Vector vo=to-O;
        vo=vo/vo.len();
        point A,B,C;
        A.input();
        B.input();
        C.input();
        double d[3];
        d[0]=cald(O,vo,A,B);
        d[1]=cald(O,vo,A,C);
        d[2]=cald(O,vo,B,C);
        double n1=1.0,n2;
        scanf("%lf",&n2);
        int pos;
        double det;
        pos=-1;
        det=-1;
        for(int i=0; i<3; i++)if(sign(d[i])==1&&(sign(det)==-1||sign(d[i]-det)==-1))
            {
                pos=i;
                det=d[i];
            }
        if(pos==-1)
        {
            if(sign(vo.y)==-1)
            {
                printf("%.3f\n",O.x-vo.x*(O.y/vo.y));
            }
            else
            {
                printf("Error\n");
            }
        }
        else
        {
            point OO;
            point too;
            Vector voo;
            double tht1;
            double tht2;
            bool left;
            left=false;
            if(pos==0)
            {
                OO=getnode(getline(O,O+vo),getline(A,B));
                tht1=pi/2.0-acos(fabs((OO-O)*(B-A))/(OO-O).len()/(B-A).len());
                point X=rotate_nod(B,OO,pi/2.0);
                if(sign((X-OO)*(O-OO))==-1)
                    X=rotate_nod(X,OO,pi);
                if(sign((X-OO)^(O-OO))==1)
                    left=true;
            }
            if(pos==1)
            {
                OO=getnode(getline(O,O+vo),getline(A,C));
                tht1=pi/2.0-acos(fabs((OO-O)*(C-A))/(OO-O).len()/(C-A).len());
                point X=rotate_nod(C,OO,pi/2.0);
                if(sign((X-OO)*(O-OO))==-1)
                    X=rotate_nod(X,OO,pi);
                if(sign((X-OO)^(O-OO))==1)
                    left=true;
            }
            if(pos==2)
            {
                OO=getnode(getline(O,O+vo),getline(B,C));
                tht1=pi/2.0-acos(fabs((OO-O)*(B-C))/(OO-O).len()/(B-C).len());
                point X=rotate_nod(B,OO,pi/2.0);
                if(sign((X-OO)*(O-OO))==-1)
                    X=rotate_nod(X,OO,pi);
                if(sign((X-OO)^(O-OO))==1)
                    left=true;
            }
            tht2=asin(sin(tht1)*n1/n2);
            if(left)
                too=rotate_nod(O,OO,pi/2.0-tht1+pi/2.0+tht2);
            else
                too=rotate_nod(O,OO,tht1+pi/2.0+pi/2.0-tht2);
            voo=(too-OO);
            voo=voo/voo.len();
            O=OO;
            vo=voo;
            d[0]=cald(O,vo,A,B);
            d[1]=cald(O,vo,A,C);
            d[2]=cald(O,vo,B,C);
            pos=-1;
            det=-1;
            for(int i=0; i<3; i++)if(sign(d[i])==1&&(sign(det)==-1||sign(d[i]-det)==-1))
                {
                    pos=i;
                    det=d[i];
                }
            left=false;
            if(pos==0)
            {
                OO=getnode(getline(O,O+vo),getline(A,B));
                tht1=pi/2.0-acos(fabs((OO-O)*(B-A))/(OO-O).len()/(B-A).len());
                point X=rotate_nod(B,OO,pi/2.0);
                if(sign((X-OO)*(O-OO))==-1)
                    X=rotate_nod(X,OO,pi);
                if(sign((X-OO)^(O-OO))==1)
                    left=true;
            }
            if(pos==1)
            {
                OO=getnode(getline(O,O+vo),getline(A,C));
                tht1=pi/2.0-acos(fabs((OO-O)*(C-A))/(OO-O).len()/(C-A).len());
                point X=rotate_nod(C,OO,pi/2.0);
                if(sign((X-OO)*(O-OO))==-1)
                    X=rotate_nod(X,OO,pi);
                if(sign((X-OO)^(O-OO))==1)
                    left=true;
            }
            if(pos==2)
            {
                OO=getnode(getline(O,O+vo),getline(B,C));
                tht1=pi/2.0-acos(fabs((OO-O)*(B-C))/(OO-O).len()/(B-C).len());
                point X=rotate_nod(B,OO,pi/2.0);
                if(sign((X-OO)*(O-OO))==-1)
                    X=rotate_nod(X,OO,pi);
                if(sign((X-OO)^(O-OO))==1)
                    left=true;
            }
            tht2=asin(sin(tht1)*n2/n1);
            if(left)
                too=rotate_nod(O,OO,pi/2.0-tht1+pi/2.0+tht2);
            else
                too=rotate_nod(O,OO,tht1+pi/2.0+pi/2.0-tht2);
            voo=(too-OO);
            voo=voo/voo.len();
            O=OO;
            vo=voo;
            if(sign(vo.y)==-1)
            {
                printf("%.3f\n",O.x-vo.x*(O.y/vo.y));
            }
            else
            {
                printf("Error\n");
            }
        }
    }
    return 0;
}
