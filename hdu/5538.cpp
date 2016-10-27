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
#define zero(x) (fabs(x)<eps)
#define sign(x) ((x)<-eps?-1:((x)>eps))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) (a<0?-a:a)

struct tow
{
    int x,y;
    int h;
};
bool cmp(tow a,tow b)
{
    if(a.h==b.h)
    {
        if(a.x==b.x)
        return a.y<b.y;
        else
        return a.x<b.x;
    }
    return a.h>b.h;
}
vector <tow> vec;
int n,m;
bool vis[55][55];
int num[55][55];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
bool intable(int x,int y)
{
    if(x>=0&&x<n&&y>=0&&y<m)
    return true;
    return false;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        vec.clear();
        memset(vis,0,sizeof(vis));
        memset(num,0,sizeof(num));
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                scanf("%d",&num[i][j]);
                if(num[i][j])
                {
                    tow tmp;
                    tmp.x=i;
                    tmp.y=j;
                    tmp.h=num[i][j];
                    vec.push_back(tmp);
                }
            }
        }
        sort(vec.begin(),vec.end(),cmp);

        int ans=0;
        for(int i=0;i<vec.size();i++)
        {
            ans=ans+1+4*vec[i].h;
            for(int j=0;j<4;j++)
            {
                int nx=vec[i].x+dx[j];
                int ny=vec[i].y+dy[j];

                if(intable(nx,ny)&&vis[nx][ny])
                ans-=vec[i].h*2;
            }
            vis[vec[i].x][vec[i].y]=1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
