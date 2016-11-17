#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8

int n,m,k;
int x,s;
int a[200005],b[200005],c[200005],d[200005];
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    scanf("%d%d",&x,&s);
    for(int i=0;i<m;i++)scanf("%d",&a[i]);
    for(int i=0;i<m;i++)scanf("%d",&b[i]);
    for(int i=0;i<k;i++)scanf("%d",&c[i]);
    for(int i=0;i<k;i++)scanf("%d",&d[i]);
    long long ans=1LL*n*x;
    if(d[0]<=s)
    {
        int pos=upper_bound(d,d+k,s)-d-1;
        ans=min(ans,1LL*max((n-c[pos]),0)*x);
    }
    for(int i=0;i<m;i++)
    {
        if(d[0]<=(s-b[i]))
        {
            int pos=upper_bound(d,d+k,s-b[i])-d-1;
            ans=min(ans,1LL*max((n-c[pos]),0)*a[i]);
        }
        else if(b[i]<=s)
            ans=min(ans,1LL*n*a[i]);
    }
    printf("%I64d\n",ans);
    return 0;
}
