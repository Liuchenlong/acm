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
#define eps 1e-7
const int maxl=50*50*100+1;
int val[55],num[55];
int main()
{
    int n;
    while(scanf("%d",&n),n+1)
    {
        int maxn=0;
        for(int i=0; i<n; i++)
        {
            scanf("%d%d",&val[i],&num[i]);
            maxn+=val[i]*num[i];
        }
        bitset<maxl>bst;
        bst[0]=true;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<num[i];j++)
            {
                bst=bst|(bst<<val[i]);
            }
        }
        int ans=0;
        for(int i=0;i<=maxn/2;i++)
            if(bst[i]==1)
            ans=i;
        printf("%d %d\n",maxn-ans,ans);
    }
    return 0;
}
