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
int num[100005];
int main()
{
    int n;
    scanf("%d",&n);
    long long sum=0;
    for(int i=0; i<n; i++)
    {
        scanf("%d",&num[i]);
        sum+=num[i];
    }
    sort(num,num+n);
    long long ans=(sum%(n-1)==0?sum/(n-1):sum/(n-1)+1);
    ans=max(ans,1LL*num[n-1]);
    printf("%I64d\n",ans);
    return 0;
}
