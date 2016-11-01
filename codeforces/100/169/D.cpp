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

long long cal(long long a,long long b,int bit)
{
    if(bit==-1)
        return 0;
    long long two=(1LL<<bit);
    if(two>b)
        return cal(a,b,bit-1);
    if(two>a)
        return two+two-1;
    return cal(a-two,b-two,bit-1);
}
int main()
{
    long long a,b;
    scanf("%I64d%I64d",&a,&b);
    printf("%I64d\n",cal(a,b,62));
    return 0;
}
