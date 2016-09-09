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
int cnt[100005];
int a[100005],b[100005];
int ba[100005];
int c[100005],d[100005],e[100005];
pair<int,pair<int,int> > p3[100005];
int tail;
int N=1005;
int bit[1015][1015];
int lowbit(int x)
{
    return x&(-x);
}
void add(int x,int y,int info)
{
    for(int i=x;i<=N;i+=lowbit(i))
        for(int j=y;j<=N;j+=lowbit(j))
        bit[i][j]+=info;
}
int qry(int x,int y)
{
    int ans=0;
    for(int i=x;i>0;i-=lowbit(i))
        for(int j=y;j>0;j-=lowbit(j))
        ans+=bit[i][j];
    return ans;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        memset(cnt,0,sizeof(cnt));
        memset(ba,-1,sizeof(ba));
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&a[i],&b[i]);
            ba[b[i]]=max(ba[b[i]],a[i]);
        }
        for(int i=0;i<n;i++)
        {
            if(ba[b[i]]==a[i])
                cnt[b[i]]++;
        }
        int maxc=N-1,maxd=N-1;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&c[i],&d[i],&e[i]);
        }
        tail=0;
        map<pair<int,pair<int,int> >,long long >mp;
        for(int i=0;i<m;i++)
        {
            if(ba[e[i]]==-1)
                continue;
            p3[tail++]=make_pair(ba[e[i]],make_pair(c[i],d[i]));
            mp[p3[tail-1]]+=cnt[e[i]];
        }
        sort(p3,p3+tail);
        tail=unique(p3,p3+tail)-p3;
        long long ans=0;
        memset(bit,0,sizeof(bit));
        for(int i=tail-1;i>=0;i--)
        {
            int x=p3[i].second.first;
            int y=p3[i].second.second;
            if(qry(maxc,maxd)-qry(x-1,maxd)-qry(maxc,y-1)+qry(x-1,y-1)==0)
            {
                ans+=mp[p3[i]];
            }
            add(x,y,1);
        }
        printf("Case #%d: %lld\n",cas,ans);
    }
    return 0;
}
