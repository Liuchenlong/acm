#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(a) (a<0?-a:a)

bool vis[5005];
int num[100005];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%d",&num[i]);
        memset(vis,0,sizeof(vis));
        vis[0]=1;
        int sum=0;
        bool flag=false;
        for(int i=0;i<n;i++)
        {
            sum+=num[i];
            sum%=m;
            if(vis[sum])
            {
                flag=true;
                break;
            }
            vis[sum]=true;
        }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
