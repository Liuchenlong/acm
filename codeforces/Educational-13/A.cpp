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

int main()
{
    long long n,k;
    scanf("%I64d%I64d",&n,&k);
    long long ans=n/k*k;
    if(ans<=n)ans+=k;
    printf("%I64d\n",ans);
    return 0;
}
