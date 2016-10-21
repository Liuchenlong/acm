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
const double pi=acos(-1.0);

int main()
{
    int n;
    scanf("%d",&n);
    for(int cas=1;cas<=n;cas++)
    {
        double x,y;
        scanf("%lf%lf",&x,&y);
        double d2=x*x+y*y;
        double sum=d2*pi/2;
        double yr=sum/50.0;
        printf("Property %d: This property will begin eroding in year %d.\n",cas,(int)(yr-1e-8)+1);
    }
    printf("END OF OUTPUT.\n");
    return 0;
}
