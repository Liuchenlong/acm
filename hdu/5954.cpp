#include <bits/stdc++.h>

using namespace std;
const double pi=acos(-1.0);
double V(double a) {
    return pi*cos(a) - a*cos(a) + sin(a) - pow(sin(a), 3)/3;
}
double cal(double tht)
{
    double a=acos(2*tan(tht)-1);
    return (V(a)-V(pi))/tan(tht);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        double d;
        scanf("%lf",&d);
        if(d>=1)
        {
            double tht=atan(2-d);
            printf("%.5f\n",pi/cos(tht));
        }
        else if(d==0)
        {
            printf("%.5f\n",0);
        }
        else
        {
            double l=0,r=pi/4;
            for(int i=0;i<100;i++)
            {
                double mid=(l+r)/2.0;
                if(cal(mid)>=d*pi)
                    r=mid;
                else
                    l=mid;
            }
            double a=acos(2*tan(l)-1);
            printf("%.5f\n",(pi-a+cos(a)*sin(a))/sin(l));
        }
    }
    return 0;
}
