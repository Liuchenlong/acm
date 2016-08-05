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
#define eps 1e-14

long long c[100005];
bool vis[100005];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    long long sum=0;
    long long ans=0;
    for(int i=0;i<n;i++)
    {
        scanf("%I64d",&c[i]);
        sum+=c[i];
    }
    long long sum2=0;
    for(int i=0;i<k;i++)
    {
        int pos;
        scanf("%d",&pos);
        vis[pos-1]=1;
        sum2+=c[pos-1];
    }
    for(int i=0;i<n;i++)
    {
        ans+=c[i]*c[(i+1)%n];
    }
    long long ans2=0;
    for(int i=0;i<n;i++)
    {
        if(vis[i])
        {
            ans+=(sum-c[i]-c[(i+1)%n]-c[(i+n-1)%n])*c[i];
            long long s2=sum2-c[i];
            if(vis[(i+1)%n])s2-=c[(i+1)%n];
            if(vis[(i+n-1)%n])s2-=c[(i+n-1)%n];
            ans2+=s2*c[i];
        }
    }
    printf("%I64d\n",ans-ans2/2);
    return 0;
}
