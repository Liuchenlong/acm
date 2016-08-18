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
const double pi=acos(-1.0);

int n;
struct obj
{
    int x1,x2,y;
    bool operator < (const obj a)const
    {
        if(y==a.y)
        {
            return x1<a.x1;
        }
        else
            return y<a.y;
    }
};
obj a[100005],b[100005];///a|,b-
int siza,sizb;
int x[300005],y[300005];
int sizx,sizy;
struct event
{
    int x,y,info;
    event() {}
    event(int xx,int yy,int ii)
    {
        x=xx;
        y=yy;
        info=ii;
    }
    bool operator <(const event a)const
    {
        if(x==a.x)
        {
            return y<a.y;
        }
        return x<a.x;
    }
};
event e[200005];
int cnte;
int A[300005];
int N;
int lowbit(int x)
{
    return x&(-x);
}
void add(int x,int info)
{
    for(int i=x; i<=N; i+=lowbit(i))
        A[i]+=info;
}
int qry(int x)
{
    int ans=0;
    for(int i=x; i>0; i-=lowbit(i))
    {
        ans+=A[i];
    }
    return ans;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        map<int,int>mx,my;
        sizx=0;
        sizy=0;
        siza=0;
        sizb=0;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            int x1,y1,x2,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            if(x1==x2)
            {
                if(y1>y2)swap(y1,y2);
                x[sizx++]=x1;
                y[sizy++]=y1;
                y[sizy++]=y2;
                a[siza].y=x1;
                a[siza].x1=y1;
                a[siza].x2=y2;
                siza++;
            }
            else
            {
                if(x1>x2)swap(x1,x2);
                y[sizy++]=y1;
                x[sizx++]=x1;
                x[sizx++]=x2;
                b[sizb].y=y1;
                b[sizb].x1=x1;
                b[sizb].x2=x2;
                sizb++;
            }
        }
        sort(x,x+sizx);
        sort(y,y+sizy);
        sizx=unique(x,x+sizx)-x;
        sizy=unique(y,y+sizy)-y;
        N=3*n+2;
        memset(A,0,sizeof(A));
        for(int i=0; i<sizx; i++)mx[x[i]]=i+1;
        for(int i=0; i<sizy; i++)my[y[i]]=i+1;
        for(int i=0; i<siza; i++)
        {
            a[i].y=mx[a[i].y];
            a[i].x1=my[a[i].x1];
            a[i].x2=my[a[i].x2];
        }
        for(int i=0; i<sizb; i++)
        {
            b[i].y=my[b[i].y];
            b[i].x1=mx[b[i].x1];
            b[i].x2=mx[b[i].x2];
        }
        cnte=0;
        for(int i=0; i<siza; i++)
        {
            e[cnte++]=event(a[i].x1,a[i].y,1);
            e[cnte++]=event(a[i].x2+1,a[i].y,-1);
        }
        sort(e,e+cnte);
        sort(a,a+siza);
        sort(b,b+sizb);
        long long sum=0;
        int pos=0;
        for(int i=0; i<sizb; i++)
        {
            while(pos<cnte&&e[pos].x<=b[i].y)
            {
                add(e[pos].y,e[pos].info);
                pos++;
            }
            sum+=qry(b[i].x2)-qry(b[i].x1-1);
        }
        cnte=0;
        for(int i=0; i<siza; i++)
        {
            e[cnte++]=event(a[i].y,a[i].x1,1);
            e[cnte++]=event(a[i].y,a[i].x2,-1);
        }
        sort(e,e+cnte);
        int res=0;
        for(int i=0; i<cnte; i++)
        {
            if(e[i].info==1)
            {
                sum+=res;
                res++;
            }
            else
                res--;
        }
        cnte=0;
        swap(a,b);
        swap(siza,sizb);
        for(int i=0; i<siza; i++)
        {
            e[cnte++]=event(a[i].y,a[i].x1,1);
            e[cnte++]=event(a[i].y,a[i].x2,-1);
        }
        sort(e,e+cnte);
        res=0;
        for(int i=0; i<cnte; i++)
        {
            if(e[i].info==1)
            {
                sum+=res;
                res++;
            }
            else
                res--;
        }
        printf("%I64d\n",sum);
    }
    return 0;
}
