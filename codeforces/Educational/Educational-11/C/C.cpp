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
int n,k;
int num[300006];
int sum[300005];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&num[i]);
        sum[i]+=sum[i-1];
        if(num[i]==0)
            sum[i]++;
    }
    int ans=0;
    int l=0,r=0;
    for(int i=0;i<n;i++)
    {
        int pos=upper_bound(sum+1,sum+n+1,sum[i]+k)-1-sum;
        if(pos-i>ans)
        {
            ans=pos-i;
            l=i;
            r=pos;
        }
    }
    int tsum=0;
    for(int i=1;i<=n;i++)
    {
        if(i<=r&&i>l)
        {
            num[i]=1;
            tsum++;
        }
    }
    printf("%d\n",tsum);
    for(int i=1;i<=n;i++)
        printf("%d ",num[i]);
    printf("\n");
    return 0;
}
