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
int num[100005];
bool vis[100005];
int main()
{
    int n,h,k;
    scanf("%d%d%d",&n,&h,&k);
    for(int i=0; i<n; i++)
        scanf("%d",&num[i]);
    long long ans=0;
    long long res=0;
    for(int i=0; i<n; i++)
    {
        if(res+num[i]<=h)
            res+=num[i];
        else
        {
            ans+=res/k;
            res%=k;
            if(res+num[i]>h)
            {
                ans++;
                res=0;
            }
            i--;
        }
    }
    ans+=res/k;
    res%=k;
    if(res)
        ans++;
    printf("%I64d\n",ans);
    return 0;
}
