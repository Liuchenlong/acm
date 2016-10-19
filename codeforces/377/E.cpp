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
#define LL int
#define pii pair<int,int>
int n,m;
pii pp[200005];
pii ps[200005];
map<int,int>head;
int nxt[200005];
int ans[200005];
int cnt[200005];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&pp[i].first);
        head[pp[i].first]=-1;
        pp[i].second=i+1;
    }
    for(int i=0;i<m;i++)
    {
        scanf("%d",&ps[i].first);
        ps[i].second=i+1;
    }
    sort(pp,pp+n);
    sort(ps,ps+m);
    for(int i=0;i<n;i++)
    {
        int val=pp[i].first;
        nxt[i]=head[val];
        head[val]=i;
    }
    int c=0,u=0;
    for(int i=0;i<m;i++)
    {
        int val=ps[i].first;
        while(1)
        {
            if(head.find(val)!=head.end()&&head[val]!=-1)
            {
                c++;
                u+=cnt[ps[i].second];
                ans[pp[head[val]].second]=ps[i].second;
                head[val]=nxt[head[val]];
                break;
            }
            if(val==1)
            {
                cnt[ps[i].second]=0;
                break;
            }
            val=(val+1)/2;
            cnt[ps[i].second]++;
        }
    }
    printf("%d %d\n",c,u);
    for(int i=1;i<=m;i++)printf("%d ",cnt[i]);
    printf("\n");
    for(int i=1;i<=n;i++)printf("%d ",ans[i]);
    printf("\n");
    return 0;
}
