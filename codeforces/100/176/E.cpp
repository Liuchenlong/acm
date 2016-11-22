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
int n;
int p[1000005];
bool vis[1000005];
int ans[1000005];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&p[i]);
    int m;
    scanf("%d",&m);
    while(m--)
    {
        int x;
        scanf("%d",&x);
        vis[x]=1;
    }
    stack<int>stk;
    for(int i=n;i>=1;i--)
    {
        if(vis[i])
        {
            ans[i]=-p[i];
            stk.push(ans[i]);
        }
        else
        {
            if(stk.empty())
            {
                ans[i]=-p[i];
                stk.push(ans[i]);
            }
            else
            {
                int head=stk.top();
                if(p[i]+head==0)
                {
                    ans[i]=p[i];
                    stk.pop();
                }
                else
                {
                    ans[i]=-p[i];
                    stk.push(-p[i]);
                }
            }
        }
    }
    if(stk.empty())
    {
        printf("YES\n");
        for(int i=1;i<=n;i++)
            printf("%d ",ans[i]);
        puts("");
    }
    else
        printf("NO\n");
    return 0;
}
