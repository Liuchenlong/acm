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
#define SIZE 1000005
const long long mod=100000007;
long long fac[SIZE];
long long inv[SIZE];
long long ifac[SIZE];
void init()
{
    fac[0]=inv[0]=ifac[0]=1;
    fac[1]=inv[1]=ifac[1]=1;
    for(int i=2;i<SIZE;i++)
    {
        fac[i]=fac[i-1]*i%mod;
        inv[i]=(mod-mod/i)*inv[mod%i]%mod;
        ifac[i]=ifac[i-1]*inv[i]%mod;
    }
}
long long C(int n,int m)
{
    if(m>n)return 0;
    if(n<0)return 0;
    return fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
int l[11],r[11];
int main()
{
//    freopen("1.txt","r",stdin);
//    freopen("2.out","w",stdout);
    init();
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&l[i],&r[i]);
            m-=(l[i]-1);
            r[i]-=(l[i]-1);
            l[i]-=(l[i]-1);
        }
        long long ans=0;
        for(int i=0;i<(1<<n);i++)
        {
            int sig=1;
            int val=m;
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j))
                {
                    sig*=-1;
                    val-=(r[j]);
                }
            }
            ans+=C(val-1,n-1)*sig;
            ans%=mod;
        }
        printf("Case %d: %lld\n",cas,(ans%mod+mod)%mod);
    }
    return 0;
}
