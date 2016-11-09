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

int num[105][105];
int Min[105];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            scanf("%d",&num[i][j]);
        Min[i]=num[i][0];
        for(int j=0;j<m;j++)
            Min[i]=min(Min[i],num[i][j]);
        ans=max(ans,Min[i]);
    }
    printf("%d\n",ans);
    return 0;
}
