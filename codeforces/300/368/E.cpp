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

int n,m,k;
int Q;
struct node
{
    int x,y,val;
};
vector<node>chain[2005];
int len[2005];
struct qry
{
    int type;
    int x1,y1,x2,y2;
};
qry q[1000005];
qry ask[2005];
long long pre[2005];
long long ctb[2005][2005];
int nask;
int lowbit(int x)
{
    return x&(-x);
}
struct BIT
{
    int n,m;
    long long a[2005][2005];
    void init(int N,int M)
    {
        n=N;
        m=M;
        memset(a,0,sizeof(a));
    }
    void add(int x,int y,long long info)
    {
        for(int i=x;i<=n;i+=lowbit(i))
            for(int j=y;j<=m;j+=lowbit(j))
            a[i][j]+=info;
    }
    long long qry(int x,int y)
    {
        long long sum=0;
        for(int i=x;i>0;i-=lowbit(i))
            for(int j=y;j>0;j-=lowbit(j))
            sum+=a[i][j];
        return sum;
    }
}b;
long long query(int x1,int y1,int x2,int y2)
{
    return b.qry(x2,y2)-b.qry(x1-1,y2)-b.qry(x2,y1-1)+b.qry(x1-1,y1-1);
}
bool flip[2005];
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<k;i++)
    {
        scanf("%d",&len[i]);
        for(int j=0;j<len[i];j++)
        {
            node p;
            scanf("%d%d%d",&p.x,&p.y,&p.val);
            chain[i].push_back(p);
        }
    }
    scanf("%d",&Q);
    for(int i=0;i<Q;i++)
    {
        char str[10];
        scanf("%s",str);
        if(str[0]=='S')
        {
            q[i].type=0;
            scanf("%d",&q[i].x1);
            q[i].x1--;
        }
        else
        {
            q[i].type=1;
            scanf("%d%d%d%d",&q[i].x1,&q[i].y1,&q[i].x2,&q[i].y2);
            ask[nask++]=q[i];
        }
    }
    b.init(n,m);
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<len[i];j++)
            b.add(chain[i][j].x,chain[i][j].y,chain[i][j].val);
        for(int j=0;j<nask;j++)
        {
            long long now=query(ask[j].x1,ask[j].y1,ask[j].x2,ask[j].y2);
            ctb[i][j]=now-pre[j];
            pre[j]=now;
        }
    }
    int pos=0;
    for(int i=0;i<Q;i++)
    {
        if(q[i].type==0)
            flip[q[i].x1]^=1;
        else
        {
            long long ans=0;
            for(int j=0;j<k;j++)
            {
                if(flip[j]==0)
                {
                    ans+=ctb[j][pos];
                }
            }
            printf("%I64d\n",ans);
            pos++;
        }
    }
    return 0;
}
