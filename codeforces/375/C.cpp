#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[2005];
int cnt[2005];
set<pair<int,int> >s;
bool vis[2005];
vector<int>vec;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
        if(a[i]<=m)cnt[a[i]]++;
    }
    int sum=n/m;
    for(int i=1; i<=m; i++)
    {
        if(cnt[i]<=sum)
        {
            vis[i]=1;
            if(cnt[i]<sum)
                vec.push_back(i);
        }
    }
    int head=0;
    int tot=0;
    for(int i=0; i<n; i++)
    {
        if(a[i]<=m&&vis[a[i]])continue;
        if(head<vec.size()&&cnt[vec[head]]<sum&&(a[i]>m||cnt[a[i]]>sum))
        {
            tot++;
            if(a[i]<=m)
                cnt[a[i]]--;
            a[i]=vec[head];

            cnt[vec[head]]++;

            if(cnt[vec[head]]==sum)head++;
        }
    }
    printf("%d %d\n",sum,tot);
    for(int i=0; i<n; i++)printf("%d ",a[i]);
    return 0;
}
