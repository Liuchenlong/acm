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
const double eps = 1e-15;
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
point p[3005];
int n;
double tht[6006];
int solve(int pos)
{
    int num=0;
    for(int i=0;i<n;i++)
        {
            if(i==pos)
                continue;
            tht[num++]=atan2(p[i].y-p[pos].y,p[i].x-p[pos].x);
        }
    sort(tht,tht+num);
    for(int i=num;i<2*num;i++)
        tht[i]=tht[i-num]+pi*2;
    int ans=9999;
    for(int i=0;i<num;i++)
    {
        int l=i,r=i+num;
        while(l<r)
        {
            int mid=(l+r)/2;
            if(tht[mid]>tht[i]+pi+eps)
                r=mid;
            else
                l=mid+1;
        }
        ans=min(ans,num-(l-i));
    }
    printf("%d\n",ans);

}
int main()
{
//    freopen("C-small-practice.in","r",stdin);
//    freopen("C-small-practice.out","w",stdout);
//    freopen("C-large-practice.in","r",stdin);
//    freopen("C-large-practice.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            p[i].input();
        printf("Case #%d:\n",cas);
        if(n==1)
        {
            printf("0\n");
            continue;
        }
        for(int i=0;i<n;i++)
            solve(i);
    }
    return 0;
}
