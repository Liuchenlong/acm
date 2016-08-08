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
#define eps 1e-12
const double pi=acos(-1.0);

int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        double R;
        int n;
        scanf("%lf%d",&R,&n);
        double tht=pi/n;
        double r=R*sin(tht)/(sin(tht)+1.0);
        printf("Case %d: %.10f\n",cas,r);
    }
    return 0;
}
