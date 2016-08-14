#include<stdio.h>
#include<cmath>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<set>
#include<vector>
#include<map>
using namespace std;
struct point
{
    int x,y,z;
    void input()
    {
        scanf("%d%d%d",&x,&y,&z);
    }
    bool operator <(const point a)const
    {
        if(x==a.x)
        {
            if(y==a.y)
            {
                return z<a.z;
            }
            return y<a.y;
        }
        return x<a.x;
    }
};
point xmult(point u,point v)
{
    point ret;
    ret.x=u.y*v.z-v.y*u.z;
    ret.y=u.z*v.x-u.x*v.z;
    ret.z=u.x*v.y-u.y*v.x;
    return ret;
}
point subt(point u,point v)
{
    point ret;
    ret.x=u.x-v.x;
    ret.y=u.y-v.y;
    ret.z=u.z-v.z;
    return ret;
}
point pvec(point s1,point s2,point s3)
{
    return xmult(subt(s1,s2),subt(s2,s3));
}
int dist(point a,point b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z);
}
int n;
point p[202];
int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
point calvec(point a,point b,point c)
{
    point v=pvec(a,b,c);
    if(v.x==0)
    {
        if(v.y==0)
        {
            if(v.z==0)return v;
            else{v.z=1;return v;}
        }
        else
        {
            if(v.y<0){v.y*=-1;v.z*=-1;}
            int GD=gcd(v.y,abs(v.z));
            v.y/=GD;v.z/=GD;
            return v;
        }
    }
    else
    {
        if(v.x<0){v.x*=-1;v.y*=-1;v.z*=-1;}
        int GD=gcd(v.x,abs(v.y));
        GD=gcd(GD,abs(v.z));
        v.x/=GD;v.y/=GD;v.z/=GD;
        return v;
    }
}
pair<int,point> num[202];
bool equ(point a,point b)
{
    if(a.x==b.x&&a.y==b.y&&a.z==b.z)
        return true;
    return false;
}
int cnt;
long long ddd[202][202];
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        scanf("%d",&n);
        for(int i=0; i<n; i++)p[i].input();
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)ddd[i][j]=dist(p[i],p[j]);
        long long ans=0;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                cnt=0;
                for(int k=0; k<n; k++)
                {
                    if(k==i||k==j)continue;
                    if(dist(p[i],p[k])==dist(p[j],p[k]))
                    {
                        num[cnt++]=make_pair(dist(p[i],p[k]),calvec(p[i],p[j],p[k]));
                    }
                }
                if(cnt==0)continue;
                sort(num,num+cnt);
                int pre=0;
                int now=1;
                for(int k=1; k<=cnt; k++)
                {
                    if(k==cnt)
                    {
                        ans+=(long long)pre*now;
                        break;
                    }
                    if(num[k].first!=num[k-1].first)
                    {
                        ans+=(long long)now*pre;
                        pre=0;
                        now=1;
                    }
                    else
                    {
                        if(equ(num[k].second,num[k-1].second))
                        {
                            now++;
                        }
                        else
                        {
                            ans+=(long long)now*pre;
                            pre+=now;
                            now=1;
                        }
                    }
                }
            }
        }
        ans/=2;
        for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)for(int k=j+1;k<n;k++)
        {
            long long dis=ddd[i][j];
            if(ddd[j][k]!=dis)continue;
            if(ddd[i][k]!=dis)continue;
            for(int w=k+1;w<n;w++)
            {
                if(ddd[i][w]!=dis)continue;
                if(ddd[j][w]!=dis)continue;
                if(ddd[k][w]!=dis)continue;
                ans-=2;
            }
        }
        printf("Case #%d: %I64d\n",cas,ans);
    }
    return 0;
}
