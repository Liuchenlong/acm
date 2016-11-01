#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
long long a,b;
double cal(long long len)
{
    if(len==0)
        return b;
    long long num=len/(b*2);
    return (double)len/(2*num);
}
int main()
{

    scanf("%I64d%I64d",&a,&b);
    if(b>a)
        printf("-1\n");
    else
    {
        double ans1=cal(a-b);
        double ans2=cal(a+b);
        printf("%.10f\n",min(ans1,ans2));
    }
    return 0;
}
