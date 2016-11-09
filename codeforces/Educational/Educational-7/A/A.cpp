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
    long long n;
    scanf("%I64d",&n);
    for(int i=1;;i++)
    {
        if(n>i)
            n-=i;
        else
        {
            printf("%I64d\n",n);
            return 0;
        }
    }
    return 0;
}
