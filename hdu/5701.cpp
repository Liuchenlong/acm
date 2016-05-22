#include<stdio.h>
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
int n;
int num[8005];
int mp[2][20005];
int sum[8005];
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1; i<=n; i++)
            scanf("%d",&num[i]);
        for(int i=1; i<=n; i++)
        {
            if(i>1)
                printf(" ");
            memset(mp,0,sizeof(mp));
            mp[0][10000]=1;
            mp[1][10000]=1;
            for(int j=1; j<i; j++)
            {
                sum[j]=sum[j-1];
                if(num[j]<num[i])
                    sum[j]++;
                mp[j%2][2*sum[j]-j+10000]++;
            }
            int ans=0;
            for(int j=i; j<=n; j++)
            {
                sum[j]=sum[j-1];
                if(num[j]<num[i])
                    sum[j]++;
                ans+=mp[1^(j%2)][2*sum[j]-j+1+10000];
            }
            printf("%d",ans);
        }
        printf("\n");
    }
    return 0;
}
