#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
using namespace std;

inline int f(int x,int k)
{
    return x-(x/k)-1;
}
int dp[3000005];
int num[3000005];
int last[3000005];
int ans[3000005];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int N,K,Q;
        scanf("%d%d%d",&N,&K,&Q);
        for(int i=0; i<N; i++)
        {
            if(i%K==0)
            {
                dp[i]=1;
                last[i]=i/K;
            }
            else
            {
                dp[i]=dp[f(i,K)]+1;
                last[i]=last[f(i,K)];
            }
        }
        int sum=N-1;
        for(int i=1; i<=N; i++)
        {
            num[i]=1+sum/K;
            sum-=num[i];
            num[i]+=num[i-1];
            if(sum==0)break;
        }
        for(int i=0;i<N;i++)
        {
            int pos=num[dp[i]-1]+last[i]+1;
            ans[pos]=i+1;
        }
        for(int i=0;i<Q;i++)
        {
            int qry;
            scanf("%d",&qry);
            printf("%d\n",ans[qry]);
        }
    }
    return 0;
}
