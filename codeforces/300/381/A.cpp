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

int main()
{
    long long n,a,b,c;
    scanf("%I64d%I64d%I64d%I64d",&n,&a,&b,&c);
    if(n%4==0)
        puts("0");
    else if(n%4==1)
    {
        printf("%I64d\n",min(a*3,min(c,b+a)));
    }
    else if(n%4==3)
    {
        printf("%I64d\n",min(c*3,min(a,b+c)));
    }
    else if(n%4==2)
    {
        printf("%I64d\n",min(b,min(a*2,c*2)));
    }
    return 0;
}
