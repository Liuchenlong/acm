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
        int n,m;
        scanf("%d%d",&n,&m);
        if(n>m)
            swap(n,m);
        if(n==1)
        {
            printf("Case %d: %d\n",cas,m);
            continue;
        }
        if(n==2)
        {
            printf("Case %d: %d\n",cas,2*(m/4*2+min(2,m%4)));
            continue;
        }
        printf("Case %d: %d\n",cas,(n*m+1)/2);
    }
    return 0;
}
