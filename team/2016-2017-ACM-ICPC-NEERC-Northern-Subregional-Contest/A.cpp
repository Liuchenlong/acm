#include <cstdio>
#include <cstring>
#include <map>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
#define eps 1e-8
int w,h;
int ax,ay;
int bx,by;
int main()
{
    freopen("anniversary.in","r",stdin);
    freopen("anniversary.out","w",stdout);
    scanf("%d%d",&w,&h);
    scanf("%d%d",&ax,&ay);
    scanf("%d%d",&bx,&by);
    if(ay!=by)
        printf("%d %d %d %d\n",0,min(ay,by),w,max(ay,by));
    else
        printf("%d %d %d %d\n",min(ax,bx),0,max(ax,bx),h);
    return 0;
}
