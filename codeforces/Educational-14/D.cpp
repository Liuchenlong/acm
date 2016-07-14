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
int n,m;
int pre[1000005];
void init()
{
    for(int i=1;i<=n;i++)
        pre[i]=i;
}
int find(int x)
{
    if(x!=pre[x])
    {
        int fx=find(pre[x]);
        pre[x]=fx;
    }
    return pre[x];
}
void Union(int x,int y)
{
    int fx=find(x);
    int fy=find(y);
    pre[fx]=fy;
}
int num[1000005];
vector<int>vpos[1000005];
vector<int>vval[1000005];
int ans[1000005];
int main()
{
    scanf("%d%d",&n,&m);
    init();
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&num[i]);
    }
    for(int i=0;i<m;i++)
    {
        int pa,pb;
        scanf("%d%d",&pa,&pb);
        if(find(pa)!=find(pb))
            Union(pa,pb);
    }
    for(int i=1;i<=n;i++)
    {
        int pos=find(i);
        vpos[pos].push_back(i);
        vval[pos].push_back(num[i]);
    }
    for(int i=1;i<=n;i++)
    {
        if(vpos[i].size())
        {
            sort(vpos[i].begin(),vpos[i].end());
            sort(vval[i].rbegin(),vval[i].rend());
            for(int j=0;j<vpos[i].size();j++)
                ans[vpos[i][j]]=vval[i][j];
        }
    }
    for(int i=1;i<=n;i++)
        printf("%d ",ans[i]);
    printf("\n");
    return 0;
}
