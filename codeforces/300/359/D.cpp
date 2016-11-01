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
#define eps 1e-8
int n,q;
int fat[300005];
vector<int>son[300005];
int tson[300005];
int siz[300005];
int dfs(int rt)
{
    if(siz[rt]!=0)
        return siz[rt];
    int ans=1;
    for(int i=0;i<son[rt].size();i++)
        ans+=dfs(son[rt][i]);
    siz[rt]=ans;
    return siz[rt];
}
int ans[300005];
int cal(int rt)
{
    if(ans[rt])
        return ans[rt];
    for(int i=0;i<son[rt].size();i++)
        ans[son[rt][i]]=cal(son[rt][i]);
    ans[rt]=rt;
    if(tson[rt])
    {
        ans[rt]=ans[tson[rt]];
        while(ans[rt]!=rt)
        {
            if(siz[ans[rt]]*2>=siz[rt])
                break;
            ans[rt]=fat[ans[rt]];
        }
    }
    return ans[rt];
}
int main()
{
    scanf("%d%d",&n,&q);
    fat[1]=-1;
    for(int i=2;i<=n;i++)
    {
        scanf("%d",&fat[i]);
        son[fat[i]].push_back(i);
    }
    for(int i=1;i<=n;i++)
    {
        siz[i]=dfs(i);
    }
    for(int i=2;i<=n;i++)
    {
        if(siz[tson[fat[i]]]<siz[i])
            tson[fat[i]]=i;
    }
    ans[1]=cal(1);
    for(int i=0;i<q;i++)
    {
        int rt;
        scanf("%d",&rt);
        printf("%d\n",ans[rt]);
    }
    return 0;
}
