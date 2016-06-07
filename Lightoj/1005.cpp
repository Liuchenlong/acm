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
long long C[33][33];
long long fac[33];
void init()
{
    fac[0]=1;
    C[0][0]=1;
    for(int i=1;i<=30;i++)
    {
        fac[i]=fac[i-1]*i;
        C[i][0]=1;
        for(int j=1;j<=i;j++)
        {
            C[i][j]=C[i-1][j]+C[i-1][j-1];
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
        int n,k;
        scanf("%d%d",&n,&k);
        long long ans;
        if(k>n)
            ans=0;
        else
            ans=C[n][k]*C[n][k]*fac[k];
        printf("Case %d: %lld\n",cas,ans);
    }
    return 0;
}
