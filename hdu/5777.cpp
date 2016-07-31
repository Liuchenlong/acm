#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(a) (a<0?-a:a)

long long d[100005];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        long long sum=n;
        for(int i=0; i<n-1; i++)
        {
            scanf("%I64d",&d[i]);
            sum+=d[i];
        }
        sort(d,d+n-1);
        reverse(d,d+n-1);
        if(k>=n)
        {
            printf("%d\n",n);
            continue;
        }
        else
        {
            for(int i=0;i<k-1;i++)
                sum-=d[i];
            printf("%I64d\n",sum);
        }
    }
    return 0;
}
