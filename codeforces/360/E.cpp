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
#include<bitset>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
int n,k;
int c[505];
bitset<505>bst[505];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1; i<=n; i++)
        scanf("%d",&c[i]);
    bst[0][0]=1;
    for(int i=1; i<=n; i++)
    {
        for(int j=k; j>=c[i]; j--)
        {
            bst[j]=bst[j]|(bst[j-c[i]]<<c[i])|(bst[j-c[i]]);
        }
    }
    printf("%d\n",bst[k].count());
    for(int i=0; i<=k; i++)
    {
        if(bst[k][i]==1)
            printf("%d ",i);
    }
    printf("\n");
    return 0;
}
