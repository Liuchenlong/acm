#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <fstream>
using namespace std;
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) (a<0?-a:a)

#define eps 1e-8
const double pi=acos(-1.0);

struct point
{
    double x,y;
    int pos;
    long double tht;
};
bool cmp(point a,point b)
{
    return a.tht<b.tht;
}
bool cmp2(point a,point b)
{
    return a.tht>b.tht;
}
point p[100005];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lf%lf",&p[i].x,&p[i].y);
        p[i].pos=i;
        p[i].tht=atan2(p[i].y,p[i].x);
    }
    sort(p+1,p+n+1,cmp);
    p[n+1]=p[1];
    p[n+1].tht+=2*pi;
    int pos=1;
    long double ans=999999;
    for(int i=1;i<=n;i++)
    {
        if(p[i+1].tht-p[i].tht<ans)
        {
            ans=p[i+1].tht-p[i].tht;
            pos=i;
        }
    }
    printf("%d %d\n",p[pos].pos,p[pos+1].pos);

    return 0;
}
