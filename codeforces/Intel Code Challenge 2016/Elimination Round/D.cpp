#include<stdio.h>
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
int n;
int val[50005];
map<int,bool>vis;
bool check(int x)
{
    vis.clear();
    for(int i=n-1;i>=0;i--)
    {
        int now=val[i];
        while(now)
        {
            if(now<=x&&vis[now]==0)
            {
                vis[now]=1;
                break;
            }
            now/=2;
        }
        if(now==0)return false;
    }
    return true;
}
void output(int x)
{
    vis.clear();
    for(int i=n-1;i>=0;i--)
    {
        int now=val[i];
        while(now)
        {
            if(now<=x&&vis[now]==0)
            {
                vis[now]=1;
                printf("%d ",now);
                break;
            }
            now/=2;
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&val[i]);
    sort(val,val+n);
    int l=1,r=val[n-1];
    while(l<r)
    {
        int mid=(l+r)/2;
        if(check(mid))
            r=mid;
        else
            l=mid+1;
    }
    output(l);
    return 0;
}
