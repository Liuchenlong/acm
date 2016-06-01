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

int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        long long w;
        scanf("%lld",&w);
        if(w%2==1)
            printf("Case %d: Impossible\n",cas);
        else
        {
            long long ans=1;
            while(w%2==0)
            {
                w/=2;
                ans*=2;
            }
            printf("Case %d: %lld %lld\n",cas,w,ans);

        }
    }
    return 0;
}
