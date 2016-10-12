#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
#define eps 1e-8

///注意平行,常函数等情况
struct line
{
    double k,b;
    line(){}
    line(double K,double B)
    {
        k=K;
        b=B;
    }
    double get(double x)
    {
        return k*x+b;
    }
    void output()
    {
        printf("%f x + %f\n",k,b);
    }
};
struct Convex_Hull_up
{
    int siz;
    line L[200005];
    void init()
    {
        siz=0;
        L[siz++]=line(0,0);
    }
    bool is_bad(int one,int two,int three)//目前凸包集为xxx12,要将3插入,判断是否删除2
    {
        line l1=L[one],l2=L[two],l3=L[three];
        return (l2.b-l1.b)*(l1.k-l3.k)>=(l3.b-l1.b)*(l1.k-l2.k);//我这样肯定可以！
    }
    void insert(line l)//斜率从小到大
    {
        L[siz++]=l;
        while(siz>=3&&is_bad(siz-3,siz-2,siz-1))
        {
            L[siz-2]=L[siz-1];
            siz--;
        }
    }
    double query(double x)//查询横坐标为x的最大值
    {
        int l=0,r=siz-1;
        while(l<r)
        {
            int mid=(l+r)/2;
            if(L[mid].get(x)<=L[mid+1].get(x))
                l=mid+1;
            else
                r=mid;
        }
        return L[l].get(x);
    }
};
struct Convex_Hull_down
{
    int siz;
    line L[200005];
    void init()
    {
        siz=0;
        L[siz++]=line(1e9,0);
    }
    bool is_bad(int one,int two,int three)//目前凸包集为xxx12,要将3插入,判断是否删除2
    {
        line l1=L[one],l2=L[two],l3=L[three];
        return (l2.b-l1.b)*(l1.k-l3.k)>=(l3.b-l1.b)*(l1.k-l2.k);//我这样肯定可以！
    }
    void insert(line l)//斜率从大到小
    {
        L[siz++]=l;
        while(siz>=3&&is_bad(siz-3,siz-2,siz-1))
        {
            L[siz-2]=L[siz-1];
            siz--;
        }
    }
    double query(double x)//查询横坐标为x的最小值
    {
        int l=0,r=siz-1;
        while(l<r)
        {
            int mid=(l+r)/2;
            if(L[mid].get(x)>L[mid+1].get(x))
                l=mid+1;
            else
                r=mid;
        }
        return L[l].get(x);
    }
};
Convex_Hull_up cv1;
Convex_Hull_down cv2;
int n;
long long t[100005],v[100005];
pair<long long,long long>pr[100005];
pair<long long,long long>pq[100005];
int tot;
double gettim(line a,line b)
{
    return (b.b-a.b)/(a.k-b.k);
}

int main()
{
    freopen("cheetahs.in","r",stdin);
    freopen("my.out","w",stdout);
    while(scanf("%d",&n),n)
    {
        long long mt=0;
        for(int i=0;i<n;i++)
        {
            scanf("%I64d%I64d",&t[i],&v[i]);
            pr[i]=make_pair(v[i],-t[i]);
            mt=max(mt,t[i]);
        }
        sort(pr,pr+n);
        cv1.init();
        cv1.insert(line(0,0));
        for(int i=0;i<n;i++)
        {
            cv1.insert(line(1.0*pr[i].first,1.0*pr[i].first*pr[i].second));
        }
        for(int i=0;i<n;i++)
        {
            pr[i]=make_pair(-v[i],t[i]);
        }
        sort(pr,pr+n);
        cv2.init();
        cv2.insert(line(1e9,0));
        for(int i=0;i<n;i++)
        {
            cv2.insert(line(-1.0*pr[i].first,1.0*pr[i].first*pr[i].second));
        }
        double ans=cv1.query(mt)-cv2.query(mt);
        for(int i=1;i<cv1.siz-1;i++)
        {
            double tim=gettim(cv1.L[i],cv1.L[i+1]);
            if(tim>=mt)
            ans=min(ans,cv1.query(tim)-cv2.query(tim));
        }
        for(int i=1;i<cv2.siz-1;i++)
        {
            double tim=gettim(cv2.L[i],cv2.L[i+1]);
            if(tim>=mt)
            ans=min(ans,cv1.query(tim)-cv2.query(tim));
        }
        printf("%.3f\n",ans);
    }
    return 0;
}
