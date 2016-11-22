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
const long long inf=(1LL<<60);
int n,k;
long long s,t;
long long c[200005],v[200005];
long long g[200005];
long long d[200005];
long long d2[200005];
long long sum[200005];
int tot;
bool check(int x)
{
//    printf("%d\n",x);
    int pos=upper_bound(d2,d2+tot,v[x])-1-d2;
//    printf("%d\n",pos);
    long long tim=sum[pos];
    tim=tim+(3LL*(sum[tot-1]-sum[pos])-v[x]*(tot-1-pos));
//    printf("%I64d\n",tim);
    return tim<=t;
}
int main()
{
    scanf("%d%d%I64d%I64d",&n,&k,&s,&t);
    for(int i=0;i<n;i++)scanf("%I64d%I64d",&c[i],&v[i]);
    long long ans=inf;
    for(int i=0;i<k;i++)scanf("%I64d",&g[i]);
    sort(g,g+k);
    d[0]=g[0];
    for(int i=1;i<k;i++)d[i]=g[i]-g[i-1];
    d[k]=s-g[k-1];
    tot=k+1;
    sort(d,d+tot);
    for(int i=0;i<tot;i++)
        d2[i]=d[i]*2;
    sum[0]=d[0];
    for(int i=1;i<tot;i++)
        sum[i]=sum[i-1]+d[i];
    for(int i=0;i<n;i++)
    {
        if(v[i]<d[tot-1])continue;
        if(check(i))
            ans=min(ans,c[i]);
    }
    printf("%I64d\n",ans==inf?-1:ans);
    return 0;
}
