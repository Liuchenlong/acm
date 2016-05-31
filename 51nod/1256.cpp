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
#define SIZE 1001005
long long d,x,y;
long long exgcd(long long a,long long b,long long &x,long long &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    else
    {
        long long ret=exgcd(b,a%b,x,y);
        long long tmp=x;
        x=y;
        y=tmp-a/b*y;
        return ret;
    }
}
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    exgcd(m,n,x,y);
    printf("%I64d\n",(x%n+n)%n);
    return 0;
}
