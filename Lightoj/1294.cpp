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
        long long n,m;
        scanf("%lld%lld",&n,&m);
        printf("Case %d: %lld\n",cas,(n/(m*2))*m*m);
    }
    return 0;
}
