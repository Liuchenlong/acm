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
#define eps 1e-8
#define LL long long
#define pii pair<int,int>

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        printf("%d\n",n);
        if(n%2==0)
            puts("No solution");
        else
        {
            for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)
                printf("%d %d %d ",i,j,(i+j)%n+1);
            printf("\n");
        }
    }
    return 0;
}
