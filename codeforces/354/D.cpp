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
int n,m;
bool vis[1005][1005][4];
int step[1005][1005][4];
int state[1005][1005][4];
char table[1005][1005];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int next[1<<4];
bool intable(int x,int y)
{
    if(x>=0&&x<n&&y>=0&&y<m)
        return true;
    return false;
}
int getstate(char ch)
{
    if(ch=='*')
        return 0;
    if(ch=='^')
        return 1<<3;
    if(ch=='v')
        return 1<<1;
    if(ch=='<')
        return 1<<2;
    if(ch=='>')
        return 1<<0;
    if(ch=='|')
        return (1<<3)|(1<<1);
    if(ch=='-')
        return (1<<0)|(1<<2);
    if(ch=='L')
        return 15^(1<<2);
    if(ch=='R')
        return 15^(1<<0);
    if(ch=='U')
        return 15^(1<<3);
    if(ch=='D')
        return 15^(1<<1);
    if(ch=='+')
        return 15;
}
void init()
{
    next[getstate('+')]=getstate('+');
    next[getstate('-')]=getstate('|');
    next[getstate('|')]=getstate('-');
    next[getstate('^')]=getstate('>');
    next[getstate('>')]=getstate('v');
    next[getstate('v')]=getstate('<');
    next[getstate('<')]=getstate('^');
    next[getstate('L')]=getstate('U');
    next[getstate('U')]=getstate('R');
    next[getstate('R')]=getstate('D');
    next[getstate('D')]=getstate('L');
    next[getstate('*')]=getstate('*');
}
pair<pair<int,int>,int> mp3(int a,int b,int c)
{
    return make_pair(make_pair(a,b),c);
}
void bfs(int x,int y)
{
    queue< pair<pair<int,int>,int> >Q;
    Q.push(mp3(x,y,0));
    vis[x][y][0]=1;
    step[x][y][0]=0;
    while(!Q.empty())
    {
        pair<pair<int,int>,int>head=Q.front();
        Q.pop();
        int sx=head.first.first;
        int sy=head.first.second;
        int stt=head.second;
        if(vis[sx][sy][(stt+1)%4]==0)
        {
            vis[sx][sy][(stt+1)%4]=1;
            step[sx][sy][(stt+1)%4]=step[sx][sy][stt]+1;
            Q.push(mp3(sx,sy,(stt+1)%4));
        }
        for(int i=0;i<4;i++)
        {
            int nx=sx+dx[i];
            int ny=sy+dy[i];
            if(!intable(nx,ny))
                continue;
            if(vis[nx][ny][stt])
                continue;
            if(((1<<i)&state[sx][sy][stt])&&((1<<((i+2)%4))&(state[nx][ny][stt])))
            {
                vis[nx][ny][stt]=1;
                step[nx][ny][stt]=step[sx][sy][stt]+1;
                Q.push(mp3(nx,ny,stt));
            }
        }
    }
}
int main()
{
    memset(step,-1,sizeof(step));
    init();
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%s",table[i]);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int k=0;k<4;k++)
            {
                if(k==0)
                state[i][j][k]=getstate(table[i][j]);
                else
                state[i][j][k]=next[state[i][j][k-1]];
            }
        }
    }
    int x,y;
    int ex,ey;
    scanf("%d%d%d%d",&x,&y,&ex,&ey);
    x--;
    y--;
    ex--;
    ey--;
    bfs(x,y);
    int ans=-1;
    for(int i=0;i<4;i++)
    {
        if(step[ex][ey][i]!=-1)
        {
            if(ans==-1)
                ans=step[ex][ey][i];
            else
                ans=min(ans,step[ex][ey][i]);
        }
    }
    printf("%d\n",ans);
    return 0;
}
