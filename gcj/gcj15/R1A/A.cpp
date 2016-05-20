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
int num[1005];
int n;
int check(int x)
{
    int ans=0;
    for(int i=1;i<n;i++)
    {
        int det=10*x;
        if(num[i]<num[i-1]-det)
            return -1;
        else
        {
            ans=ans+num[i-1]-max(num[i-1]-det,0);
        }
    }
    return ans;
}
int main()
{
//    freopen("A-small-practice.in","r",stdin);
//    freopen("A-small-practice.out","w",stdout);
//    freopen("A-large-practice.in","r",stdin);
//    freopen("A-large-practice.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&num[i]);
        int ans1=0,ans2=0;
        for(int i=1;i<n;i++)
            ans1=ans1+max(0,num[i-1]-num[i]);
        int v=0;
        for(int i=1;i<n;i++)
        {
            if(num[i-1]-v>num[i])
            v=max(v,num[i-1]-num[i]);
        }
        for(int i=1;i<n;i++)
        {
            ans2=ans2+num[i-1]-max(0,num[i-1]-v);
        }
        printf("Case #%d: %d %d\n",cas,ans1,ans2);
    }
    return 0;
}
