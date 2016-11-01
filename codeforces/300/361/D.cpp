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
int a[200005];
int dpmax[200005][20];
int b[200005];
int dpmin[200005][20];
void init()
{
    for(int i=0; i<20; i++)
        for(int j=0; j<n; j++)
        {
            if(i==0)
            {
                dpmax[j][i]=a[j];
                dpmin[j][i]=b[j];
            }
            else if(j+(1<<i)-1<n)
            {
                dpmax[j][i]=max(dpmax[j][i-1],dpmax[j+(1<<(i-1))][i-1]);
                dpmin[j][i]=min(dpmin[j][i-1],dpmin[j+(1<<(i-1))][i-1]);
            }
        }
}
int query(int l,int r,int type)
{
    double len=(double)r-l+1;
    int two=(int)(log10(len)/log10(2.0));
    if(type)
        return max(dpmax[l][two],dpmax[r-(1<<two)+1][two]);
    return min(dpmin[l][two],dpmin[r-(1<<two)+1][two]);
}
int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)scanf("%d",&a[i]);
    for(int i=0; i<n; i++)scanf("%d",&b[i]);
    init();
    long long ans=0;
    for(int i=0; i<n; i++)
    {
        int sum=0;
        int l=i,r=n-1;
        if(a[i]>b[i])
            continue;
        while(l<r)
        {
            int mid=(l+r+1)/2;
            if(query(i,mid,1)<=query(i,mid,0))
                l=mid;
            else
                r=mid-1;
        }
        sum+=(l-i+1);
        if(a[i]==b[i])
        {
            ans+=sum;
            continue;
        }
        l=i,r=n-1;
        while(l<r)
        {
            int mid=(l+r+1)/2;
            if(query(i,mid,1)<query(i,mid,0))
                l=mid;
            else
                r=mid-1;
        }
        sum-=(l-i+1);
        ans+=sum;
    }
    printf("%I64d\n",ans);
    return 0;
}
