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
const int maxn=70005;
int N;
int a[maxn];
int lowbit(int x)
{
    return x&(-x);
}
int add(int x)
{
    for(int i=x;i<=N;i+=lowbit(i))
        a[i]++;
}
int sum(int x)
{
    int ans=0;
    for(int i=x;i>0;i-=lowbit(i))
        ans+=a[i];
    return ans;
}
int n;
int n1[maxn];
int n2[maxn];
map<int,int>mp;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&n1[i]);
        n2[i]=n1[i];
    }
    sort(n2,n2+n);
    N=unique(n2,n2+n)-n2;
    for(int i=0;i<N;i++)
        mp[n2[i]]=i+1;
    long long ans=0;
    for(int i=0;i<n;i++)
    {
        ans+=(i-sum(mp[n1[i]]));
        add(mp[n1[i]]);
    }
    printf("%I64d\n",ans);
    return 0;
}
