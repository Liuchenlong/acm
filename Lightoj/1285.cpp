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
struct point
{
    int pos;
    int x,y;
    point() {}
    point(int xx,int yy)
    {
        x=xx;
        y=yy;
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
//两点距离平方
int dist2(point p1,point p2)
{
    return (p1-p2)*(p1-p2);
}
bool cmp1(point a,point b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}
point ttt;
bool cmp2(point a,point b)
{
    int s=(a-ttt)^(b-ttt);
    if(s==0)
        return dist2(ttt,a)<dist2(ttt,b);
    return s>0;
}
int n;
point p[2005];
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            p[i].input();
            p[i].pos=i;
        }
        sort(p,p+n,cmp1);
        ttt=p[0];
        sort(p+1,p+n,cmp2);
        printf("Case %d:\n",cas);
        int tmp=0;
        for(int i=n-1; i>0; i--)
        {
            if(((p[n-1]-p[0])^(p[i]-p[0]))==0)
                ;
            else
            {
                tmp=i;
                break;
            }
        }
        if(tmp==0)
        {
            printf("Impossible\n");
        }
        else
        {
            reverse(p+tmp+1,p+n);
            for(int i=0; i<n; i++)
            {
                if(i)printf(" ");
                printf("%d",p[i].pos);
            }
            printf("\n");
        }
    }
    return 0;
}
