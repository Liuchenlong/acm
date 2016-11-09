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
long long mod=1e9+7;
long long powm[1000005];
long long powm_[1000005];
long long fac[1000005];
long long finv[1000005];
long long inv[1000005];
long long C[1000005];
int n,m;
void init()
{
    inv[0]=1;
    inv[1]=1;
    for(int i=2; i<=n; i++)
    {
        inv[i]=(mod-mod/i)*inv[mod%i]%mod;
    }
    fac[0]=1;
    fac[1]=1;
    finv[1]=1;
    for(int i=2; i<=n; i++)
    {
        fac[i]=(fac[i-1]*i)%mod;
        finv[i]=(finv[i-1]*inv[i])%mod;
    }
    powm[0]=powm_[0]=1;
    for(int i=1; i<=n; i++)
    {
        powm[i]=powm[i-1]*m%mod;
        powm_[i]=powm_[i-1]*(m-1)%mod;
    }
    C[0]=1;
    for(int i=1;i<n;i++)
    {
        C[i]=fac[n]*finv[i]%mod*finv[n-i]%mod;
    }
    C[n]=1;
}
int main()
{
    scanf("%d%d",&n,&m);
    init();
    long long ans=0;
    for(int s=1;s<=n;s++)
    {
        ans=ans+powm[s]*powm_[n-s]%mod*C[s-1]%mod;
        ans%=mod;
    }
    ans=(ans+powm[n])%mod;
    printf("%I64d\n",ans);
    return 0;
}
