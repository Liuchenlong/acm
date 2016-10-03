#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
using namespace std;
#define eps 1e-8
char sa[11],sb[11],sc[11];
int la,lb,lc;
bool vis[5];
bool viss[10];
int num[5];
int ans;
long long get(char str[],int len)
{
    long long sum=0;
    for(int i=0;i<len;i++)
        sum=sum*10+num[str[i]-'A'];
    return sum;
}

void dfs(int pos)
{
    if(pos==5)
    {
        if(la>1&&num[sa[0]-'A']==0)return ;
        if(lb>1&&num[sb[0]-'A']==0)return ;
        if(lc>1&&num[sc[0]-'A']==0)return ;
        long long na=get(sa,la),nb=get(sb,lb),nc=get(sc,lc);
        if(na+nb==nc)ans++;
        if(na-nb==nc)ans++;
        if(na*nb==nc)ans++;
        if(nb*nc==na&&nb!=0)ans++;
        return ;
    }
    for(int i=0;i<10;i++)
    {
        if(viss[i])continue;
        num[pos]=i;
        viss[i]=1;
        dfs(pos+1);
        viss[i]=0;
    }
}
int c[10];
int main()
{
    c[0]=1;
    c[1]=6;
    c[2]=42;
    c[3]=6*7*8;
    c[4]=6*7*8*9;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s%s%s",sa,sb,sc);
        la=strlen(sa);
        lb=strlen(sb);
        lc=strlen(sc);
        memset(vis,0,sizeof(vis));
        for(int i=0;i<la;i++)vis[sa[i]-'A']=1;
        for(int i=0;i<lb;i++)vis[sb[i]-'A']=1;
        for(int i=0;i<lc;i++)vis[sc[i]-'A']=1;
        ans=0;
        dfs(0);
        int cnt=0;
        for(int i=0;i<5;i++)if(vis[i]==0)cnt++;;
        printf("%d\n",ans/c[cnt]);
    }
    return 0;
}
