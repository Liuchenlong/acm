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
int d[1000005];
int n,x;
int main()
{
    scanf("%d%d",&n,&x);
    for(int i=0;i<n;i++)scanf("%d",&d[i]);
    sort(d,d+n);
    if(n==1)
    {
        printf("0\n");
        return 0;
    }
    int pos=upper_bound(d,d+n,x)-d;
    int nr=n-pos;
    int nl=n-nr;
    if(nl==0)printf("%d\n",d[n-2]-x);
    else if(nr==0)printf("%d\n",x-d[1]);
    else
    {
        if(nl==1)
        {
            int ans=min(d[n-1]-x,d[n-2]-d[0]+x-d[0]);
            if(n>2)
                ans=min(ans,min(d[n-2]-d[0]+x-d[0],d[n-2]-d[0]+d[n-2]-x));
            printf("%d\n",ans);
        }
        else if(nr==1)
        {
            int ans=min(d[n-1]-d[1]+d[n-1]-x,x-d[0]);
            if(n>2)
                ans=min(ans,min(d[n-1]-d[1]+x-d[1],d[n-1]-d[1]+d[n-1]-x));
            printf("%d\n",ans);
        }
        else
        {
            int ans=99999999;
            ans=min(ans,min(d[n-1]-d[1]+x-d[1],d[n-1]-d[1]+d[n-1]-x));
            ans=min(ans,min(d[n-2]-d[0]+x-d[0],d[n-2]-d[0]+d[n-2]-x));
            printf("%d\n",ans);
        }
    }
    return 0;
}
