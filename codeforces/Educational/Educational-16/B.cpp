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
int n;
long long x[300005];
long long pre[300005];
long long suf[300005];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%I64d",&x[i]);
    sort(x,x+n);
    long long now=0;
    for(int i=0;i<n;i++)
    {
        pre[i]=x[i]*i-now;
        now+=x[i];
    }
    now=0;
    for(int i=n-1;i>=0;i--)
    {
        suf[i]=now-x[i]*(n-1-i);
        now+=x[i];
    }
    int ans=0;
    for(int i=1;i<n;i++)
    {
        if(pre[i]+suf[i]<pre[ans]+suf[ans])
            ans=i;
    }
    printf("%d\n",x[ans]);
    return 0;
}
