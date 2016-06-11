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
#define SIZE 1000005
int main()
{
    int x1,y1,x2,y2;
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    if(x1==x2)
    {
        int d=abs(y1-y2);
        printf("%d %d %d %d\n",x1+d,y1,x2+d,y2);
    }
    else if(y1==y2)
    {
        int d=abs(x1-x2);
        printf("%d %d %d %d\n",x1,y1+d,x2,y2+d);
    }
    else
    {
        int d1=abs(x1-x2);
        int d2=abs(y1-y2);
        if(d1!=d2)
            printf("-1\n");
        else
        {
            printf("%d %d %d %d\n",x1,y2,x2,y1);
        }
    }
    return 0;
}
