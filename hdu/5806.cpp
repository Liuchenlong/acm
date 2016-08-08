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

int n,m,k;
int a[2000005];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&k);
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        int head=0,tail=1;
        int num=(a[0]>=m);
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            while(head<i)
            {
                num-=(a[head]>=m);
                head++;
            }
            while(tail<n&&num<k)
            {
                num+=(a[tail]>=m);
                tail++;
            }
            if(num>=k)
                ans+=n-tail+1;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
