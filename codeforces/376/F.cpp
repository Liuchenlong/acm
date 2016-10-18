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

int cnt[500005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        cnt[x]++;
    }
    for(int i=1;i<=500000;i++)cnt[i]+=cnt[i-1];
    long long ans=0;
    for(int i=1;i<=200000;i++)
    {
        if(cnt[i]-cnt[i-1]==0)continue;
        long long tmp=0;
        for(int j=i;j<=200000;j+=i)
        {
            tmp+=1LL*j*(cnt[j+i-1]-cnt[j-1]);
        }
        ans=max(ans,tmp);
    }
    printf("%I64d\n",ans);
    return 0;
}
