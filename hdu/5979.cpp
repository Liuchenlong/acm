#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
#define eps 1e-8
const double pi=acos(-1.0);
int n,d;
double tht[15];
int main()
{
    while(scanf("%d%d",&n,&d)!=EOF)
    {
        double ans=0;
        for(int i=0;i<n;i++)
        {
            scanf("%lf",&tht[i]);
            tht[i]=tht[i]/180.0*pi;
            ans+=0.5*d*d*sin(tht[i]);
        }
        printf("%.3f\n",ans);
    }
    return 0;
}
