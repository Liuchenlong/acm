#include <cstdio>
#include <cstring>
#include <map>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
#define eps 1e-8
struct obj
{
    int x,y;
    int pos;
};
bool cmp(obj a,obj b)
{
    return a.x<b.x;
}
int n;
obj node[100005];
vector<pair<int,int> >px,py;
bool vis[100005];
int ans[100005];
int rx[100005];
int ry[100005];
int main()
{
    freopen("codecoder.in","r",stdin);
    freopen("codecoder.out","w",stdout);
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        node[i].pos=i;
        scanf("%d%d",&node[i].x,&node[i].y);
        rx[i]=node[i].x;
        ry[i]=node[i].y;
        px.push_back(make_pair(node[i].x,i));
        py.push_back(make_pair(node[i].y,i));
    }
    sort(node,node+n,cmp);
    sort(px.begin(),px.end());
    sort(py.begin(),py.end());
    int minx=0,miny=0;
    int cnt=0;
    int headx=0,heady=0;
    for(int i=0; i<n; i++)
    {
        if(node[i].x<=minx&&node[i].y<=miny)
        {
            ans[node[i].pos]=ans[node[i-1].pos];
            continue;
        }
        else
        {
            if(node[i].x>minx)
            {
                int maxx=node[i].x;
                int maxy=miny;
                while(1)
                {
                    minx=maxx;
                    while(headx<n&&px[headx].first<=minx)
                    {
                        maxy=max(maxy,ry[px[headx].second]);
                        if(!vis[px[headx].second])
                        {
                            vis[px[headx].second]=1;
                            cnt++;
                        }
                        headx++;
                    }
                    if(maxy==miny)break;
                    miny=maxy;
                    while(heady<n&&py[heady].first<=miny)
                    {
                        maxx=max(maxx,rx[py[heady].second]);
                        if(!vis[py[heady].second])
                        {
                            vis[py[heady].second]=1;
                            cnt++;
                        }
                        heady++;
                    }
                    if(maxx==minx)break;
                }
            }
            else
            {
                int maxy=node[i].y;
                int maxx=minx;
                while(1)
                {
                    miny=maxy;
                    while(heady<n&&py[heady].first<=miny)
                    {
                        maxx=max(maxx,rx[py[heady].second]);
                        if(!vis[py[heady].second])
                        {
                            vis[py[heady].second]=1;
                            cnt++;
                        }
                        heady++;
                    }
                    if(maxx==minx)break;
                    minx=maxx;
                    while(headx<n&&px[headx].first<=minx)
                    {
                        maxy=max(maxy,ry[px[headx].second]);
                        if(!vis[px[headx].second])
                        {
                            vis[px[headx].second]=1;
                            cnt++;
                        }
                        headx++;
                    }
                    if(maxy==miny)break;
                }
            }
            ans[node[i].pos]=cnt-1;
        }
    }
    for(int i=0; i<n; i++)
        printf("%d\n",ans[i]);
    return 0;
}
