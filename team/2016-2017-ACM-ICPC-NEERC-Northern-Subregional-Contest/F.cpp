#include <cstdio>
#include <cstring>
#include <map>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
#define eps 1e-8
int inf=1e9;
int cal(int W,int H,int w,int h)
{
    if(W<w||H<h)
        return inf;
    int ans=0;
    while(W>=w*2)
    {
        W=(W+1)/2;
        ans++;
    }
    if(W!=w)ans++;
    while(H>=h*2)
    {
        H=(H+1)/2;
        ans++;
    }
    if(H!=h)
        ans++;
    return ans;
}
int main()
{
    freopen("folding.in","r",stdin);
    freopen("folding.out","w",stdout);
    int W,H,w,h;
    scanf("%d%d%d%d",&W,&H,&w,&h);
    int ans=inf;
    ans=min(ans,cal(W,H,w,h));
    ans=min(ans,cal(W,H,h,w));
    printf("%d\n",ans==inf?-1:ans);
    return 0;
}
