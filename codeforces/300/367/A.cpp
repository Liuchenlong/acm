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

struct point
{
    double x,y;
    void input()
    {
        scanf("%lf%lf",&x,&y);
    }
};
double dist(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
point O;
point p[1005];
double v[1005];
int main()
{
    O.input();
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        p[i].input();
        scanf("%lf",&v[i]);
    }
    double ans=1e9;
    for(int i=0;i<n;i++)
    {
        ans=min(ans,dist(p[i],O)/v[i]);
    }
    printf("%.10f\n",ans);
    return 0;
}
