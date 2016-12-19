#include <bits/stdc++.h>

using namespace std;
int n,m,W;
int dp[1005];
int w[1005];
int v[1005];
int pre[1005];
void init()
{
    for(int i=1; i<=1000; i++)
        pre[i]=i;
}
int find(int x)
{
    if(pre[x]!=x)
        pre[x]=find(pre[x]);
    return pre[x];
}
void Union(int x,int y)
{
    int fx=find(x);
    int fy=find(y);
    pre[fx]=fy;
}
vector<pair<int,int> >vec[1005][2];
int ww[1005];
int vv[1005];
int dpnxt[1005];
int main()
{
    scanf("%d%d%d",&n,&m,&W);
    for(int i=1; i<=n; i++)scanf("%d",&w[i]);
    for(int i=1; i<=n; i++)scanf("%d",&v[i]);
    init();
    for(int i=0; i<m; i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if(find(a)!=find(b))
            Union(a,b);
    }
    for(int i=1; i<=n; i++)vec[i][1].push_back(make_pair(0,0));
    for(int i=1; i<=n; i++)
    {
        vec[find(i)][0].push_back(make_pair(w[i],v[i]));
        vec[find(i)][1][0].first+=w[i];
        vec[find(i)][1][0].second+=v[i];
    }
    memset(dp,-1,sizeof(dp));
    memset(dpnxt,-1,sizeof(dpnxt));
    dp[0]=0;
    dpnxt[0]=0;
    for(int i=1; i<=n; i++)
    {
        if(vec[i][0].size()==0)continue;
        else
        {
            for(int j=0; j<vec[i][0].size(); j++)
            {
                int we=vec[i][0][j].first,va=vec[i][0][j].second;
                for(int k=W; k>=we; k--)
                {
                    if(dp[k-we]==-1)continue;
                    dpnxt[k]=max(dpnxt[k],dp[k-we]+va);
                }
            }
            int we=vec[i][1][0].first,va=vec[i][1][0].second;
            for(int k=W; k>=we; k--)
            {
                if(dp[k-we]==-1)continue;
                dpnxt[k]=max(dpnxt[k],dp[k-we]+va);
            }
            for(int j=0; j<=W; j++)
                dp[j]=max(dp[j],dpnxt[j]);
        }
    }
    int ans=0;
    for(int i=0; i<=W; i++)ans=max(ans,dp[i]);
    printf("%d\n",ans);
    return 0;
}
