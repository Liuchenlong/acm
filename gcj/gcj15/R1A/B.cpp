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
int n,m;
int tim[1005];
bool check(int pos)
{
    long long l=1,r=m;
    while(l<=r)
    {
        long long mid=(l+r)/2;
        long long t=(long long)tim[pos]*(mid-1);
        long long num=0;
        for(int i=1; i<=pos; i++)
            num=num+(t/tim[i]+1);
        for(int i=pos+1;i<=n;i++)
        {
            num=num+(t/tim[i]+1);
            if(t%tim[i]==0)
                num--;
        }
        if(num==m)
            return true;
        if(num>m)
            r=mid-1;
        else
            l=mid+1;
    }
    return false;
}
int main()
{
//    freopen("B-small-practice.in","r",stdin);
//    freopen("B-small-practice.out","w",stdout);
//    freopen("B-large-practice.in","r",stdin);
//    freopen("B-large-practice.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++)
            scanf("%d",&tim[i]);
        int ans=0;
        for(int i=1; i<=n; i++)
            if(check(i))
            {
                ans=i;
                break;
            }
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}
