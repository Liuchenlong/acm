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
#define eps 1e-12
const double pi=acos(-1.0);

int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        int m;
        scanf("%d",&m);
        printf("Case %d:\n",cas);
        for(int i=0;i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if(x>=x1&&x<=x2&&y>=y1&&y<=y2)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}
