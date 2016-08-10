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

bool vis[100005];
int nxt[100005];
int val[100005];
int main()
{
    int cas=0;
    int n;
    while(scanf("%d",&n),n)
    {
        cas++;
        memset(vis,0,sizeof(vis));
        printf("Case #%d:\n",cas);
        int pos=0;
        int heada=-1,headb=-1;
        int last=-1;
        for(int i=0; i<n; i++)
        {
            char str[11];
            scanf("%s",str);
            if(str[1]=='u')
            {
                char name[10];
                scanf("%s",name);
                int x;
                scanf("%d",&x);
                val[pos]=x;
                if(name[0]=='A')
                {
                    nxt[pos]=heada;
                    heada=pos;
                }
                else
                {
                    nxt[pos]=headb;
                    headb=pos;
                }
                pos++;
            }
            if(str[1]=='o')
            {
                char name[10];
                scanf("%s",name);
                if(name[0]=='A')
                {
                    if(last==heada)
                        last=nxt[heada];
                    printf("%d\n",val[heada]);
                    vis[heada]=1;
                    heada=nxt[heada];
                }
                else
                {
                    if(last==headb)
                        last=nxt[headb];
                    printf("%d\n",val[headb]);
                    vis[headb]=1;
                    headb=nxt[headb];
                }
            }
            if(str[1]=='e')
            {
                char n1[3],n2[3];
                scanf("%s%s",n1,n2);
                if(heada==-1||headb==-1)
                {
                    if(n1[0]=='A')
                        heada=max(heada,headb);
                    else
                        headb=max(heada,headb);
                    continue;
                }
                int head=-1;
                int pre=-1;
                for(int j=pos-1; j>last; j--)
                {
                    if(vis[j])continue;
                    if(head==-1)head=j;
                    if(pre==-1)
                        pre=j;
                    else
                    {
                        nxt[pre]=j;
                        pre=j;
                    }
                }
                if(pre==-1)
                    head=last;
                else
                {
                    nxt[pre]=last;
                }
                last=head;
                if(n1[0]=='A')
                {
                    heada=head;
                    headb=-1;
                }
                else
                {
                    headb=head;
                    heada=-1;
                }
            }
        }
    }
    return 0;
}
