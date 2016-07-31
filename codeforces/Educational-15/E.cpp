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

struct obj
{
    int to;
    long long sum;
    long long Min;
};
obj p[100005][40];
obj ans[100005];
int main()
{
    int n;
    long long k;
    scanf("%d%I64d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&p[i][0].to);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%I64d",&p[i][0].sum);
        p[i][0].Min=p[i][0].sum;
    }
    for(int i=1;i<40;i++)
    {
        for(int j=0;j<n;j++)
        {
            int nt=p[p[j][i-1].to][i-1].to;
            long long nsum=p[j][i-1].sum+p[p[j][i-1].to][i-1].sum;
            long long nmin=min(p[j][i-1].Min,p[p[j][i-1].to][i-1].Min);
            p[j][i].to=nt;
            p[j][i].sum=nsum;
            p[j][i].Min=nmin;
        }
    }
    for(int i=0;i<n;i++)
    {
        ans[i].to=i;
        ans[i].sum=0;
        ans[i].Min=1e9;
    }
    for(int i=0;i<40;i++)
    {
        if(k&(1LL<<i))
        {
            for(int j=0;j<n;j++)
            {
                int nt=p[ans[j].to][i].to;
                long long nsum=ans[j].sum+p[ans[j].to][i].sum;
                long long nmin=min(ans[j].Min,p[ans[j].to][i].Min);
                ans[j].to=nt;
                ans[j].sum=nsum;
                ans[j].Min=nmin;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%I64d %I64d\n",ans[i].sum,ans[i].Min);
    }
    return 0;
}
