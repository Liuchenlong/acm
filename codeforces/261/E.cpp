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
#define SIZE 1000005
struct road
{
    int f;
    int t;
    int v;
};
bool cmp(road a,road b)
{
    return a.v<b.v;
}
road r[300005];
int n,m;
vector<pair<int,int> >vec[300005];
int dp[300005];
int dpt[300005];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&r[i].f,&r[i].t,&r[i].v);
        vec[r[i].v].push_back(make_pair(r[i].f,r[i].t));
    }
    for(int i=1;i<=300000;i++)
    {
        for(int j=0;j<vec[i].size();j++)
        {
            dpt[vec[i][j].second]=max(dpt[vec[i][j].second],dp[vec[i][j].first]+1);
        }
        for(int j=0;j<vec[i].size();j++)
        {
            dp[vec[i][j].second]=max(dpt[vec[i][j].second],dp[vec[i][j].second]);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)ans=max(ans,dp[i]);
    printf("%d\n",ans);
    return 0;
}
