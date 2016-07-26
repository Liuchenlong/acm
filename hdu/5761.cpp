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
bool zero(double x)
{
    return fabs(x)<=eps;
}
int sign(double x)
{
    if(zero(x))return 0;
    if(x>0)return 1;
    return -1;
}
int main()
{
    double a,v1,v2;
    while(scanf("%lf%lf%lf",&a,&v1,&v2)!=EOF)
    {
        if(zero(a))
        {
            printf("0.000000\n");
            continue;
        }
        if(v1<=v2)
        {
            printf("Infinity\n");
            continue;
        }
        printf("%f\n",a*v1/(v1*v1-v2*v2));
    }
    return 0;
}
