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

int dp[255];

int main()
{
    for(int i=0;i<200;i++)dp[i]=1;
    for(int i=2;i<=120;i++)
        for(int j=i;j<=120;j++)
        dp[j]+=dp[j-i];
    int n;
    while(scanf("%d",&n)!=EOF)printf("%d\n",dp[n]);
    return 0;
}
