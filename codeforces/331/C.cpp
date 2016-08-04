#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

#define ABS(a) ((a)<0?-(a):(a))

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
point p[100005];
vector <point> vec[400005];
vector <point> ans;
int w[100005];
int pos[400005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%d",&p[i].x,&p[i].y);
    sort(p,p+n,cmp);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&w[i]);
    }
    for(int i=0;i<n;i++)
    {
        vec[p[i].y-p[i].x+200000].push_back(p[i]);
    }
    int flag=1;
    for(int i=0;i<n;i++)
    {
        if(pos[w[i]+200000]==vec[w[i]+200000].size())
        {
            flag=0;
            break;
        }
        else
            ans.push_back(vec[w[i]+200000][pos[w[i]+200000]++]);
    }
    if(flag)
    {
        for(int i=0;i<n-1;i++)
        {
            if(ans[i].x>=ans[i+1].x&&ans[i].y>=ans[i+1].y)
            {
                flag=0;
                break;
            }
        }
    }
    if(flag)
    {
        printf("YES\n");
        for(int i=0;i<n;i++)
            printf("%d %d\n",ans[i].x,ans[i].y);
    }
    else
        printf("NO\n");
    return 0;
}
