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
const long long inf=1e9;
long long maxn;
long long ans;
long long sum;
long long p;
int cost[11]= {1,5,10,20,50,100,200,500,1000,2000};
int num[11];
void dfs(int pos,long long s,int snum)
{
    if(s==0)
    {
        ans=min(ans,(long long)snum);
    }
    if(pos==-1)
    {
        return ;
    }
    int t=s/cost[pos];
    if(t<=num[pos])
    {
        dfs(pos-1,s-t*cost[pos],t+snum);
        dfs(pos-1,s-max(0,t-1)*cost[pos],max(0,t-1)+snum);
    }
    else
    {
        dfs(pos-1,s-num[pos]*cost[pos],num[pos]+snum);
        dfs(pos-1,s-max(0,num[pos]-1)*cost[pos],max(0,num[pos]-1)+snum);
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        maxn=0;
        sum=0;
        scanf("%I64d",&p);
        for(int i=0; i<10; i++)
        {
            scanf("%d",&num[i]);
            maxn+=num[i];
            sum+=num[i]*cost[i];
        }
        ans=inf;
        if(sum<p)
        {
            printf("-1\n");
            continue;
        }
        sum-=p;
        for(int i=9; i>=0; i--)
        {
            dfs(i,sum,0);
        }
        if(ans==inf)
            printf("-1\n");
        else
            printf("%I64d\n",maxn-ans);
    }
    return 0;
}
