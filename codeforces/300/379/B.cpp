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

long long num[4];
int main()
{
    for(int i=0;i<4;i++)scanf("%I64d",&num[i]);
    long long cnt=min(num[0],num[2]);
    cnt=min(cnt,num[3]);
    long long ans=cnt*256;
    num[0]-=cnt;
    ans+=min(num[0],num[1])*32;
    printf("%I64d\n",ans);
    return 0;
}
