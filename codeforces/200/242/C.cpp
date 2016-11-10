#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
#define eps 1e-8
int n;
int q[1000005];
int pre[1000005];
int main()
{
    for(int i=1;i<=1000000;i++)
        pre[i]=pre[i-1]^i;
    scanf("%d",&n);
    int Q=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&q[i]);
        Q^=q[i];
    }
    for(int i=1;i<=n;i++)
    {
        int t=n+1;
        Q^=((t/i)%2*pre[i-1])^(t%i==0?0:pre[t%i-1]);
    }
    printf("%d\n",Q);
    return 0;
}
