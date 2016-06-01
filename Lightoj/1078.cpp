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
        int n,k;
        scanf("%d%d",&n,&k);
        int ans=1;
        int res=k%n;
        while(res)
        {
            ans++;
            res=(res*10+k)%n;
        }
        printf("Case %d: %d\n",cas,ans);
    }
    return 0;
}
