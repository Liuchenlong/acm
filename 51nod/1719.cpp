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
#define LL long long
#define pii pair<int,int>
const double pi=acos(-1.0);
int a,b,n;
const double eps=1e-8;
bool zero(double x)
{
    return fabs(x)<=eps;
}
int sign(double x)
{
    if(zero(x))
        return 0;
    if(x>0)
        return 1;
    return -1;
}
double cal(double x)
{
    double ans=0;
    for(int k=1;k<=10000;k++)
    {
        ans+=(sin(x+k)*(1.0*a/(k+sin(k)))+cos(x+k)*(1.0*b/(k+cos(k))));
    }
    return ans;
}
int main()
{

    scanf("%d%d%d",&a,&b,&n);
    double l=0,r=pi;
    bool flag=(sign(cal(0))>=0);
    for(int i=0;i<50;i++)
    {
        double mid=(l+r)/2.0;
        if(cal(mid)>=0)
        {
            if(flag)
                l=mid;
            else
                r=mid;
        }
        else
        {
            if(flag)
                r=mid;
            else
                l=mid;
        }
    }
    double ans=0;
    for(int i=0;i<n;i++)
    {
        ans+=l;
        l+=pi;
    }
    printf("%.3f\n",ans);
    return 0;
}
