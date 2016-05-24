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
int n,m;
char table[105][105];
int check(int x,int y)
{
    if(table[x][y]=='^')
    {
        for(int i=x-1; i>=0; i--)
        {
            if(table[i][y]!='.')
                return 0;
        }
        for(int i=x+1; i<n; i++)
        {
            if(table[i][y]!='.')
                return 1;
        }
        for(int j=y+1; j<m; j++)
            if(table[x][j]!='.')
                return 1;
        for(int j=y-1; j>=0; j--)
            if(table[x][j]!='.')
                return 1;
        return -1;
    }
    if(table[x][y]=='v')
    {
        for(int i=x+1; i<n; i++)
        {
            if(table[i][y]!='.')
                return 0;
        }
        for(int i=x-1; i>=0; i--)
        {
            if(table[i][y]!='.')
                return 1;
        }
        for(int j=y+1; j<m; j++)
            if(table[x][j]!='.')
                return 1;
        for(int j=y-1; j>=0; j--)
            if(table[x][j]!='.')
                return 1;
        return -1;
    }
    if(table[x][y]=='>')
    {
        for(int j=y+1; j<m; j++)
            if(table[x][j]!='.')
                return 0;
        for(int i=x-1; i>=0; i--)
        {
            if(table[i][y]!='.')
                return 1;
        }
        for(int i=x+1; i<n; i++)
        {
            if(table[i][y]!='.')
                return 1;
        }

        for(int j=y-1; j>=0; j--)
            if(table[x][j]!='.')
                return 1;
        return -1;
    }
    if(table[x][y]=='<')
    {
        for(int j=y-1; j>=0; j--)
            if(table[x][j]!='.')
                return 0;
        for(int i=x-1; i>=0; i--)
        {
            if(table[i][y]!='.')
                return 1;
        }
        for(int i=x+1; i<n; i++)
        {
            if(table[i][y]!='.')
                return 1;
        }
        for(int j=y+1; j<m; j++)
            if(table[x][j]!='.')
                return 1;

        return -1;
    }
}
int main()
{
//    freopen("A-small-practice.in","r",stdin);
//    freopen("A-small-practice.out","w",stdout);
//    freopen("A-large-practice.in","r",stdin);
//    freopen("A-large-practice.out","w",stdout);
//    freopen("data.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        scanf("%d%d",&n,&m);
        for(int i=0; i<n; i++)
            scanf("%s",table[i]);
        int flag=0;
        int ans=0;
        for(int i=0; i<n; i++)for(int j=0; j<m; j++)
            {
                if(table[i][j]=='.')
                    continue;
                else
                {
                    if(check(i,j)==0);
                    else if(check(i,j)==1)ans++;
                    else
                        flag=1;
                }
            }
            printf("Case #%d: ",cas);
            if(flag)
                printf("IMPOSSIBLE\n");
            else
                printf("%d\n",ans);
    }
    return 0;
}
