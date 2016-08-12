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

int pos[1005];
int f[1005];
int a[1005];
int b[1005];
bool vis[1005];
bool cmp(int a,int b)
{
    return f[a]<f[b];
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(f,0,sizeof(f));
        memset(vis,0,sizeof(vis));
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        for(int i=0;i<n;i++)scanf("%d",&b[i]);
        bool flag=true;
        for(int i=n-1;i>=0;i--)
        {
            pos[i]=i;
            bool tmp=0;
            for(int j=n-1;j>=0;j--)
            {
                if(vis[j])continue;
                if(a[i]==b[j])
                {
                    tmp=1;
                    f[i]=j;
                    vis[j]=1;
                    break;
                }
            }
            flag&=tmp;
        }
        for(int i=0;i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if(flag)
            sort(pos+x-1,pos+y,cmp);
        }
        if(flag==0)
        {
            printf("No\n");
            continue;
        }
        bool ans=1;
        for(int i=0;i<n;i++)
        {
            if(a[pos[i]]!=b[i])
                ans=0;
        }
        if(ans)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
