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
long long mod=1e9+7;
int n;
int w[1005];
int cap[1005];
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        scanf("%d",&n);
        for(int i=0; i<n; i++)scanf("%d",&w[i]);
        for(int i=0; i<n; i++)scanf("%d",&cap[i]);
        sort(w,w+n);
        sort(cap,cap+n);
        long long ans=1;
        int res=0;
        int pos=0;
        for(int i=0; i<n; i++)
        {
            while(pos<n&&w[pos]<=cap[i])
            {
                res++;
                pos++;
            }
            ans*=res;
            ans%=mod;
            res--;
        }
        printf("Case %d: %lld\n",cas,ans%mod);
    }
    return 0;
}
