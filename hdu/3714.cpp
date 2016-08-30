#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
using namespace std;
int n;
double a[10005],b[10005],c[10005];
double cal(double x)
{
    double ans=a[0]*x*x+b[0]*x+c[0];
    for(int i=1;i<n;i++)
    {
        ans=max(ans,a[i]*x*x+b[i]*x+c[i]);
    }
    return ans;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%lf%lf%lf",&a[i],&b[i],&c[i]);
        double L=0,R=1000;
        for(int tim=0;tim<100;tim++)
        {
            double mid=(L+R)/2.0;
            double midmid=(mid+R)/2.0;
            if(cal(mid)<cal(midmid))
                R=midmid;
            else
                L=mid;
        }
        printf("%.4f\n",cal(L));
    }
    return 0;
}
