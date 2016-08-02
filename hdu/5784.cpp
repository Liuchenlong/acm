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
#define eps 1e-12
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
    long long x,y;
    double tht;
    point() {}
    point(long long xx,long long yy)
    {
        x=xx;
        y=yy;
    }
    void output()
    {
        printf("(%lld,%lld)\n",x,y);
    }
    void input()
    {
        int dx,dy;
        scanf("%d%d",&dx,&dy);
        x=dx;
        y=dy;
    }
    point operator -(const point &b)
    {
        return point(x - b.x, y - b.y);
    }
    point operator +(const point &b)
    {
        return point(x + b.x, y + b.y);
    }
    long long operator ^(const point &b)
    {
        return x*b.y - y*b.x;
    }
    long long operator *(const point &b)
    {
        return x*b.x + y*b.y;
    }
    double len()
    {
        return sqrt(x*x+y*y);
    }
};
bool cmp(point a,point b)
{
    return sign(a.tht-b.tht)==-1;
}
long long gcd(long long a,long long b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int n;
point p[2005];
point p2[4005];
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        long long sum=0;
        long long ans=0;
        for(int i=0;i<n;i++)p[i].input();
        for(int i=0; i<n; i++)
        {
            int num=0;
            for(int j=0; j<n; j++)
            {
                if(i==j)continue;
                p2[num++]=p[j];
            }
            for(int j=0; j<num; j++)
                p2[j].tht=atan2(p2[j].y-p[i].y,p2[j].x-p[i].x);
            sort(p2,p2+num,cmp);
            for(int j=num; j<num+num; j++)
            {
                p2[j]=p2[j-num];
                p2[j].tht+=2*pi;
            }
            int head=0,tail180=0,tail90=0;
            for(int j=0; j<num; j++)
            {
                while(tail90<j+num&&sign(p2[tail90].tht-p2[j].tht-pi/2)==-1)tail90++;
                while(tail180<j+num&&sign(p2[tail180].tht-p2[j].tht-pi)==-1)tail180++;
                while(head<tail90&&sign(p2[head].tht-p2[j].tht)==0)head++;
                ans+=(tail180-tail90);
                sum+=(tail90-head);
            }
        }
        printf("%I64d\n",(sum-ans*2)/3);
    }
    return 0;
}
