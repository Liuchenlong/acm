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

int n,m;
vector<int>son[100005];
bool nrt[100005];
vector<int>road[100005];
int gft[100005];
int d[100005];
void dfs(int pos,int mx)
{
    for(int i=0;i<son[pos].size();i++)
    {
        int nxt=son[pos][i];
        int gt=gft[nxt];
        if(gt==mx)
        {
            road[mx].push_back(nxt);
            dfs(nxt,mx);
        }
        else
        {
            road[gt].push_back(mx);
            if(gt!=nxt)
                road[gt].push_back(nxt);
            dfs(nxt,gt);
        }
    }
}
vector<int>ans;
void topo()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<road[i].size();j++)
            d[road[i][j]]++;
    }
    queue<int>Q;
    for(int i=0;i<n;i++)
        if(d[i]==0)
        Q.push(i);
    while(Q.size())
    {
        int head=Q.front();
        Q.pop();
        ans.push_back(head);
        for(int i=0;i<road[head].size();i++)
        {
            int nxt=road[head][i];
            d[nxt]--;
            if(d[nxt]==0)
                Q.push(nxt);
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int f,s;
        scanf("%d%d",&f,&s);
        f--;
        s--;
        son[f].push_back(s);
        nrt[s]=1;
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&gft[i]);
        gft[i]--;
    }
    for(int i=0;i<n;i++)
    {
        if(nrt[i]==0)
            dfs(i,gft[i]);
    }
    topo();
    if(ans.size()!=n)
        printf("-1\n");
    else
    {
        printf("%d\n",n);
        for(int i=0;i<n;i++)
            printf("%d\n",ans[i]+1);
    }
    return 0;
}
