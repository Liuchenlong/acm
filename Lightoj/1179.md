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
int f[100005];
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        f[1]=0;
        for(int i=2;i<=n;i++)
        {
            f[i]=(f[i-1]+k%i)%i;
        }
        printf("Case %d: %d\n",cas,f[n]+1);
    }
    return 0;
}
