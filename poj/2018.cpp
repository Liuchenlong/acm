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
int m;
long long num[1000005];
long long sum[1000005];
int Q[5000005];
long long getup(int p1,int p2)
{
    return sum[p1]-sum[p2];
}
long long getdown(int p1,int p2)
{
    return p1-p2;
}
double getdp(int pos,int i)
{
    return (double)getup(pos,i)/getdown(pos,i);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&num[i]);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+num[i];
    int head=0,tail=0;
    double ans=0.0;
    for(int i=m;i<=n;i++)
    {
        int k=i-m;
        while(head+1<tail&&getup(k,Q[tail-1])*getdown(Q[tail-1],Q[tail-2])<=getup(Q[tail-1],Q[tail-2])*getdown(k,Q[tail-1]))
                tail--;
        Q[tail++]=k;
        int l=0,r=tail-2;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(getup(i,Q[mid])*getdown(i,Q[mid+1])<=getup(i,Q[mid+1])*getdown(i,Q[mid]))l=mid+1;
            else r=mid-1;
        }
        ans=max(ans,getdp(i,Q[l]));
    }
    printf("%d\n",(int)(1000*ans));
    return 0;
}
