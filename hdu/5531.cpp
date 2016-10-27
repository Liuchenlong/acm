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
#define eps 1e-6
#define zero(x) (fabs(x)<eps)
#define sign(x) ((x)<-eps?-1:((x)>eps))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) (a<0?-a:a)
const double pi=acos(-1.0);
struct seg
{
    double l,r;
};
vector <seg> vec;
struct point
{
    double x,y;
    void input()
    {
        scanf("%lf%lf",&x,&y);
    }
};
double dist(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double d[10005];
void get(double l,double r,int pos)
{
    if(pos==0)
    {
        seg tmp;
        tmp.l=l;
        tmp.r=r;
        vec.push_back(tmp);
        return ;
    }
    else
    {
        get(MAX(d[pos-1]-r,0),MIN(d[pos-1]-l,d[pos-1]),pos-1);
        return ;
    }
}
point p[10005];
int n;
double cal(double r)
{
    double ans=r*r;
    double tmp=r;
    for(int i=1; i<n; i++)
    {
        tmp=d[i-1]-tmp;
        ans=ans+tmp*tmp;
    }
    return ans;
}
bool check(double x)
{
    double tmp=x;
    for(int i=1; i<n; i++)
    {
        tmp=d[i-1]-tmp;
        if(tmp<-eps)
        return false;
    }
    if(fabs(tmp+x-d[n-1])>eps)
    return false;

    return true;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        vec.clear();
        scanf("%d",&n);
        for(int i=0; i<n; i++)
            p[i].input();
        for(int i=0; i<n; i++)
        {
            d[i]=dist(p[i],p[(i+1)%n]);
        }
        if(n%2==1)
        {
            double sum=0.0;
            for(int i=0; i<n; i++)
            {
                if(i&1)
                    sum=sum-d[i];
                else
                    sum=sum+d[i];
            }
            if(sum<-eps)
            {
                printf("IMPOSSIBLE\n");
                continue;
            }
            double R=sum/2.0;
            if(check(R))
            {
                double ans=cal(R);
                printf("%.2f\n",pi*ans);
                printf("%.2f\n",R);
                for(int i=1; i<n; i++)
                {
                    R=d[i-1]-R;
                    printf("%.2f\n",R);
                }
            }
            else
            {
                printf("IMPOSSIBLE\n");
            }
            continue;
        }
        double tmp=0.0;
        for(int i=0;i<n;i++)
        {
            if(i&1)
            tmp+=d[i];
            else
            tmp-=d[i];
        }
        if(!zero(tmp))
        {
            printf("IMPOSSIBLE\n");
            continue;
        }
        get(0,d[n-1],n-1);
        double L=0.0,R=99999.0;
        for(int i=0; i<vec.size(); i++)
        {
            L=MAX(L,vec[i].l);
            R=MIN(R,vec[i].r);
        }
        if(R-L<-eps)
        {
            printf("IMPOSSIBLE\n");
        }
        else
        {
            while(R-L>eps)
            {
                double mid=(L+R)/2.0;
                double midmid=(mid+R)/2.0;

                double rmid=cal(mid);
                double rmidmid=cal(midmid);
                if(rmid<rmidmid)
                    R=midmid;
                else
                    L=mid;
            }
            double ans=cal(L);
            printf("%.2f\n",pi*ans);
            printf("%.2f\n",L);
            for(int i=1; i<n; i++)
            {
                L=d[i-1]-L;
                printf("%.2f\n",L);
            }
        }
    }
    return 0;
}
