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

int main()
{
    int t,x,s;
    scanf("%d%d%d",&t,&s,&x);
    if(x<t)
    {
        printf("NO\n");
    }
    else
    {
        int res=x-t;
        if(res%s==0||(res%s==1&&res>s))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
