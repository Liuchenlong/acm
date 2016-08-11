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

double v[100005];
double x[100005];
double d[100005];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        double C;
        scanf("%d%lf",&n,&C);
        for(int i=0;i<n;i++)
            scanf("%lf%lf%lf",&v[i],&x[i],&d[i]);
        sort(v,v+n);
        int q;
        scanf("%d",&q);
        for(int i=0;i<q;i++)
        {
            double t;
            int k;
            scanf("%lf%d",&t,&k);
            k--;
            printf("%.3f\n",sqrt(v[k]*v[k]+2.0*C*t));
        }
    }
    return 0;
}
