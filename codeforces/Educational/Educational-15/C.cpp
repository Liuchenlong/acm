#include<stdio.h>
#include<cmath>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<set>
#include<vector>
#include<map>
using namespace std;
#define eps 1e-12
int n,m;
long long a[1000005];
long long b[1000005];
const long long inf=(1LL<<40);
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%I64d",&a[i]);
    }
    for(int i=1;i<=m;i++)
        scanf("%I64d",&b[i]);
    b[0]=-inf;
    b[m+1]=inf;
    long long ans=0;
    for(int i=0;i<n;i++)
    {
        int pos=lower_bound(b,b+m+2,a[i])-b;
        ans=max(ans,min(b[pos]-a[i],a[i]-b[pos-1]));
    }
    printf("%I64d\n",ans);
    return 0;
}
