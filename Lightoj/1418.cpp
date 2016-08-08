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
    long long x,y;
    point(){}
    point(long long xx,long long yy)
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
        scanf("%lld%lld",&x,&y);
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
};
long long gcd(long long a,long long b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
point p[10005];
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)p[i].input();
        long long sum=0;
        for(int i=1;i<n-1;i++)
        {
            sum+=(p[i]-p[0])^(p[(i+1)%n]-p[0]);
        }
        sum=abs(sum)/2;
        sum++;
        long long res=0;
        for(int i=0;i<n;i++)
        {
            long long dx=(p[(i+1)%n]-p[i]).x;
            long long dy=(p[(i+1)%n]-p[i]).y;
            dx=abs(dx);
            dy=abs(dy);
            res+=gcd(dx,dy);
        }
        sum-=res/2;
        printf("Case %d: %lld\n",cas,sum);
    }
    return 0;
}
