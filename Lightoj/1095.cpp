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
long long C[1005][1005];
long long fac[1005];
long long MOD=1e9+7;
void init()
{
    fac[0]=1;
    C[0][0]=1;
    for(int i=1;i<=1000;i++)
    {
        fac[i]=fac[i-1]*i%MOD;
        C[i][0]=1;
        for(int j=1;j<=i;j++)
        {
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
        }
    }
}
int main()
{

    init();
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        long long ans=C[m][k];
        long long tmp=0;
        int sig=1;
        for(int i=0;i<=m-k;i++)
        {
            tmp=tmp+C[m-k][i]*fac[n-k-i]%MOD*sig;
            sig*=-1;
            tmp=(tmp%MOD+MOD)%MOD;
        }
        printf("Case %d: %lld\n",cas,ans*tmp%MOD);
    }
    return 0;
}
