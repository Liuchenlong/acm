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

int pre[200005];
int find(int x)
{
    if(x!=pre[x])
        pre[x]=find(pre[x]);
    return pre[x];
}
void Union(int x,int y)
{
    pre[find(x)]=find(y);
}
int n,m,k;
int c[200005];
map<int,int>cnt[200005];
int mx[200005];
int ans[200005];
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++)
    {
        pre[i]=i;
        scanf("%d",&c[i]);
    }
    for(int i=0;i<m;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        l--;
        r--;
        if(find(l)!=find(r))
            Union(l,r);
    }
    for(int i=0;i<n;i++)
    {
        cnt[find(i)][c[i]]++;
        if(cnt[find(i)][c[i]]>mx[find(i)])
        {
            mx[find(i)]=cnt[find(i)][c[i]];
            ans[find(i)]=c[i];
        }
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        if(c[i]!=ans[find(i)])
            sum++;
    }
    printf("%d\n",sum);
    return 0;
}
