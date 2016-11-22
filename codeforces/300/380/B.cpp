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
int num[1005][1005];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            scanf("%d",&num[i][j]);
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=0;j<m;j++)
        {
            if(num[i][j]==0)ans+=sum;
            else sum=1;
        }
        sum=0;
        for(int j=m-1;j>=0;j--)
        {
            if(num[i][j]==0)ans+=sum;
            else sum=1;
        }
    }
    for(int j=0;j<m;j++)
    {
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(num[i][j]==0)ans+=sum;
            else sum=1;
        }
        sum=0;
        for(int i=n-1;i>=0;i--)
        {
            if(num[i][j]==0)ans+=sum;
            else sum=1;
        }
    }
    printf("%d\n",ans);
    return 0;
}
