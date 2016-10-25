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
#define LL long long
#define pii pair<int,int>
char str[30];
int len;
char ans[2][22];
int vis[26];
void output(int now,int fnl,int x,int y,int dir)
{
    ans[x][y]=str[now];
    if((now+1)%len==fnl)
        return ;
    if(dir==1)
    {
        if(y==len/2-1)
            output((now+1)%len,fnl,1,len/2-1,-1);
        else
            output((now+1)%len,fnl,x,y+1,1);
    }
    else
    {
        if(y==0)
            output((now+1)%len,fnl,1,0,1);
        else
            output((now+1)%len,fnl,x,y-1,-1);
    }
}
int main()
{
    scanf("%s",str);
    len=strlen(str);
    memset(vis,-1,sizeof(vis));
    char ch;
    int dis=0;
    bool flag=0;
    for(int i=0; i<len-1; i++)
    {
        if(str[i]==str[i+1])
        {
            flag=true;
            break;
        }
    }
    if(flag)
    {
        puts("Impossible");
        return 0;
    }
    int fst,scd;
    for(int i=0; i<len; i++)
    {
        if(vis[str[i]-'A']!=-1)
        {
            fst=vis[str[i]-'A'];
            scd=i;
            ch=str[i];
            dis=i-vis[str[i]-'A'];
            break;
        }
        else vis[str[i]-'A']=i;
    }
    int pos=(dis+1)/2-1;
    output(fst,scd,0,pos,-1);
    output(scd,fst,0,pos,1);
    printf("%s\n%s\n",ans[0],ans[1]);
    return 0;
}
