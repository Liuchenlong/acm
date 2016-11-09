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
map <int,int>mp;
vector<int>vec;
int n;
struct seg
{
    int pos;
    int l,r;
}s[200005];
int ans[200005];
int a[4000005];
int N;
int lowbit(int x)
{
    return x&(-x);
}
void add(int x)
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
bool cmp(seg a,seg b)
{
    return a.l<b.l;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        s[i].pos=i;
        scanf("%d%d",&s[i].l,&s[i].r);
        vec.push_back(s[i].l);
        vec.push_back(s[i].r);
    }
    N=n*2;
    sort(vec.begin(),vec.end());
    int pos=1;
    for(int i=0;i<vec.size();i++)
    {
        mp[vec[i]]=pos++;
    }
    for(int i=1;i<=n;i++)
    {
        s[i].l=mp[s[i].l];
        s[i].r=mp[s[i].r];
    }
    sort(s+1,s+n+1,cmp);
    for(int i=n;i>=1;i--)
    {
        add(s[i].r);
        ans[s[i].pos]=sum(s[i].r-1)-sum(s[i].l);
    }
    for(int i=1;i<=n;i++)
        printf("%d\n",ans[i]);
    return 0;
}
