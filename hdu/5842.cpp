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
bool vis[30];
char str[1000005];
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        scanf("%s",str);
        memset(vis,0,sizeof(vis));
        int len=strlen(str);
        for(int i=0;i<len;i++)
        {
            vis[str[i]-'a']=1;
        }
        int ans=0;
        for(int i=0;i<26;i++)
            if(vis[i])ans++;
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}
