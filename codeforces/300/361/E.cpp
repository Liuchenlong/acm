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
#include<bitset>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
int n;
int a[200005*2];
int lowbit(int x)
{
    return x&(-x);
}
int add(int x)
{
    for(int i=x; i<=n*2; i+=lowbit(i))
        a[i]++;
}
int query(int x)
{
    int ans=0;
    for(int i=x; i>0; i-=lowbit(i))
        ans+=a[i];
    return ans;
}
struct seg
{
    long long l,r;
    long long tl,tr;
};
bool cmp1(seg a,seg b)
{
    return a.l<b.l;
}
bool cmp2(seg a,seg b)
{
    return a.r>b.r;
}
seg s[2000005];
map<int,int>mp;
long long fac[2000005];
long long finv[2000005];
const long long mod=1e9+7;
void init()
{
    fac[0]=1;
    finv[0]=1;
    fac[1]=1;
    finv[1]=1;
    for(int i=2; i<=2000000; i++)
    {
        fac[i]=fac[i-1]*i%mod;
        finv[i]=(mod-mod/i)*finv[mod%i]%mod;
    }
    for(int i=1; i<=2000000; i++)
        finv[i]=finv[i-1]*finv[i]%mod;
}
long long C(int n,int m)
{
    if(m>n)
        return 0;
    long long ans=1;
    ans=ans*fac[n]*finv[m]%mod*finv[n-m]%mod;
    return ans;
}
int main()
{
    init();
    int k;
    scanf("%d%d",&n,&k);
    for(int i=0; i<n; i++)
    {
        scanf("%I64d%I64d",&s[i].l,&s[i].r);
        s[i].tl=s[i].l;
        s[i].tr=s[i].r;
    }
    vector<int>vec;
    for(int i=0; i<n; i++)
    {
        vec.push_back(s[i].l);
        vec.push_back(s[i].r);
    }
    sort(vec.begin(),vec.end());
    int siz=unique(vec.begin(),vec.end())-vec.begin();
    for(int i=0; i<siz; i++)
        mp[vec[i]]=i+1;
    for(int i=0; i<n; i++)
    {
        s[i].l=mp[s[i].l];
        s[i].r=mp[s[i].r];
    }
    long long ans=0;
    sort(s,s+n,cmp1);
    long long L=-2e9;
    for(int i=0;i<n;i++)
    {
        long long num=C(i-query(s[i].l-1),k-1);
        ans=(ans-num*((s[i].tl-L)%mod))%mod;
        add(s[i].r);
    }
    memset(a,0,sizeof(a));
    sort(s,s+n,cmp2);
    for(int i=0;i<n;i++)
    {
        long long num=C(query(s[i].r),k-1);
        ans=(ans+num*((s[i].tr-L+1)%mod))%mod;
        add(s[i].l);
    }
    printf("%I64d\n",(ans%mod+mod)%mod);
    return 0;
}
