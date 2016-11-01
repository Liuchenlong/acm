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
bool vis[1005][1005];
bool flip[1005];
int num[1005];
struct qry
{
    int type;
    int i,j;
};
qry Q[100005];
int n,m,q;
vector<int>nxt[100005];
int ans[100005];
void dfs(int pos,int sum)
{
    bool change=false;
    if(Q[pos].type==1)
    {
        int i=Q[pos].i;
        int j=Q[pos].j;
        if(flip[i])
        {
            if(vis[i][j]){change=true;sum++;num[i]++;vis[i][j]=0;}
            else ;
        }
        else
        {
            if(vis[i][j]);
            else {change=true;sum++;num[i]++;vis[i][j]=1;}
        }
    }
    if(Q[pos].type==2)
    {
        int i=Q[pos].i;
        int j=Q[pos].j;
        if(flip[i])
        {
            if(vis[i][j]);
            else {change=true;vis[i][j]=1;sum--;num[i]--;}
        }
        else
        {
            if(vis[i][j]){change=true;vis[i][j]=0;sum--;num[i]--;}
            else ;
        }
    }
    if(Q[pos].type==3)
    {
        int k=Q[pos].i;
        flip[k]^=1;
        sum+=(m-num[k]-num[k]);
        num[k]=m-num[k];
    }
    ans[pos]=sum;
    for(int i=0; i<nxt[pos].size(); i++)
    {
        dfs(nxt[pos][i],sum);
    }
    if(Q[pos].type==1)
    {
        int i=Q[pos].i;
        int j=Q[pos].j;
        if(change)
        {
            vis[i][j]^=1;
            num[i]--;
        }
    }
    if(Q[pos].type==2)
    {
        int i=Q[pos].i;
        int j=Q[pos].j;
        if(change)
        {
            vis[i][j]^=1;
            num[i]++;
        }
    }
    if(Q[pos].type==3)
    {
        int k=Q[pos].i;
        flip[k]^=1;
        num[k]=m-num[k];
    }
}
int main()
{
    scanf("%d%d%d",&n,&m,&q);
    Q[0].type=4;
    for(int i=1; i<=q; i++)
    {
        scanf("%d",&Q[i].type);
        if(Q[i].type<=2)
        {
            scanf("%d%d",&Q[i].i,&Q[i].j);
        }
        else
            scanf("%d",&Q[i].i);
        if(Q[i].type==4)
            nxt[Q[i].i].push_back(i);
        else
            nxt[i-1].push_back(i);
    }
    dfs(0,0);
    for(int i=1; i<=q; i++)
        printf("%d\n",ans[i]);
    return 0;
}
