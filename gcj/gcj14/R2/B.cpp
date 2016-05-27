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
int num[1005];
bool vis[1005];
int main()
{
//    freopen("B-small-practice.in","r",stdin);
//    freopen("B-small-practice.out","w",stdout);
    freopen("B-large-practice.in","r",stdin);
    freopen("B-large-practice.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        memset(vis,0,sizeof(vis));
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&num[i]);
        int head=0,tail=n-1;
        int ans=0;
        for(int tim=0;tim<n;tim++)
        {
            int pos=head;
            for(int i=head;i<=tail;i++)
            {
                if(num[i]<num[pos])
                    pos=i;
            }
            if(pos-head<tail-pos)
            {
                ans+=pos-head;
                for(int i=pos;i>head;i--)
                    swap(num[i],num[i-1]);
                head++;
            }
            else
            {
                ans+=tail-pos;
                for(int i=pos;i<tail;i++)
                    swap(num[i],num[i+1]);
                tail--;
            }
        }
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}
