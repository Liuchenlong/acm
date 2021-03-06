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
#define rep(i,n) for(int i = 0;i < n; i++)
using namespace std;
const int size  = 200005,INF = 1<<30;
int rk[size],sa[size],height[size],w[size],wa[size],res[size];
void getSa (int len,int up)
{
    int *k = rk,*id = height,*r = res, *cnt = wa;
    rep(i,up) cnt[i] = 0;
    rep(i,len) cnt[k[i] = w[i]]++;
    rep(i,up) cnt[i+1] += cnt[i];
    for(int i = len - 1; i >= 0; i--)
    {
        sa[--cnt[k[i]]] = i;
    }
    int d = 1,p = 0;
    while(p < len)
    {
        for(int i = len - d; i < len; i++) id[p++] = i;
        rep(i,len)  if(sa[i] >= d) id[p++] = sa[i] - d;
        rep(i,len) r[i] = k[id[i]];
        rep(i,up) cnt[i] = 0;
        rep(i,len) cnt[r[i]]++;
        rep(i,up) cnt[i+1] += cnt[i];
        for(int i = len - 1; i >= 0; i--)
        {
            sa[--cnt[r[i]]] = id[i];
        }
        swap(k,r);
        p = 0;
        k[sa[0]] = p++;
        rep(i,len-1)
        {
            if(sa[i]+d < len && sa[i+1]+d <len &&r[sa[i]] == r[sa[i+1]]&& r[sa[i]+d] == r[sa[i+1]+d])
                k[sa[i+1]] = p - 1;
            else k[sa[i+1]] = p++;
        }
        if(p >= len) return ;
        d *= 2,up = p, p = 0;
    }
}
void getHeight(int len)
{
    rep(i,len) rk[sa[i]] = i;
    height[0] =  0;
    for(int i = 0,p = 0; i < len - 1; i++)
    {
        int j = sa[rk[i]-1];
        while(i+p < len&& j+p < len&& w[i+p] == w[j+p])
        {
            p++;
        }
        height[rk[i]] = p;
        p = max(0,p - 1);
    }
}
int getSuffix(int s[],int n)
{
    int len = n,up = 0;
    for(int i = 0; i < len; i++)
    {
        w[i] = s[i];
        up = max(up,w[i]);
    }
    w[len++] = 0;
    getSa(len,up+1);
    getHeight(len);
    return len;
}
int n;
int num[200005];
bool check(int len)
{
    int mx=sa[1],mn=sa[1];
    for(int i=2; i<=n; i++)
    {
        if(i==n||height[i]<len)
        {
            if(mx-mn>=len)
                return true;
            mx=sa[i];
            mn=sa[i];
        }
        else
        {
            mx=max(mx,sa[i]);
            mn=min(mn,sa[i]);
        }
    }
    return false;
}
int main()
{
    while(scanf("%d",&n),n)
    {
        for(int i=0; i<n; i++)scanf("%d",&num[i]);
        for(int i=0; i<n-1; i++)num[i]=num[i+1]-num[i]+100;
        n=getSuffix(num,n-1);
        int l=0,r=n-1;
        while(l<r)
        {
            int mid=(l+r+1)/2;
            if(check(mid))
                l=mid;
            else
                r=mid-1;
        }
        if(l+1>=5)
            printf("%d\n",l+1);
        else
            printf("0\n");
    }
    return 0;
}
