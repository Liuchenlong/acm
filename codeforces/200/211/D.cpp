#include<bits/stdc++.h>
using namespace std;
#define eps 1e-8
int n,m,a;
int b[100005];
int p[100005];
bool check(int x)
{
    long long res=0;
    for(int i=0;i<x;i++)
    {
        res+=max(0,p[i]-b[n-x+i]);
    }
    return res<=a;
}
int main()
{
    scanf("%d%d%d",&n,&m,&a);
    for(int i=0;i<n;i++)scanf("%d",&b[i]);
    for(int i=0;i<m;i++)scanf("%d",&p[i]);
    sort(b,b+n);
    sort(p,p+m);
    if(b[n-1]+a<p[0])
    {
        printf("0 0\n");
        return 0;
    }
    else
    {
        int l=1,r=min(n,m);
        while(l<r)
        {
            int mid=(l+r+1)/2;
            if(check(mid))
                l=mid;
            else
                r=mid-1;
        }
        long long sum=0;
        for(int i=0;i<l;i++)sum+=p[i];
        printf("%d %I64d\n",l,max(sum-a,0));
    }
    return 0;
}
