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
long long A[1000006];
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        int n,q;
        scanf("%d%d",&n,&q);
        for(int i=1;i<=n;i++)scanf("%lld",&A[i]);
        long long ans=0;
        for(int i=1;i<=n;i++)
            ans=ans+A[i]*(n-i)-A[i]*(i-1);
        printf("Case %d:\n",cas);
        for(int i=0;i<q;i++)
        {
            int type;
            scanf("%d",&type);
            if(type==1)
                printf("%lld\n",ans);
            else
            {
                int x,v;
                scanf("%d%d",&x,&v);
                x++;
                ans=ans-A[x]*(n-x)+A[x]*(x-1);
                A[x]=v;
                ans=ans+A[x]*(n-x)-A[x]*(x-1);
            }
        }
    }
    return 0;
}
