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
#pragma comment(linker, "/STACK:102400000,102400000")
int mod=1000000007;
int inv[2000005];
int fac[2000005];
void init()
{
    inv[0]=1;
    inv[1]=1;
    for(int i=2;i<=2000000;i++)
        inv[i]=(long long)(mod-mod/i)*inv[mod%i]%mod;
    for(int i=2;i<=2000000;i++)
        inv[i]=(long long)inv[i-1]*inv[i]%mod;

    fac[0]=1;
    fac[1]=1;
    for(int i=2;i<=2000000;i++)
        fac[i]=(long long)fac[i-1]*i%mod;
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
        long long ans=1;
        ans=(long long)fac[n+k-1]*inv[k-1]%mod*inv[n]%mod;
        printf("Case %d: %d\n",cas,ans);
    }
    return 0;
}
