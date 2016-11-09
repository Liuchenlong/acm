#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <fstream>
using namespace std;
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) (a<0?-a:a)

#define eps 1e-8


int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long n;
        scanf("%I64d",&n);
        long long ans=n*(n+1)/2;
        long long two=1;
        while(two<=n)
        {
            ans-=two*2LL;
            two*=2;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
