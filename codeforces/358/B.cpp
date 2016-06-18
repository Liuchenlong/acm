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
int num[1000005];
int n;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&num[i]);
    sort(num,num+n);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int t=ans;
        ans=min(ans+1,num[i]);
        ans=max(ans,t);
    }
    printf("%d\n",ans+1);
    return 0;
}
