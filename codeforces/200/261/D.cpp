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
#define SIZE 1000005
int a[1000005];
int n;
int lowbit(int x)
{
    return x&(-x);
}
int add(int x)
{
    for(int i=x;i<=n;i+=lowbit(i))
        a[i]++;
}
int sum(int x)
{
    int ans=0;
    for(int i=x;i>=1;i-=lowbit(i))
        ans+=a[i];
    return ans;
}

int num[1000005];
int val[1000005];
int valp[1000005];
map<int,int>mp;
map<int,int>mpp;
vector<int>vec;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&num[i]);
    for(int i=n;i>=1;i--)
    {
        mp[num[i]]++;
        val[i]=mp[num[i]];
        vec.push_back(val[i]);
    }
    for(int i=1;i<=n;i++)
    {
        mpp[num[i]]++;
        valp[i]=mpp[num[i]];
    }
    sort(vec.begin(),vec.end());
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        add(val[i]);
        int pos=lower_bound(vec.begin(),vec.end(),valp[i])-vec.begin();
        ans+=pos-sum(valp[i]-1);
    }
    printf("%I64d\n",ans);
    return 0;
}
