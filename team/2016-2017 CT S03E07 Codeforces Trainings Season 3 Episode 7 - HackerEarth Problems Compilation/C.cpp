#include <cstdio>
#include <cstring>
#include <map>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
#define eps 1e-8
const long long mod=1e9+7;
bool ok[202][202];
int d[202];
long long C(long long n,long long k)
{
    if(n<k)return 0;
    long long fz=1,fm=1;
    for(int i=0;i<k;i++)
    {
        fz*=(n-i);
        fm*=(k-i);
    }
    return (fz/fm)%mod;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        ok[u][v]=1;
        ok[v][u]=1;
        d[u]++;
        d[v]++;
    }
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)continue;
            if(ok[i][j]==0)continue;
            int cnt=0;
            for(int k=1;k<=n;k++)
            {
                if(k==i||k==j)continue;
                if(ok[i][k]&&ok[j][k])
                    cnt++;
            }
            for(int k=0;k<=min(cnt,3);k++)
            {
                ans+=(C(cnt,k)*C(d[i]-1-cnt,3-k)%mod)*(C(d[j]-1-k,2))%mod;
            }
        }
    }
    printf("%I64d\n",ans%mod);
    return 0;
}
