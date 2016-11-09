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
int n;
int num[1005];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&num[i]);
    if(n==1)
        {
            if(num[0]==1)
                printf("YES\n");
            else
                printf("NO\n");
        }
    else
    {
        int sum=0;
        for(int i=0;i<n;i++)
            if(num[i]==0)
            sum++;
        if(sum!=1)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
