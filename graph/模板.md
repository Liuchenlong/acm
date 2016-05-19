#图论
##最小生成树
###kruskal(poj1258)
```c
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
//#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
#define eps 1e-8
struct road
{
    int f,t;
    int v;
};
bool cmp(road a,road b)
{
    return a.v<b.v;
}
vector <road>vec;
int pre[505];
void init()
{
    for(int i=0; i<=500; i++)
        pre[i]=i;
}
int find(int x)
{
    if(pre[x]!=x)
    {
        int fx=find(pre[x]);
        pre[x]=fx;
    }
    return pre[x];
}
void unite(int x,int y)
{
    int fx=find(x);
    int fy=find(y);
    pre[fx]=fy;
}
int cost[505][505];
int n;
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        vec.clear();
        init();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                scanf("%d",&cost[i][j]);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                road tmp;
                tmp.f=i;
                tmp.t=j;
                tmp.v=cost[i][j];
                vec.push_back(tmp);
            }
        }
        sort(vec.begin(),vec.end(),cmp);
        int ans=0;
        int num=0;
        for(int i=0;i<vec.size();i++)
        {
            if(num==n-1)
                break;
            if(find(vec[i].f)!=find(vec[i].t))
            {
                unite(vec[i].f,vec[i].t);
                ans+=vec[i].v;
                num++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
```
##拓扑排序
```c
int con[33][33];
int n,m;
int pre[33];
bool vis[33];
vector <int>vec;
int tosort()
{
    vec.clear();
    memset(vis,0,sizeof(vis));
    int tpre[33];
    for(int i=0; i<n; i++)
        tpre[i]=pre[i];
    int flag=0;
    for(int i=0; i<n; i++)
    {
        int num=0;
        int ans;
        for(int j=0; j<n; j++)
        {
            if(tpre[j]==0&&!vis[j])
            {
                num++;
                ans=j;
            }
        }
        if(num>1)
        {
            flag=1;
        }
        if(num==0)
            return -1;
        vis[ans]=1;
        vec.push_back(ans);
        for(int j=0; j<n; j++)
        {
            if(con[ans][j])
                tpre[j]--;
        }
    }
    return flag;
}
```
##最短路
###dijkstra
```c
void dijkstra(int x)
{
    memset(vis,0,sizeof(vis));
    for(int i=0; i<=n; i++)
        d[i]=1e9;
    d[x]=0;
    for(int k=0; k<n; k++)
    {
        long long mindist=1e9;
        int chos=0;
        for(int i=0; i<n; i++)
        {
            if(vis[i]==0&&(d[i]<mindist))
            {
                mindist=d[i];
                chos=i;
            }
        }
        vis[chos]=1;
        for(int i=0; i<n; i++)
        {
            if(vis[i]==false&&d[i]>d[chos]+cost[chos][i])
            {
                    d[i]=d[chos]+cost[chos][i];
            }
        }
    }
}
```
###SPFA(shortest path fast algorithm)
```c
int d[3005][3005];//距离
bool vis[3005];//是否在队列中
int inq[3005];//入队次数
vector<int>road[3005];
void spfa(int x)
{
    memset(vis,0,sizeof(vis));
    for(int i=0; i<n; i++)
        d[x][i]=inf;
    d[x][x]=0;
    queue<int>Q;
    Q.push(x);
    vis[x]=1;
    inq[x]=1;
    while(!Q.empty())
    {
        int head=Q.front();
        Q.pop();
        vis[head]=0;
        for(int i=0; i<road[head].size(); i++)
        {
            int next=road[head][i];
            if(d[x][next]>d[x][head]+cost[head][next])
            {
                d[x][next]=d[x][head]+cost[head][next];
                if(vis[next]==0)
                {
                    vis[next]=1;
                    inq[next]++;
                    Q.push(next);
                    if(inq[next]>n)//入队次数>n说明有负环
                        return ;
                }
            }
        }
    }
}
```
###bellman-ford
```c
//判正环
bool bellman(int x)
{
    memset(d,0,sizeof(d));
    d[x]=v;
    for(int i=0;i<n;i++)
    {
        int flag=0;
        for(int j=0;j<rnum;j++)
        {
            if(d[r[j].t]<(d[r[j].f]-r[j].c)*r[j].r)
            {
                flag=1;
                d[r[j].t]=(d[r[j].f]-r[j].c)*r[j].r;
            }
        }
        if(!flag)
            break;
    }
    for(int i=0;i<rnum;i++)
    {
        if(d[r[i].t]<(d[r[i].f]-r[i].c)*r[i].r)
            return true;
    }
    return false;
}
```
###floyd
```c
void floyd()
{
    for(int k=0; k<n; k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(i!=j&&dist[i][j]>dist[i][k]+dist[k][j])
                    dist[i][j]=dist[i][k]+dist[k][j];
}
```

##二分图匹配
###匈牙利算法
```c
/* **************************************************************************
//二分图匹配（匈牙利算法的DFS实现）
//初始化：g[][]两边顶点的划分情况
//建立g[i][j]表示i->j的有向边就可以了，是左边向右边的匹配
//g没有边相连则初始化为0
//uN是匹配左边的顶点数，vN是匹配右边的顶点数
//调用：res=hungary();输出最大匹配数
//优点：适用于稠密图，DFS找增广路，实现简洁易于理解
//时间复杂度:O(VE)
//***************************************************************************/
//顶点编号从0开始的
const int MAXN=510;
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
```
##二分图带权匹配
###KM算法
```c
/*其实在求最大 最小的时候只要用一个模板就行了,把边的权值去相反数即可得到另外一个.求结果的时候再去相反数即可*/
/*最大最小有一些地方不同。。*/
#include <iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
//赤裸裸的模板啊。
const int maxn = 101;
const int INF = (1<<31)-1;
int w[maxn][maxn];
int lx[maxn],ly[maxn]; //顶标
int linky[maxn];
int visx[maxn],visy[maxn];
int slack[maxn];
int nx,ny;
bool find(int x)
{
    visx[x] = true;
    for(int y = 0; y < ny; y++)
    {
        if(visy[y])
            continue;
        int t = lx[x] + ly[y] - w[x][y];
        if(t==0)
        {
            visy[y] = true;
            if(linky[y]==-1 || find(linky[y]))
            {
                linky[y] = x;
                return true;        //找到增广轨
            }
        }
        else if(slack[y] > t)
            slack[y] = t;
    }
    return false;                   //没有找到增广轨（说明顶点x没有对应的匹配，与完备匹配(相等子图的完备匹配)不符）
}

int KM()                //返回最优匹配的值
{
    int i,j;

    memset(linky,-1,sizeof(linky));
    memset(ly,0,sizeof(ly));
    for(i = 0; i < nx; i++)
        for(j = 0,lx[i] = -INF; j < ny; j++)
            if(w[i][j] > lx[i])
                lx[i] = w[i][j];
    for(int x = 0; x < nx; x++)
    {
        for(i = 0; i < ny; i++)
            slack[i] = INF;
        while(true)
        {
            memset(visx,0,sizeof(visx));
            memset(visy,0,sizeof(visy));
            if(find(x))                     //找到增广轨，退出
                break;
            int d = INF;
            for(i = 0; i < ny; i++)          //没找到，对l做调整(这会增加相等子图的边)，重新找
            {
                if(!visy[i] && d > slack[i])
                    d = slack[i];
            }
            for(i = 0; i < nx; i++)
            {
                if(visx[i])
                    lx[i] -= d;
            }
            for(i = 0; i < ny; i++)
            {
                if(visy[i])
                     ly[i] += d;
                else
                     slack[i] -= d;
            }
        }
    }
    int result = 0;
    for(i = 0; i < ny; i++)
    if(linky[i]>-1)
        result += w[linky[i]][i];
    return result;
}

int main()
{
    while(true)
    {
        scanf("%d%d",&nx,&ny);
        int a,b,c;
        while(scanf("%d%d%d",&a,&b,&c),a+b+c)
        {
            w[a][b]=c;
        }
        printf("%d\n",KM());
        break;
    }
    return 0;
}
```
