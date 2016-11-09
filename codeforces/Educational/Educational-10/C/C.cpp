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
int num[300005];
int pos[300005];
int r[300005];
int Q[300005];
int hpos[300005];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&num[i]);
        pos[num[i]]=i;
    }
    for(int i=1; i<=n; i++)
        r[i]=n-1;
    for(int i=0; i<m; i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if(pos[b]>pos[a])
        {
            r[a]=min(r[a],pos[b]-1);
        }
        if(pos[a]>pos[b])
        {
            r[b]=min(r[b],pos[a]-1);
        }
    }
    long long ans=0;
    int head=0,tail=0;
    int lpos=0;
    for(int i=0; i<n; i++)
    {
        while(head<tail&&r[Q[tail-1]]>=r[num[i]])tail--;
        Q[tail++]=num[i];
        int rpos=lpos;
        int flag=0;
        while(head<tail&&r[Q[head]]==i)
        {
            flag=1;
            rpos=pos[Q[head]];
            head++;
        }
        if(flag)
        {
            for(int j=lpos; j<=rpos; j++)
                ans=ans+(i-j+1);
            lpos=rpos+1;
        }
    }
    printf("%I64d\n",ans);
    return 0;
}
