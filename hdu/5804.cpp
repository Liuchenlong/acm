#include<stdio.h>
#include<cmath>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<set>
#include<vector>
#include<map>
using namespace std;
#define eps 1e-12


int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            sum+=x;
        }
        for(int i=0;i<m;i++)
        {
            long long x;
            scanf("%I64d",&x);
            if(x>sum)
                printf("1");
            else
                printf("0");
        }
        printf("\n");
    }
    return 0;
}
