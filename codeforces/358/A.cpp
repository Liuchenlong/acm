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
long long num1[5],num2[5];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        num1[i%5]++;
    }
    for(int i=1;i<=m;i++)
        num2[i%5]++;
    long long ans=0;
    for(int i=0;i<5;i++)
    {
        ans+=num1[i]*num2[(5-i)%5];
    }
    printf("%I64d\n",ans);
    return 0;
}
