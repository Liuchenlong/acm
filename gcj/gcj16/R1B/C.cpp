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

vector<string>sa,sb;
map<string,int>ma,mb;
struct node
{
    string a,b;
};
node p[1005];
const int MAXN=1010;
int uN,vN;//u,v数目
int g[MAXN][MAXN];
int linker[MAXN];
bool used[MAXN];
bool dfs(int u)//从左边开始找增广路径
{
    int v;
    for(v=0;v<vN;v++)//这个顶点编号从0开始，若要从1开始需要修改
      if(g[u][v]&&!used[v])
      {
          used[v]=true;
          if(linker[v]==-1||dfs(linker[v]))
          {//找增广路，反向
              linker[v]=u;
              return true;
          }
      }
    return false;//这个不要忘了，经常忘记这句
}
int hungary()
{
    int res=0;
    int u;
    memset(linker,-1,sizeof(linker));
    for(u=0;u<uN;u++)
    {
        memset(used,0,sizeof(used));
        if(dfs(u)) res++;
    }
    return res;
}
int main()
{
//    freopen("C-small-practice.in","r",stdin);
//    freopen("C-small-practice.out","w",stdout);
//    freopen("C-large-practice.in","r",stdin);
//    freopen("C-large-practice.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        memset(g,0,sizeof(g));
        sa.clear();
        sb.clear();
        ma.clear();
        mb.clear();
        int n;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            cin >> p[i].a >> p[i].b;
            sa.push_back(p[i].a);
            sb.push_back(p[i].b);
        }
        sort(sa.begin(),sa.end());
        sort(sb.begin(),sb.end());
        uN=unique(sa.begin(),sa.end())-sa.begin();
        vN=unique(sb.begin(),sb.end())-sb.begin();
        for(int i=0;i<uN;i++)
            ma[sa[i]]=i;
        for(int i=0;i<vN;i++)
            mb[sb[i]]=i;
        for(int i=0;i<n;i++)
        {
            g[ma[p[i].a]][mb[p[i].b]]=1;
        }
        int ans=n-(uN+vN-hungary());
        printf("Case #%d: %d\n",cas,ans);

    }
    return 0;
}
