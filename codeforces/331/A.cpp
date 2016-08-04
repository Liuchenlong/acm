#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

#define ABS(a) ((a)<0?-(a):(a))

int main()
{
    int x[4];
    int y[4];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%d",&x[i],&y[i]);
    if(n==1)
        printf("-1\n");
    else if(n==2)
    {
        if(x[0]==x[1]||y[0]==y[1])
            printf("-1\n");
        else
        {
            printf("%d\n",ABS((x[1]-x[0])*(y[1]-y[0])));
        }
    }
    else
    {
        int maxx=max(x[0],max(x[1],x[2]));
        int minx=min(x[0],min(x[1],x[2]));
        int maxy=max(y[0],max(y[1],y[2]));
        int miny=min(y[0],min(y[1],y[2]));
        
        printf("%d\n",(maxx-minx)*(maxy-miny));
    }

    return 0;
}
