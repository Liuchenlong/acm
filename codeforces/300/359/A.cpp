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
#define eps 1e-8

int main()
{
    int n;
    long long x;
    scanf("%d%I64d",&n,&x);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        char str[3];
        long long d;
        scanf("%s%I64d",str,&d);
        if(str[0]=='+')
            x+=d;
        else
        {
            if(x>=d)
                x-=d;
            else
                ans++;
        }
    }
    printf("%I64d %d\n",x,ans);
    return 0;
}
