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
struct seg
{
    int l,r;
};
seg s[100005];
bool cmp(seg a,seg b)
{
    if(a.l==b.l)
        return a.r<b.r;
    return a.l<b.l;
}
int n,m,k;
int num[100005];
long long Sum[100005];
int a[100005];
int lowbit(int x)
{
    return x&(-x);
}
int add(int x,int info)
{
    for(int i=x; i<=n; i+=lowbit(i))
        a[i]+=info;
}
int sum(int x)
{
    int ans=0;
    for(int i=x; i>=1; i-=lowbit(i))
        ans+=a[i];
    return ans;
}
int main()
{
    while(scanf("%d%d%d",&n,&k,&m)!=EOF)
    {
        memset(a,0,sizeof(a));
        for(int i=1; i<=n; i++)scanf("%d",&num[i]);
        for(int i=1; i<=n; i++)Sum[i]=Sum[i-1]+num[i];
        for(int i=0; i<m; i++)scanf("%d%d",&s[i].l,&s[i].r);
        sort(s,s+m,cmp);
        long long ans=0;
        for(int i=0; i<m; i++)
        {
            int L=s[i].l;
            int l=1,r=s[i].r;
            add(s[i].r,1);
            while(l<r)
            {
                int mid=(l+r+1)/2;
                if((sum(n)-sum(mid-1))>=k)
                    l=mid;
                else
                    r=mid-1;
            }
            if(L<=l&&sum(n)-sum(l-1)>=k)
                ans=max(ans,Sum[l]-Sum[L-1]);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
