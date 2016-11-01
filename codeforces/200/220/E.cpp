#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
using namespace std;
int pre[4005];
void init()
{
    for(int i=1; i<=4000; i++)
        pre[i]=i;
}
int find(int x)
{
    if(pre[x]!=x)
    {
        pre[x]=find(pre[x]);
    }
    return pre[x];
}
void Union(int x,int y)
{
    int fx=find(x);
    int fy=find(y);
    pre[fx]=fy;
}
struct event
{
    int x,y;
    int t;
    event() {}
    event(int xx,int yy,int tt)
    {
        x=xx;
        y=yy;
        t=tt;
    }
    bool operator <(const event a)const
    {
        if(x==a.x)
        {
            if(y==a.y)
                return t>a.t;
            return y<a.y;
        }
        return x<a.x;
    }
};
event e[4000000+5];
int n,m;
struct point
{
    int x,y;
};
point r[2005],b[2005];
int cal(point a,point b)
{
    int t1=(int)ceil(fabs(b.y+b.x-a.y-a.x)/2.0);
    int t2=(int)ceil(fabs(a.y-a.x-b.y+b.x)/2.0);
    return max(t1,t2);
}
bool cmp(event a,event b)
{
    return a.t<b.t;
}
int main()
{
    init();
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++)scanf("%d%d",&b[i].x,&b[i].y);
    for(int i=0; i<m; i++)scanf("%d%d",&r[i].x,&r[i].y);
    for(int i=0; i<n; i++)for(int j=i+1; j<n; j++)
        {
            if(b[i].x-b[j].x==b[j].y-b[i].y)
                {
                    Union(i,j);
                }
        }
    for(int i=0; i<m; i++)for(int j=i+1; j<m; j++)
        {
            if(r[i].x-r[j].x==r[i].y-r[j].y)
            {
                Union(n+i,n+j);
            }
        }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            e[i*m+j]=event(find(i),find(n+j),cal(b[i],r[j]));
        }
    }
    sort(e,e+n*m);
    vector<event>vec;
    event now=e[0];
    for(int i=1; i<=n*m; i++)
    {
        if(i==n*m)
        {
            vec.push_back(now);
            break;
        }
        else
        {
            if(e[i].x==now.x&&e[i].y==now.y)
            {
                now=e[i];
            }
            else
            {
                vec.push_back(now);
                now=e[i];
            }
        }
    }
    sort(vec.begin(),vec.end(),cmp);
    for(int i=0; i<vec.size(); i++)
    {
        if(find(vec[i].x)==find(vec[i].y))
        {

            printf("%d\n",vec[i].t);
            return 0;
        }
        else
        {
            Union(vec[i].x,vec[i].y);
        }
    }
    printf("Poor Sereja!\n");
    return 0;
}
