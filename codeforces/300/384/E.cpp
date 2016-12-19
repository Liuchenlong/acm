#include <bits/stdc++.h>
using namespace std;
vector<int>vec[10];
int n;
int num[1005];
int dp[1005][1<<8];
int ans=0;
bool check(int len)
{
    memset(dp,-1,sizeof(dp));
    dp[0][0]=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<(1<<8);j++)
        {
            if(dp[i][j]==-1)continue;
            for(int k=0;k<8;k++)
            {
                if(j&(1<<k))continue;
                int pos=lower_bound(vec[k+1].begin(),vec[k+1].end(),i)-vec[k+1].begin();
                if(pos+len<=vec[k+1].size())
                {
                    int nxt=len==0?i+1:vec[k+1][pos+len-1]+1;
                    dp[nxt][j|(1<<k)]=max(dp[nxt][j|(1<<k)],dp[i][j]+len);
                }
                if(pos+len+1<=vec[k+1].size())
                {
                    int nxt=vec[k+1][pos+len]+1;
                    dp[nxt][j|(1<<k)]=max(dp[nxt][j|(1<<k)],dp[i][j]+len+1);
                }
            }
            if(j==(1<<8)-1)
                dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
        }
    }
    if(dp[n][(1<<8)-1]==-1)
        return false;
    ans=max(ans,dp[n][(1<<8)-1]);
    return true;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&num[i]);
    for(int i=0;i<n;i++)vec[num[i]].push_back(i);
    for(int i=1;i<=8;i++)if(vec[i].size()>0)ans++;
    int l=1,r=n;
    while(l<r)
    {
        int mid=(l+r+1)/2;
        if(check(mid))
            l=mid;
        else
            r=mid-1;
    }
    check(l);
    printf("%d\n",ans);
    return 0;
}
