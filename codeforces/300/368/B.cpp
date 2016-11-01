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

struct road
{
    int u,v,l;
};
road r[100005];
bool vis[100005];
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++)scanf("%d%d%d",&r[i].u,&r[i].v,&r[i].l);
    for(int i=0;i<k;i++)
    {
        int x;
        scanf("%d",&x);
        vis[x]=1;
    }
    int ans=-1;
    for(int i=0;i<m;i++)
    {
        if((vis[r[i].u]^vis[r[i].v])==1)
        {
            if(ans==-1)ans=r[i].l;
            else ans=min(ans,r[i].l);
        }
    }
    printf("%d\n",ans);
    return 0;
}
