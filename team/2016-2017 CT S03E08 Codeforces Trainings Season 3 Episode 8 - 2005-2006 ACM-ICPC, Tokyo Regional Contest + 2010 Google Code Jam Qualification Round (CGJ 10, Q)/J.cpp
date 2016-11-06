#include <cstdio>
#include <cstring>
#include <map>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
#define eps 1e-8
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        long long n,k;
        scanf("%I64d%I64d",&n,&k);
        if((k%(1LL<<n))==(1LL<<n)-1)
            puts("ON");
        else
            puts("OFF");
    }
    return 0;
}
