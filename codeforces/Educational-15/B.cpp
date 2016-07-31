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

int a[1000005];
map<long long,int>mp;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
        mp[a[i]]++;
    }
    long long ans=0;
    for(int i=0;i<=32;i++)
    {
        long long num=mp[(1LL<<i)];
        ans+=num*(num-1)/2;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=32; j++)
        {
            long long res=(1LL<<j);
            if(res-a[i]>a[i])
            {
                ans+=mp[res-a[i]];
            }
        }
    }
    printf("%I64d\n",ans);
    return 0;
}
