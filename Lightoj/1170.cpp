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
#define SIZE 1000005
long long catlan[SIZE];
long long inv[SIZE];
long long mod=100000007;
void init()
{
    inv[0]=1;
    inv[1]=1;
    for(int i=2;i<SIZE;i++)
        inv[i]=(mod-mod/i)*inv[mod%i]%mod;
    catlan[0]=1;
    for(int i=0;i+1<=1000002;i++)
        catlan[i+1]=2LL*(2*i+1)*inv[i+2]%mod*catlan[i]%mod;
}
vector<long long>vec;
void init2()
{
    for(long long i=2;i<=100000;i++)
    {
        long long x=i;
        while(x*i<=10000000000LL)
        {
            x*=i;
            vec.push_back(x);
        }
    }
    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
}
int main()
{
    init();
    init2();
    catlan[0]=0;
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        long long a,b;
        scanf("%lld%lld",&a,&b);
        int sum=0;
        sum=(upper_bound(vec.begin(),vec.end(),b)-vec.begin())-(lower_bound(vec.begin(),vec.end(),a)-vec.begin());
        printf("Case %d: %lld\n",cas,catlan[sum]);
    }
    return 0;
}
