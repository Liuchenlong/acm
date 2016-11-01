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

int num[105];
bool vis[50005];
int main()
{
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    if(b==0&&n==a+1)
    {
        if(n==1)printf("1");
        else
        printf("-1\n");
        return 0;
    }
    if(b==0)
    {
        printf("200 200 ");
        for(int i=1;i<=a;i++)
        {
            printf("%d ",200+i);
        }
        for(int i=0;i<n-2-a;i++)
        {
            printf("%d ",199-i);
        }
        printf("\n");
    }
    else
    {
        vis[1]=1;
        int sum=1;
        num[0]=1;
        printf("1 ");
        for(int i=1;i<b;i++)
        {
            num[i]=sum+1;
            printf("%d ",num[i]);
            vis[num[i]]=1;
            sum+=num[i];
        }
        num[b]=50000-100;
        printf("%d ",num[b]);

        int pre=num[b];
        for(int i=1;i<=a;i++)
        {
            printf("%d ",pre+1);
            vis[pre+1]=1;
            pre++;
        }
        int res=n-1-b-a;
        int now=40000;
        while(true)
        {
            if(res==0)break;
            if(vis[now])
                ;
            else
            {
                printf("%d ",now);
                vis[now]=true;
                res--;
            }
            now--;
        }
    }
    return 0;
}
