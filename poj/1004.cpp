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


int main()
{
    double sum=0.0;
    for(int i=0;i<12;i++)
    {
        double x;
        scanf("%lf",&x);
        sum+=x;
    }
    printf("$%.2f\n",sum/12);
    return 0;
}
