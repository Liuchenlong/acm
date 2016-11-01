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
#include<bitset>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-7
int n;
int pf[305][305];
int mf[305];
int ans[305];
int now[2];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int x;
            scanf("%d",&x);
            pf[i][x]=j;
        }
        pf[i][0]=999;
    }
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        mf[x]=i;
    }
    mf[0]=999;
    for(int i=1;i<=n;i++)
    {
        if(mf[i]<mf[now[0]])
        {
            now[1]=now[0];
            now[0]=i;
        }
        else
        {
            if(mf[i]<mf[now[1]])
            {
                now[1]=i;
            }
        }
        for(int j=1;j<=n;j++)
        {
            if(j==now[0])
            {
                if(pf[j][ans[j]]>pf[j][now[1]])
                    ans[j]=now[1];
            }
            else
            {
                if(pf[j][ans[j]]>pf[j][now[0]])
                    ans[j]=now[0];
            }
        }

    }
    for(int i=1;i<=n;i++)
    {
        printf("%d ",ans[i]);
    }
    printf("\n");
    return 0;
}
