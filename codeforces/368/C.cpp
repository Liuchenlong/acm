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

bool check1(long long x)
{
    for(long long i=1;i*i<x;i++)
    {
        long long res=(long long)sqrt(x*x-i*i);
        if(res*res+i*i==x*x)
        {
            printf("%I64d %I64d\n",i,res);
            return true;
        }
    }
    return false;
}
bool check2(long long x)
{
    for(long long d=1;d<x;d++)
    {
        long long res=x*x-d*d;
        if(res%(d*2)==0)
        {
            printf("%I64d %I64d\n",res/d/2,res/d/2+d);
            return true;
        }
    }
    return false;
}
int main()
{
    long long x;
    scanf("%I64d",&x);
    if(check1(x))
        return 0;
    if(check2(x))
        return 0;
    printf("-1\n");
    return 0;
}
