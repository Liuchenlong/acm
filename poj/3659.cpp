#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
#define eps 1e-8
int n;
vector<int>son[10005];
int dp[10005][3];
int fa[10005];
int inf=1000000;
void getdp(int rt)
{
    dp[rt][0]=0;
    dp[rt][1]=0;
    dp[rt][2]=1;
    if(son[rt].size()==1&&fa[rt]!=-1)
    {
        dp[rt][1]=inf;
        return ;
    }
    bool flag=false;
    int det=inf;
    for(int i=0;i<son[rt].size();i++)
    {
        int nxt=son[rt][i];
        if(fa[rt]==nxt)continue;
        fa[nxt]=rt;
        getdp(nxt);
        dp[rt][0]+=min(dp[nxt][1],dp[nxt][2]);
        dp[rt][2]+=min(dp[nxt][0],min(dp[nxt][1],dp[nxt][2]));
        if(dp[nxt][2]<=dp[nxt][1])
        {
            flag=true;
            dp[rt][1]+=dp[nxt][2];
        }
        else
        {
            dp[rt][1]+=dp[nxt][1];
            if(dp[nxt][2]-dp[nxt][1]<det)
                det=dp[nxt][2]-dp[nxt][1];
        }
    }
    if(!flag)
        dp[rt][1]+=det;
}

int main()
{
    scanf("%d",&n);
    memset(fa,-1,sizeof(fa));
    for(int i=0; i<n-1; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        son[u].push_back(v);
        son[v].push_back(u);
    }
    getdp(1);
    printf("%d\n",min(dp[1][1],dp[1][2]));
    return 0;
}
