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
int n;
int num[300005];
map <int,int>mp;
struct seg
{
    int l,r;
    seg(int a=0,int b=0)
    {
        l=a;
        r=b;
    }
};
bool cmp(seg a,seg b)
{
    if(a.r==b.r)
        return a.l<b.l;
    return a.r<b.r;
}
vector <seg>vec;
vector <seg>vans;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&num[i]);
    }
    for(int i=1;i<=n;i++)
    {
        if(mp[num[i]]!=0)
        {
            vec.push_back(seg(mp[num[i]],i));
        }
        mp[num[i]]=i;
    }
    sort(vec.begin(),vec.end(),cmp);
    int ans=0;
    int l=1;
    for(int i=0;i<vec.size();i++)
    {
        if(vec[i].l>=l)
        {
            ans++;
            vans.push_back(seg(l,vec[i].r));
            l=vec[i].r+1;
        }
    }
    if(ans==0)
        printf("-1\n");
    else
    {
        vans[ans-1].r=n;
        printf("%d\n",ans);
        for(int i=0;i<vans.size();i++)
            printf("%d %d\n",vans[i].l,vans[i].r);
    }
    return 0;
}
