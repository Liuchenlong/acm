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
long long stir[1005][1005];
long long fac[1005];
long long MOD=10056;
void init()
{
    fac[0]=1;
    for(int i=1;i<=1000;i++)
    {
        fac[i]=fac[i-1]*i%MOD;
        for(int j=1;j<i;j++)
        {
            stir[i][j]=(j*stir[i-1][j]+stir[i-1][j-1])%MOD;
        }
        stir[i][i]=1;
    }
}
int main()
{

    init();
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        int n;
        scanf("%d",&n);
        long long ans=0;
        for(int i=1;i<=n;i++)
            ans+=fac[i]*stir[n][i]%MOD;
        printf("Case %d: %lld\n",cas,ans%MOD);
    }
    return 0;
}
