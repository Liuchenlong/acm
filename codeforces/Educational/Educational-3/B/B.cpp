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
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)<0?-(a):(a))
int n,m;
int num[200005];
int sum[11][200005];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&num[i]);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            sum[j][i]+=sum[j][i-1];
        sum[num[i]][i]++;
    }
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=ans+(n-i)-(sum[num[i]][n]-sum[num[i]][i]);
    }
    printf("%I64d\n",ans);
    return 0;
}
