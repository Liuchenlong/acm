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
        long long s;
        scanf("%lld",&s);
        long long x=(long long)sqrt(s);
        if(x*x==s)
        {
            if(x&1)
                printf("Case %d: 1 %lld\n",cas,x);
            else
                printf("Case %d: %lld 1\n",cas,x);
        }
        else
        {
            s-=x*x;
            long long d=x+1;
            if(s<=d)
            {
                if((x&1)==0)
                    printf("Case %d: %lld %lld\n",cas,x+1,s);
                else
                    printf("Case %d: %lld %lld\n",cas,s,x+1);
            }
            else
            {
                s=d+d-s;
                if((x&1))
                    printf("Case %d: %lld %lld\n",cas,x+1,s);
                else
                    printf("Case %d: %lld %lld\n",cas,s,x+1);
            }
        }
    }
    return 0;
}
