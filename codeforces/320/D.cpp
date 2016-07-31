#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
int n,k,x;
long long mul;
long long a[200005];
long long pre[200005];
long long suf[200005];
int main()
{
    scanf("%d%d%d",&n,&k,&x);
    mul=1LL;
    for(int i=0;i<k;i++)
        mul*=x;
    for(int i=1;i<=n;i++)
        scanf("%I64d",&a[i]);
    for(int i=1;i<=n;i++)
        pre[i]=pre[i-1]|a[i];
    for(int i=n;i>=1;i--)
        suf[i]=suf[i+1]|a[i];
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,(a[i]*mul)|pre[i-1]|suf[i+1]);
    }
    printf("%I64d\n",ans);
    return 0;
}
