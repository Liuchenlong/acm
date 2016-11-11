#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
#define eps 1e-8
int d[1000005];
int cnt[12];
int main()
{
    for(int i=0;i<10;i++)d[i]=i;
    for(int i=10;i<=1000000;i++)
    {
        int t=i;
        int num=0;
        while(t)
        {
            num+=t%10;t/=10;
        }
        d[i]=d[num];
    }
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        cnt[d[i]]++;
    long long ans=0;
    for(int a=1;a<=9;a++)for(int b=1;b<=9;b++)for(int c=1;c<=9;c++)
    {
        if(d[a*b]==d[c])
        {
            ans+=1LL*cnt[a]*cnt[b]*cnt[c];
        }
    }
    for(int i=1;i<=n;i++)
        ans-=n/i;
    printf("%I64d\n",ans);
    return 0;
}
