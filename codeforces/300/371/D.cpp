#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
using namespace std;
#define eps 1e-8
struct matrix
{
    int x1,y1;
    int x2,y2;
};
matrix ans1,ans2;
int n;
int get(int x1,int y1,int x2,int y2)
{
    printf("? %d %d %d %d\n",x1,y1,x2,y2);
    fflush(stdout);
    int x;
    scanf("%d",&x);
    return x;
}
int calx1(int x1,int y1,int x2,int y2)
{
    int l=x1,r=x2;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(get(mid+1,y1,x2,y2)==1)
            l=mid+1;
        else
            r=mid;
    }
    return l;
}
int calx2(int x1,int y1,int x2,int y2)
{
    int l=x1,r=x2;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(get(x1,y1,mid,y2)==1)
            r=mid;
        else
            l=mid+1;
    }
    return r;
}
int caly1(int x1,int y1,int x2,int y2)
{
    int l=y1,r=y2;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(get(x1,mid+1,x2,y2)==1)
            l=mid+1;
        else
            r=mid;
    }
    return l;
}
int caly2(int x1,int y1,int x2,int y2)
{
    int l=y1,r=y2;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(get(x1,y1,x2,mid)==1)
            r=mid;
        else
            l=mid+1;
    }
    return r;
}
matrix cal(int x1,int y1,int x2,int y2)
{
    matrix ans;
    ans.x1=calx1(x1,y1,x2,y2);
    ans.y1=caly1(x1,y1,x2,y2);
    ans.x2=calx2(x1,y1,x2,y2);
    ans.y2=caly2(x1,y1,x2,y2);
    return ans;
}
bool checkx()
{
    int l=1,r=n;
    while(l<r)
    {
        int mid=(l+r)/2;
        int ll=get(1,1,n,mid);
        int rr=get(1,mid+1,n,n);
        if(ll==1&&rr==1)
        {
            ans1=cal(1,1,n,mid);
            ans2=cal(1,mid+1,n,n);
            printf("! %d %d %d %d %d %d %d %d\n",ans1.x1,ans1.y1,ans1.x2,ans1.y2,ans2.x1,ans2.y1,ans2.x2,ans2.y2);
            fflush(stdout);
            return true;
        }
        else if(ll>0&&rr==0)
        {
            r=mid;
        }
        else if(ll==0&&rr>0)
        {
            l=mid+1;
        }
        else if(ll==0&&rr==0)
            return false;
    }
    return false;
}
bool checky()
{
    int l=1,r=n;
    while(l<r)
    {
        int mid=(l+r)/2;
        int ll=get(1,1,mid,n);
        int rr=get(mid+1,1,n,n);
        if(ll==1&&rr==1)
        {
            ans1=cal(1,1,mid,n);
            ans2=cal(mid+1,1,n,n);
            printf("! %d %d %d %d %d %d %d %d\n",ans1.x1,ans1.y1,ans1.x2,ans1.y2,ans2.x1,ans2.y1,ans2.x2,ans2.y2);
            fflush(stdout);
            return true;
        }
        else if(ll>0&&rr==0)
        {
            r=mid;
        }
        else if(ll==0&&rr>0)
        {
            l=mid+1;
        }
        else if(ll==0&&rr==0)
            return false;
    }
    return false;
}
int main()
{
    scanf("%d",&n);
    if(checkx())
        ;
    else(checky())
        ;
    return 0;
}
