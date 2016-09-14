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
#define eps 1e-8
int n,m,k;
int dist[55][55];
void floyd()
{
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                if(i!=j&&dist[i][j]>dist[i][k]+dist[k][j])
                    dist[i][j]=dist[i][k]+dist[k][j];
}
int state[55];
int q[10],t[10],ft[10];
int dp[55][1<<8][1<<8];
int inf;
void update(int &a,int b)
{
    if(a==-1)a=b;
    else a=min(a,b);
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        scanf("%d%d%d",&n,&m,&k);
        memset(dist,0x3f,sizeof(dist));
        for(int i=0; i<m; i++)
        {
            int a,b,d;
            scanf("%d%d%d",&a,&b,&d);
            dist[a][b]=d;
            dist[b][a]=d;
        }
        for(int i=0;i<=n;i++)dist[i][i]=0;
        floyd();
        memset(state,0,sizeof(state));
        for(int i=0; i<k; i++)
        {
            int ni;
            scanf("%d%d%d%d",&q[i],&t[i],&ft[i],&ni);
            for(int j=0; j<ni; j++)
            {
                int x;
                scanf("%d",&x);
                state[x]|=(1<<i);
            }
        }
        memset(dp,0x3f,sizeof(dp));
        inf=dp[0][0][0];
        dp[1][0][0]=0;
        for(int i=0; i<(1<<k); i++)
        {
            for(int j=0; j<(1<<k); j++)
            {
                for(int w=1; w<=n; w++)
                {
                    if(dp[w][i][j]==inf)continue;
                    for(int p=0;p<k;p++)
                    {
                        if(i&(1<<p))continue;
                        int val=dp[w][i][j]+dist[w][q[p]];
                        if(j&(1<<p))
                            val+=ft[p];
                        else
                            val+=t[p];
                        update(dp[q[p]][i|(1<<p)][j|(state[q[p]])],val);
                    }
                    for(int p=1;p<=n;p++)
                    {
                        update(dp[p][i][j|state[p]],dp[w][i][j]+dist[w][p]);
                    }
                }
            }
        }
        int ans=inf;
        for(int i=0;i<(1<<k);i++)for(int j=1;j<=n;j++)
            ans=min(ans,dp[j][(1<<k)-1][i]+dist[1][j]);
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}
