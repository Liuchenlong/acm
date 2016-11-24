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
int n,m;
int sum[105];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&sum[i]);
    for(int i=1;i<=n;i++)sum[i]+=sum[i-1];
    long long ans=0;
    for(int i=0;i<m;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        if(sum[r]-sum[l-1]>=0)
            ans+=sum[r]-sum[l-1];
    }
    printf("%I64d\n",ans);
    return 0;
}
