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
char table[1005][1005];
int num[1005][1005];
int dx[4]= {0,1,0,-1};
int dy[4]= {1,0,-1,0};
map <int,int>mp;
bool intable(int x,int y)
{
    if(x>=0&&x<n&&y>=0&&y<m)
        return true;
    return false;
}
int xx[1000005];
int yy[1000005];
int bfs(int x,int y,int pos)
{
    xx[0]=x;
    yy[0]=y;
    int l=0,r=1;
    num[x][y]=pos;
    int ans=1;
    while(l<r)
    {
        for(int i=0; i<4; i++)
        {
            int nx=xx[l]+dx[i];
            int ny=yy[l]+dy[i];
            if(intable(nx,ny)&&table[nx][ny]=='.'&&num[nx][ny]==0)
            {
                xx[r]=nx;
                yy[r]=ny;
                r++;
                num[nx][ny]=pos;
                ans++;
            }
        }
        l++;
    }
    return ans;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++)
        scanf("%s",table[i]);
    int pos=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(table[i][j]=='.'&&num[i][j]==0)
            {
                int tnum=bfs(i,j,++pos);
                mp[pos]=tnum;
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(table[i][j]=='.')
                printf(".");
            else
            {
                int tmp=1;
                set <int> st;
                for(int k=0; k<4; k++)
                {
                    int nx=i+dx[k];
                    int ny=j+dy[k];
                    if(intable(nx,ny)&&table[nx][ny]=='.')
                        st.insert(num[nx][ny]);
                }
                while(st.size())
                {
                    tmp=tmp+mp[*st.begin()];
                    st.erase(st.begin());
                }
                printf("%d",tmp%10);
            }
        }
        printf("\n");
    }
    return 0;
}
