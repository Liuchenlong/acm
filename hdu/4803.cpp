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
#include<bitset>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
int x,y;
int main()
{
    while(scanf("%d%d",&x,&y)!=EOF)
    {
        int ans=x-1;
        if(y<x)
        {
            printf("-1\n");
            continue;
        }
        ans+=(y/x-1);
        double val=y/x;
        for(int i=2;i<=x;i++)
        {
            if(y>(int)(x*(val+1.0/i)))
            {
                val+=1.0/i;
                ans++;
                i--;
            }
            else if(y==(int)(x*(val+1.0/i)))
            {
                ans++;
                break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
