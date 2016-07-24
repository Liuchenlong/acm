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
const int maxn=100005;
int n,k;
int tim;
double l,v1,v2;
bool check(double t)
{
    double all=t+(l-t*v2)/v1;
    double need=tim*t+(tim-1)*(t*(v2-v1)/(v2+v1));
    return need<=all;
}
int main()
{
    scanf("%d%lf%lf%lf%d",&n,&l,&v1,&v2,&k);
    tim=(n/k)+(n%k!=0);
    double L=0.0,R=l/v2;
    for(int i=0; i<100; i++)
    {
        double mid=(L+R)/2.0;
        if(check(mid))
            L=mid;
        else
            R=mid;
    }
    printf("%.10f\n",L+(l-L*v2)/v1);
    return 0;
}
