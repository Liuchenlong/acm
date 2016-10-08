#include <bits/stdc++.h>

using namespace std;
const double eps=1e-8;
bool zeros(double x)
{
    return fabs(x)<=eps;
}
int sign(double x)
{
    if(zeros(x))return 0;
    if(x>0)return 1;
    return -1;
}
struct point
{
    double x,y;
    double tht;
    point() {}
    point(double xx,double yy)
    {
        x=xx;
        y=yy;
    }
    void output()
    {
        printf("(%f,%f)\n",(double)x,(double)y);
    }
    void input()
    {
        scanf("%lf%lf",&x,&y);
    }
    point operator -(const point &b)
    {
        return point(x - b.x, y - b.y);
    }
    point operator +(const point &b)
    {
        return point(x + b.x, y + b.y);
    }
    double operator ^(const point &b)
    {
        return x*b.y - y*b.x;
    }
    double operator *(const point &b)
    {
        return x*b.x + y*b.y;
    }
};
point p[88];
point pq[222];
int tot;
point O;
double dist(point a,point b)
{
    return sqrt((b-a)*(b-a));
}
bool cmp(point a,point b)
{
    return a.tht<b.tht;
}
double dp[202][88];
int calcnt[222][222];
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        int n;
        double L;
        scanf("%d%lf",&n,&L);
        for(int i=0; i<n; i++)p[i].input();
        printf("Case #%d: ",cas);
        int ans=1;
        for(int i=0; i<n; i++)
        {
            tot=0;
            for(int j=0; j<n; j++)
            {
                if(j==i)continue;
                if(sign(p[j].x-p[i].x)>=0)
                {
                    pq[tot]=p[j];
                    pq[tot].tht=atan2(p[j].y-p[i].y,p[j].x-p[i].x);
                    tot++;
                }
            }
            O=p[i];
            sort(pq,pq+tot,cmp);///-|
            for(int j=0; j<tot; j++)
            {
                for(int k=j+1; k<tot; k++)
                {
                    int cnt=0;
                    for(int w=j+1; w<=k; w++)
                    {
                        if(sign((pq[k]-pq[j])^(pq[w]-pq[j]))>=0)
                            cnt++;
                    }
                    calcnt[j][k]=cnt;
                }
            }
            for(int j=0;j<tot;j++)for(int k=0;k<=tot;k++)dp[j][k]=1e60;
            for(int j=0; j<tot; j++)
            {
                dp[j][1]=dist(pq[j],O)*2;
                for(int k=1; k<=tot; k++)
                {
                    if(dp[j][k]<1e50)
                    for(int w=j+1; w<tot; w++)
                    {
                        dp[w][k+calcnt[j][w]]=min(dp[w][k+calcnt[j][w]],dp[j][k]-dist(pq[j],O)+dist(pq[j],pq[w])+dist(pq[w],O));
                    }
                }
            }
            for(int j=0; j<tot; j++)for(int k=0; k<=tot; k++)
                {
                    if(sign(dp[j][k]-L)>0)continue;
                    ans=max(ans,k+1);
                }
        }
        printf("%d\n",ans);
    }
    return 0;
}
