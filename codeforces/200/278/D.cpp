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
int n,s,len;
int h[100005];
int dpmax[100005][20];
int dpmin[100005][20];
int mm[100005];
void init()
{
    mm[0] = -1;
    for(int i = 1; i < 100005; i++)
    {
        if((i & (i - 1)) == 0) mm[i] = mm[i - 1] + 1;
        else mm[i] = mm[i - 1];
    }
    for(int i=0; i<20; i++)
        for(int j=0; j<n; j++)
        {
            if(i==0)
            {
                dpmax[j][i]=h[j];
                dpmin[j][i]=h[j];
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
    int two=mm[r-l+1];
    if(type)
        return max(dpmax[l][two],dpmax[r-(1<<two)+1][two]);
    else
        return min(dpmin[l][two],dpmin[r-(1<<two)+1][two]);
}
int l[100005];
int Q[100005];
int dp[100005];
int main()
{
    scanf("%d%d%d",&n,&s,&len);
    for(int i=0; i<n; i++)scanf("%d",&h[i]);
    init();
    int head=0;
    for(int i=0; i<n; i++)
    {
        while(head<i&&(query(head,i,1)-query(head,i,0))>s)head++;
        l[i]=head;
    }
    head=0;
    int tail=0;
    if(len>n||l[len-1]!=0)
    {
        puts("-1");
        return 0;
    }
    memset(dp,-1,sizeof(dp));
    dp[len-1]=1;
    for(int i=len; i<n; i++)
    {
        if(dp[i-1]!=-1)
        {
            while(head<tail&&dp[Q[tail-1]-1]>dp[i-1])tail--;
            Q[tail++]=i;
        }
        if(l[i]==0)
            dp[i]=1;
        else
        {
            while(head<tail&&!(Q[head]>=l[i]))head++;
            if(head<tail&&Q[head]<=i-len+1)
            dp[i]=dp[Q[head]-1]+1;
        }

    }
    printf("%d\n",dp[n-1]);
    return 0;
}
