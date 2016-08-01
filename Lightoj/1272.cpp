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
int a[64][105];
long long num[105];
int ans[64];
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        memset(ans,0,sizeof(ans));
        memset(a,0,sizeof(a));
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&num[i]);
            for(int j=0;j<63;j++)
            {
                if(num[i]&(1LL<<j))
                    a[j][i]=1;
            }
        }
        for(int i=0;i<63;i++)
            a[i][n]=1;
        for(int i=62;i>=0;i--)
        {
            bool flag=false;
            for(int j=0;j<n;j++)
            {
                if(a[i][j]==1)
                {
                    flag=1;
                    ans[i]=1;
                    for(int k=i-1;k>=0;k--)
                    {
                        int det=a[k][j];
                        for(int t=0;t<=n;t++)
                            a[k][t]^=(det*a[i][t]);
                    }
                    break;
                }
            }
            if(flag)
                ;
            else
            {
                if(a[i][n]==0)
                    ans[i]=1;
            }
        }
        long long tans=0;
        for(int i=0;i<63;i++)
        {
            if(ans[i])
                tans|=(1LL<<i);
        }
        printf("Case %d: %lld\n",cas,tans);

    }
    return 0;
}
