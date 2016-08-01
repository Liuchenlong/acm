#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
const double pi=acos(-1.0);
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
#define eps 1e-8
int main()
{
    double vp,vd,t,f,c;
    scanf("%lf%lf%lf%lf%lf",&vp,&vd,&t,&f,&c);
    int i=0;
    if(vp>=vd)
    {
        printf("0\n");
        return 0;
    }
    for(;;i++)
    {
        t=t+vp*t/(vd-vp);
        if(vp*t>=c)
            break;
        else
        {
            t+=vp*t/vd;
            t+=f;
        }
    }
    printf("%d\n",i);
    return 0;
}
