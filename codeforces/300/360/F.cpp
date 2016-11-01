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
#include<bitset>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
const int maxn=1005;
struct road
{
    int f,t;
    int w;
    int pos;
    bool operator <(const road a)const
    {
        return w>a.w;
    }
}r[maxn*maxn];
int pre[maxn];
int w[maxn];
int init()
{
    memset(w,0,sizeof(w));
    for(int i=0;i<maxn;i++)
        pre[i]=i;
}
int find(int x)
{
    if(x!=pre[x])
    {
        int fx=find(pre[x]);
        w[x]^=w[pre[x]];
        pre[x]=fx;
    }
    return pre[x];
}
bool Union(int x,int y)
{
    int fx=find(x);
    int fy=find(y);
    if(fx==fy)
    {
        if(w[x]==w[y])
            return true;
        return false;
    }
    pre[fx]=fy;
    w[fx]=w[x]^w[y]^1;
    return false;
}

int main()
{
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&r[i].f,&r[i].t,&r[i].w);
        r[i].f--;
        r[i].t--;
        r[i].pos=i;
    }
    sort(r,r+m);
    for(int i=0;i<q;i++)
    {
        init();
        int L,R;
        int flag=0;
        scanf("%d%d",&L,&R);
        L--;
        R--;
        for(int j=0;j<m;j++)
        {
            if(r[j].pos<L||r[j].pos>R)continue;
            if(Union(r[j].f,r[j].t))
            {
                printf("%d\n",r[j].w);
                flag=1;
                break;
            }
        }
        if(!flag)
            printf("-1\n");
    }
    return 0;
}
