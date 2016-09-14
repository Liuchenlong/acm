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
#define eps 1e-8

int main()
{
    long long l1,r1,l2,r2;
    long long k;
    scanf("%I64d%I64d%I64d%I64d%I64d",&l1,&r1,&l2,&r2,&k);
    long long l=max(l1,l2);
    long long r=min(r1,r2);
    if(l>r)puts("0");
    else
    {
        long long ans=r-l+1;
        if(k>=l&&k<=r)ans--;
        printf("%I64d\n",ans);
    }
    return 0;
}
