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
long long num[2][2];
long long x[3];
long long y[3];
long long n,m;
long long ans;
long long mod=1e9+7;
void dfs(int step,long long sum)
{
    if(step<3)
    {
        for(int i=0;i<2;i++)for(int j=0;j<2;j++)
        {
            if(num[i][j]>0)
            {
                x[step]=i;
                y[step]=j;
                num[i][j]--;
                dfs(step+1,sum*(num[i][j]+1)%mod);
                num[i][j]++;
            }
        }
    }
    else
    {
        if((x[1]-x[0])*(y[2]-y[0])%2==(x[2]-x[0])*(y[1]-y[0])%2)
            ;
        else
            ans=(ans+sum)%mod;
    }
}
int main()
{
    scanf("%lld%lld",&n,&m);
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            if(i<n&&j<m)
            {
                num[i][j]=((n-i+1)/2)*((m-j+1)/2)%mod;
            }
        }
    }
    dfs(0,1);
    printf("%lld\n",ans);
    return 0;
}
