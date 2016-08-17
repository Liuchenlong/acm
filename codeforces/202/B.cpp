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

int cost[10];
int cnt[10];
int main()
{
    int v;
    scanf("%d",&v);
    int pos=1;
    for(int i=1;i<=9;i++)scanf("%d",&cost[i]);
    for(int i=1;i<=9;i++)
    {
        if(cost[i]<=cost[pos])pos=i;
    }
    cnt[pos]=v/cost[pos];
    v%=cost[pos];
    if(cnt[pos]==0)printf("-1\n");
    else
    {
        for(int i=9;i>pos;i--)
        {
            while(cnt[pos]>0&&v+cost[pos]-cost[i]>=0)
            {
                cnt[pos]--;
                cnt[i]++;
                v=v+cost[pos]-cost[i];
            }
        }
        for(int i=9;i>=1;i--)
            for(int j=0;j<cnt[i];j++)
            printf("%d",i);
        printf("\n");
    }
    return 0;
}
