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

map<pair<int,int>,int >mp;
struct point
{
    int x,y;
};
bool cmp(point a,point b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}
point p[2005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&p[i].x,&p[i].y);
    }
    sort(p,p+n,cmp);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            ans+=mp[make_pair(p[j].x-p[i].x,p[j].y-p[i].y)];
            mp[make_pair(p[j].x-p[i].x,p[j].y-p[i].y)]++;
        }
    }
    printf("%d\n",ans/2);
    return 0;
}
