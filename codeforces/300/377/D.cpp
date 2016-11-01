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
#define LL long long
#define pii pair<int,int>

int n,m;
int d[100005];
int a[100005];
int last[100005];
bool check(int t)
{
    memset(last,-1,sizeof(last));
    for(int i=1;i<=t;i++)
        last[d[i]]=i;
    vector<pii>vec;
    for(int i=1;i<=m;i++)vec.push_back(make_pair(last[i],i));
    sort(vec.begin(),vec.end());
    if(vec[0].first==-1)return false;
    int cnt=0;
    for(int i=0;i<vec.size();i++)
    {
        if(vec[i].first-1-cnt<a[vec[i].second])return false;
        cnt+=a[vec[i].second]+1;
    }
    return true;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&d[i]);
    for(int i=1;i<=m;i++)
        scanf("%d",&a[i]);
    int l=0,r=n+1;
    bool ok=false;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(check(mid))
        {
            ok=true;
            r=mid;
        }
        else
            l=mid+1;
    }
    if(ok)printf("%d\n",l);
    else printf("-1\n");
    return 0;
}
