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

int dp[355];

int main()
{
    for(int i=0;i<340;i++)dp[i]=1;
    for(int i=2;i*i<=300;i++)
        for(int j=i*i;j<=300;j++)
        dp[j]+=dp[j-i*i];
    int n;
    while(scanf("%d",&n),n)printf("%d\n",dp[n]);
    return 0;
}
