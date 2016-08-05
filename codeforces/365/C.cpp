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
#define eps 1e-14
pair<int,int>pr[10005];
int n;
double w,v,u;
double cal(pair<int,int>p)
{
    double U=u/v;
    double d=(double)p.second-U*p.first;
    return -d/U;
}
int main()
{

    scanf("%d%lf%lf%lf",&n,&w,&v,&u);
    for(int i=0;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        pr[i].first=x;
        pr[i].second=y;
    }
    double dl,dr;
    dl=dr=cal(pr[0]);
    for(int i=1;i<n;i++)
    {
        double dd=cal(pr[i]);
        dl=min(dl,dd);
        dr=max(dr,dd);
    }
    if(dl>=0||dr<=0)
        printf("%.10f\n",w/u);
    else
        printf("%.10f\n",dr/v+w/u);
    return 0;
}
