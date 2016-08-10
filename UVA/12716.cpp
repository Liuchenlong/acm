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
#define SIZE 1000005

int ans[30000005];
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
void solve()
{
    for(int c=1;c<=15000000;c++)
    {
        for(int a=c+c;a<=30000000;a+=c)
        {
            int b=a-c;
            if((a^b)==c)
                ans[a]++;
        }
    }
    for(int i=1;i<=30000000;i++)
        ans[i]+=ans[i-1];
}
int main()
{
    solve();
    int n;
    scanf("%d",&n);
    for(int cas=1;cas<=n;cas++)
    {
        int t;
        scanf("%d",&t);
        printf("Case %d: %d\n",cas,ans[t]);
    }
    return 0;
}
