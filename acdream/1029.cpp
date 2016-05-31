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
#define SIZE 1001005
int n;
long long A[100005],B[100005];
long long suma[100005],sumb[100005];
long long C[100005];
long long mod=1e9+7;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&A[i]);
        suma[i]=(suma[i-1]+A[i])%mod;
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&B[i]);
        sumb[i]=(sumb[i-1]+B[i])%mod;
    }
    for(int i=1;i<=n;i++)
    {
        C[i]=A[i]*sumb[i]%mod+B[i]*suma[i]%mod-A[i]*B[i]%mod;
        C[i]=(C[i]%mod+mod)%mod;
    }
    for(int i=1;i<=n;i++)
    {
        if(i>1)
            printf(" ");
        printf("%lld",C[i]);
    }
    printf("\n");
    return 0;
}
