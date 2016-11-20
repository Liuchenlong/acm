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
int w,p;
point pt[1005];
struct seg
{
    point a,b;
    seg(){}
    seg(point A,point B)
    {
        a=A;
        b=B;
    }
};
seg s[1005];
bool connect[1005][1005];
int dots_inline(point p1,point p2,point p3)
{
    return zero((p2-p1)^(p3-p1));
}
int dot_online_in(point p,point l1,point l2)
{
    return ((l1-p)*(l2-p))<=eps;
}
//判两点在线段异侧,有点在线段上返回0
int opposite_side(point p1,point p2,point l1,point l2)
{
    return (((p1-l1)^(l2-l1))*((p2-l1)^(l2-l1)))<-eps;
}
int intersect_ex(point u1,point u2,point v1,point v2)
{
    return opposite_side(u1,u2,v1,v2)&&opposite_side(v1,v2,u1,u2);
}
bool check(seg a,seg b)
{
    if(intersect_ex(a.a,a.b,b.a,b.b))
        return true;
    if(dots_inline(a.b,b.a,b.b)&&dot_online_in(a.b,b.a,b.b))
        return true;
    if(dots_inline(b.b,a.a,a.b)&&dot_online_in(b.b,a.a,a.b))
        return true;
    return false;
}
int black[1005];
bool vis[1005];
bool bfs(int pos)
{
    vis[pos]=true;
    black[pos]=1;
    queue<int>q;
    q.push(pos);
    while(!q.empty())
    {
        int head=q.front();
        q.pop();
        for(int i=0;i<p;i++)
        {
            if(connect[head][i])
            {
                if(vis[i]==0)
                {
                    vis[i]=1;
                    black[i]=black[head]^1;
                    q.push(i);
                }
                else
                {
                    if(black[i]==black[head])
                        return true;
                }
            }
        }
    }
    return false;
}
int main()
{
    while(scanf("%d%d",&w,&p)!=EOF)
    {
        for(int i=0;i<w;i++)pt[i].input();
        for(int i=0;i<p;i++)
        {
            int pos;
            scanf("%d",&pos);
            s[i].a=pt[pos-1];
            s[i].b.input();
        }
        memset(connect,0,sizeof(connect));
        memset(black,-1,sizeof(black));
        memset(vis,0,sizeof(vis));
        for(int i=0;i<p;i++)
        {
            for(int j=i+1;j<p;j++)
            {
                if(check(s[i],s[j]))
                {
                    connect[i][j]=1;
                    connect[j][i]=1;
                }
            }
        }
        bool ok=true;
        for(int i=0;i<p;i++)
        {
            if(vis[i])continue;
            if(bfs(i))
                ok=false;
        }
        if(ok)
            printf("possible\n");
        else
            printf("impossible\n");
    }
    return 0;
}
