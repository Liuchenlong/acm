#include<stdio.h>
#include<cmath>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<set>
#include<vector>
#include<map>
using namespace std;
#define eps 1e-12
const int maxn=100000000+100;
int mask[maxn/32+5];
int prime[5761461],prinum;
bool getp(int x)
{
    return (1<<(x%32))&(mask[x/32]);
}
void setp(int x)
{
    mask[x/32]|=(1<<(x%32));
}
unsigned int mul[5761461];
void getprime()
{
    for(int i=2;i<=maxn;i++)
    {
        if(getp(i))
            continue;
        prime[prinum++]=i;
        for(int j=2*i;j<=maxn;j+=i)
            setp(j);
    }
    mul[0]=2;
    for(int i=1;i<prinum;i++)
        mul[i]=mul[i-1]*prime[i];
}
int n;
bool check(int x,int tim)
{
    int val=1;
    for(int i=1;i<=tim;i++)
    {
        if(val>n/x)
            return false;
        val*=x;
    }
    if(val>n)
        return false;
    return true;;
}
unsigned int solve(int &flag,int tim)
{
    if((1<<tim)>n)
    {
        flag=-1;
        return 0;
    }
    int l=0,r=prinum-1;
    flag=1;
    while(l<r)
    {
        int mid=(l+r+1)/2;
        if(check(prime[mid],tim))
        {
            l=mid;
        }
        else
            r=mid-1;
    }
    return mul[l];
}
unsigned int cal(int x)
{
    unsigned int ans=1;
    for(int i=1;;i++)
    {
        int flag;
        unsigned int val;
        val=solve(flag,i);
        if(flag==-1)
            break;
        ans=ans*val;
    }
    return ans;
}
int main()
{
    getprime();
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        scanf("%d",&n);
        printf("Case %d: %u\n",cas,cal(n));
    }
    return 0;
}
