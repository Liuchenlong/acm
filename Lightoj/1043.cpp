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
        double ab,ac,bc,r;
        scanf("%lf%lf%lf%lf",&ab,&ac,&bc,&r);
        double ans=sqrt(r/(r+1))*ab;
        printf("Case %d: %.10f\n",cas,ans);
    }
    return 0;
}
