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
#include<bitset>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
const int maxn=100005;
int father[maxn];
vector<int>son[maxn];
int n;
int num[maxn];
double ans[maxn];
int dfs1(int rt)
{
    int sum=1;
    for(int i=0;i<son[rt].size();i++)
        sum+=dfs1(son[rt][i]);
    num[rt]=sum;
    return num[rt];
}
void dfs(int rt)
{
    if(rt==1)
    {
        ans[rt]=1.0;
    }
    else
    {
        int fh=father[rt];
        ans[rt]=ans[fh]+0.5*(2+num[fh]-1-num[rt]);
    }
    for(int i=0;i<son[rt].size();i++)
        dfs(son[rt][i]);
}
int main()
{
    scanf("%d",&n);
    father[1]=-1;
    for(int i=2; i<=n; i++)
    {
        scanf("%d",&father[i]);
        son[father[i]].push_back(i);
    }
    num[1]=dfs1(1);
    dfs(1);
    for(int i=1;i<=n;i++)
        printf("%f ",ans[i]);
    return 0;
}
