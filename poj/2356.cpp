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
int num[10005];
int sum[10005];
int main()
{
    int n;
    scanf("%d",&n);
    int ans=-1;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&num[i]);
        sum[i]=(sum[i-1]+num[i])%n;
        if(sum[i]==0)
            ans=i;
    }
    if(ans!=-1)
    {
        printf("%d\n",ans);
        for(int i=1;i<=ans;i++)
        {
            printf("%d\n",num[i]);
        }
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<i;j++)
            {
                if(sum[i]==sum[j])
                {
                    printf("%d\n",i-j);
                    for(int k=j+1;k<=i;k++)
                    {
                        printf("%d\n",num[k]);
                    }
                    return 0;
                }
            }
        }
    }

    return 0;
}
