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
#define eps 1e-7
int n;
int num[100005];
bool check(int x,int type)
{
    int l=x+1,r=n-x;
    int pos=l;
    for(int i=1; i<=x; i++)
    {

        while(pos<=r&&(num[pos]==num[i]))pos++;
        if(pos>r)return false;
        if(num[pos]>=num[n-x+i])return false;

        if(type==1)
        {
            printf("%d %d %d\n",num[n-x+i],num[pos],num[i]);
        }
        pos++;
    }
    return true;
}
int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&num[i]);
    }
    sort(num+1,num+n+1);
    int l=0,r=n/3;
    while(l<r)
    {
        int mid=(l+r+1)/2;
        if(check(mid,0))
            l=mid;
        else
            r=mid-1;
    }
    printf("%d\n",l);
    check(l,1);
    return 0;
}
