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
int n;
long long num[505][505];
bool check(long long x)
{
    for(int i=0;i<n;i++)
    {
        long long sum=0;
        for(int j=0;j<n;j++)
        {
            sum+=num[i][j];
        }
        if(sum!=x)return 0;
        sum=0;
        for(int j=0;j<n;j++)
            sum+=num[j][i];
        if(sum!=x)return 0;
    }
    long long s=0;
    for(int i=0;i<n;i++)s+=num[i][i];
    if(s!=x)return 0;
    s=0;
    for(int i=0;i<n;i++)s+=num[i][n-1-i];
    if(s!=x)return 0;
    return 1;
}
int main()
{
    scanf("%d",&n);
    int px,py;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%I64d",&num[i][j]);
            if(num[i][j]==0)
            {
                px=i;
                py=j;
            }
        }
    }
    if(n==1)
        printf("1\n");
    else
    {
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            if(i!=px)
            {
                for(int j=0;j<n;j++)
                    sum+=num[i][j];
                break;
            }
        }
        long long ans=sum;
        for(int j=0;j<n;j++)
            ans-=num[px][j];
        num[px][py]=ans;
        if(ans<=0||check(sum)==0)
            printf("-1\n");
        else
            printf("%I64d\n",ans);
    }
    return 0;
}
