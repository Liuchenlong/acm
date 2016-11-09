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
long long dp[300005][4];
char str[300005];
int main()
{
    scanf("%s",str);
    long long ans=0;
    int len=strlen(str);
    for(int i=1;i<=len;i++)
    {
        dp[i][(str[i-1]-'0')%4]++;
        for(int j=0;j<4;j++)
        {
            dp[i][(j*10+str[i-1]-'0')%4]+=dp[i-1][j];
        }
        ans+=dp[i][0];
    }
    printf("%I64d\n",ans);
    return 0;
}
