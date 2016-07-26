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
const int maxl=10000+1;
int main()
{
    int n1,n2,n5;
    while(scanf("%d%d%d",&n1,&n2,&n5),n1+n2+n5)
    {
        bitset<maxl>btt;
        btt[0]=1;
        for(int i=0; i<n1; i++)
            btt=btt|(btt<<1);
        for(int i=0; i<n2; i++)
            btt=btt|(btt<<2);
        for(int i=0; i<n5; i++)
            btt=btt|(btt<<5);
        for(int i=0; i<maxl; i++)
            if(btt[i]==0)
            {
                printf("%d\n",i);
                break;
            }

    }
    return 0;
}
