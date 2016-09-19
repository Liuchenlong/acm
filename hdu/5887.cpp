#include<stdio.h>
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
int n;
long long k;
struct obj
{
    long long w,v;
    double k;
    bool operator < (const obj a)const
    {
        return k>a.k;
    }
};
obj now[105];
obj res[105];
int siz;
long long ans;
double c;
long long wei[105];
void dfs(int pos,long long has,long long lst)
{
    if((clock()-c)/CLOCKS_PER_SEC > 0.02) return;
    ans=max(ans,has);
    if(pos==siz)return ;
    if(lst<wei[pos])return ;
    if(has+res[pos].k*lst<=ans)return ;
    dfs(pos+1,has,lst);
    if(lst>=res[pos].w)
        dfs(pos+1,has+res[pos].v,lst-res[pos].w);
}
int main()
{
    while(scanf("%d%I64d",&n,&k)!=EOF)
    {
        ans=0;
        for(int i=0; i<n; i++)
        {
            scanf("%I64d%I64d",&now[i].w,&now[i].v);
            now[i].k=(now[i].v*1.0/now[i].w);
        }
        sort(now,now+n);
        siz=0;
        for(int i=0; i<n; i++)
        {
            if(now[i].w>k)continue;
            else res[siz++]=now[i];
        }
        wei[siz-1]=res[siz-1].w;
        for(int i=siz-2;i>=0;i--)
            wei[i]=min(wei[i],res[i].w);
        c=clock();
        dfs(0,0,k);
        printf("%I64d\n",ans);
    }
    return 0;
}
