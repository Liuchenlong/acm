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
pair<int,int>pr[100005];
int ans[100005];
int main()
{
    scanf("%d%d",&n,&m);
    int len=n;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&pr[i].first,&pr[i].second);
        pr[i].first--;
        pr[i].second--;
        len=min(len,pr[i].second-pr[i].first+1);
    }
    for(int i=0;i<n;i++)
        ans[i]=i%len;
    printf("%d\n",len);
    for(int i=0;i<n;i++)
        printf("%d ",ans[i]);
    printf("\n");
    return 0;
}
