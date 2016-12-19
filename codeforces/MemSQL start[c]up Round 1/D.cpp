#include<bits/stdc++.h>
using namespace std;
#define eps 1e-8

int r,c,n;
int pre[3005*6005];
void init()
{
    for(int i=1; i<=3000*6000; i++)
        pre[i]=i;
}
int find(int x)
{
    if(pre[x]!=x)
    {
        pre[x]=find(pre[x]);
    }
    return pre[x];
}
void Union(int x,int y)
{
    int fx=find(x);
    int fy=find(y);
    pre[fx]=fy;
}
bool has[3005][6005];
bool intable(int x,int y)
{
    if(x>=0&&x<r&&y>=0&&y<c+c)
        return true;
    return false;
}
int dx[8]= {-1,-1,0,1,1,1,0,-1};
int dy[8]= {0,1,1,1,0,-1,-1,-1};
bool check(int x1,int y1,int x2,int y2)
{
    bool mid=false;
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            int nx1=x1+dx[i],ny1=y1+dy[i];
            if(ny1==-1)ny1=2*c-1;
            if(ny1==2*c)ny1=0;
            int nx2=x2+dx[j],ny2=y2+dy[j];
            if(ny2==-1)ny2=2*c-1;
            if(ny2==2*c)ny2=0;
            if(intable(nx1,ny1)&&intable(nx2,ny2)&&has[nx1][ny1]&&has[nx2][ny2])
            {
                if(find(nx1*c*2+ny1)==find(nx2*c*2+ny2))
                    mid=true;
            }
        }
    }
    if(mid)
    {
        return true;
    }
    for(int i=0; i<8; i++)
    {
        int nx=x2+dx[i];
        int ny=y2+dy[i];
        if(ny==-1)ny=2*c-1;
        if(ny==2*c)ny=0;
        if(intable(nx,ny)&&has[nx][ny])
            Union(x2*c*2+y2,nx*c*2+ny);
    }
    for(int i=0; i<8; i++)
    {
        int nx=x1+dx[i];
        int ny=y1+dy[i];
        if(ny==-1)ny=2*c-1;
        if(ny==2*c)ny=0;
        if(intable(nx,ny)&&has[nx][ny])
            Union(x1*c*2+y1,nx*c*2+ny);
    }
    has[x1][y1]=true;
    has[x2][y2]=true;
    return false;
}
int main()
{
    scanf("%d%d%d",&r,&c,&n);
    int cnt=0;
    init();
    for(int i=0; i<n; i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x--;
        y--;
        if(!check(x,y,x,y+c))
            cnt++;
    }
    if(c==1)
    {
        printf("0\n");
        return 0;
    }
    printf("%d\n",cnt);
    return 0;
}
