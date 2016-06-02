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
int n,c;
long long cal(long long t)
{
    return t*(-t*n+c);
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        scanf("%d%d",&n,&c);
        int ans;
        if(n==0)
            ans=0;
        else
        {
            ans=c/(2*n);
            if(cal(ans)<cal(ans+1))
                ans++;
        }
        printf("Case %d: %d\n",cas,ans);
    }
    return 0;
}
