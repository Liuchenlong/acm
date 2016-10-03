#include <bits/stdc++.h>
using namespace std;

int n,m,k;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
bool intable(int x,int y)
{
    if(x>=0&&x<n&&y>=0&&y<m)return true;
    return false;
}
char tab[55][55];
bool vis[55][55];
set<pair<int,pair<int,int> > >s;
void bfs(int x,int y)
{
    queue<pair<int,int> >q;
    q.push(make_pair(x,y));
    vis[x][y]=1;
    int cnt=1;
    bool flag=true;
    while(!q.empty())
    {
        pair<int,int>head=q.front();
        if(head.first==0||head.first==n-1||head.second==0||head.second==m-1)
            flag=false;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx=head.first+dx[i];
            int ny=head.second+dy[i];
            if(intable(nx,ny)&&vis[nx][ny]==0&&tab[nx][ny]=='.')
            {
                cnt++;
                vis[nx][ny]=1;
                q.push(make_pair(nx,ny));
            }
        }
    }
    if(flag)
        s.insert(make_pair(cnt,make_pair(x,y)));
}
void del(int x,int y)
{
    queue<pair<int,int> >q;
    q.push(make_pair(x,y));
    vis[x][y]=1;
    while(!q.empty())
    {
        pair<int,int>head=q.front();
        tab[head.first][head.second]='*';
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx=head.first+dx[i];
            int ny=head.second+dy[i];
            if(intable(nx,ny)&&vis[nx][ny]==0&&tab[nx][ny]=='.')
            {
                vis[nx][ny]=1;
                q.push(make_pair(nx,ny));
            }
        }
    }
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++)
        scanf("%s",tab[i]);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(vis[i][j])continue;
            if(tab[i][j]=='.')
                {
                    bfs(i,j);
                }
        }
    }
    int ans=0;
    memset(vis,0,sizeof(vis));
    while(s.size()>k)
    {
        pair<int,pair<int,int> >p3=*s.begin();
        s.erase(s.begin());
        ans+=p3.first;
        del(p3.second.first,p3.second.second);
    }
    printf("%d\n",ans);
    for(int i=0;i<n;i++)
        printf("%s\n",tab[i]);
    return 0;
}
