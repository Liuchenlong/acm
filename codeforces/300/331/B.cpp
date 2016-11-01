#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

#define ABS(a) ((a)<0?-(a):(a))

long long num[200005];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%I64d",&num[i]);
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=ans+ABS(num[i]-num[i-1]);
    }
    printf("%I64d\n",ans);
    return 0;
}
