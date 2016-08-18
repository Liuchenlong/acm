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
#define eps 1e-8
const int mod=1e6+3;
long long C[1005][1005];
void init()
{
    C[0][0]=1;
    for(int i=1; i<=1000; i++)
    {
        C[i][0]=1;
        for(int j=1; j<=i; j++)
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
    }
}
int n;
int num[1005];
int bits[33][2];
int main()
{
    init();
    while(scanf("%d",&n)!=EOF)
    {
        memset(bits,0,sizeof(bits));
        for(int i=0; i<n; i++)
        {
            scanf("%d",&num[i]);
            int pos=0;
            for(int tim=0;tim<32;tim++)
            {
                bits[pos][num[i]%2]++;
                num[i]/=2;
                pos++;
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(i!=1)
                printf(" ");
            long long sum=0;
            for(int j=0;j<32;j++)
            {
                int n1=bits[j][0];
                int n2=bits[j][1];
                for(int k=0;k<=i&&k<=bits[j][0];k++)
                {
                    if(i-k>bits[j][1])
                        continue;
                    if(i-k<0)
                    break;
                    if((i-k)&1)
                    {
                        sum+=C[n1][k]*C[n2][i-k]%mod*(1<<j)%mod;
                    }
                }
            }
            printf("%lld",sum%mod);
        }
        printf("\n");

    }
    return 0;
}
