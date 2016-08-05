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
const int mod=1000000007;
int n;
long long a[100005];
int lowbit(int x)
{
    return x&(-x);
}
void add(int x,int info)
{
    for(int i=x;i<=n;i+=lowbit(i))
        a[i]=(a[i]+info)%mod;
}
long long qry(int x)
{
    long long ans=0;
    for(int i=x;i>0;i-=lowbit(i))
        ans+=a[i];
    return ans%mod;
}
int num[1000005];
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        memset(a,0,sizeof(a));
        int nn;
        scanf("%d",&nn);
        for(int i=0;i<nn;i++)scanf("%d",&num[i]);
        vector<int>vec;
        for(int i=0;i<nn;i++)vec.push_back(num[i]);
        sort(vec.begin(),vec.end());
        int siz=unique(vec.begin(),vec.end())-vec.begin();
        map<int,int>mp;
        n=siz;
        for(int i=0;i<siz;i++)
            mp[vec[i]]=i+1;
        for(int i=0;i<nn;i++)num[i]=mp[num[i]];
        for(int i=0;i<nn;i++)
        {
            add(num[i],1+qry(num[i]-1));
        }
        printf("Case %d: %lld\n",cas,qry(n));
    }
    return 0;
}
