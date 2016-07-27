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
#define eps 1e-7

const double pi=acos(-1.0);
int main()
{
    int n,R,r;
    scanf("%d%d%d",&n,&R,&r);
    bool flag=false;
    if(r>R)
    {
        flag=false;
    }
    else if(r*2>R)
    {
        if(n<=1)flag=true;
    }
    else if(r*2==R)
    {
        if(n<=2)flag=true;
    }
    else
    {
        double tht=asin(r*1.0/(R-r))*2;
        int maxn=(int)(pi*2/tht+eps);
        if(n<=maxn)flag=true;
    }
    if(flag)printf("YES\n");
    else printf("NO\n");
    return 0;
}
