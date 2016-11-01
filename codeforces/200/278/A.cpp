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
#define LL long long
#define pii pair<int,int>
bool check(int n)
{
    while(n)
    {
        if(n%10==8)
            return true;
        n/=10;
    }
    return false;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=20;i++)
    {
        if(check(abs(n+i)))
        {
            printf("%d\n",i);
            return 0;
        }
    }
    return 0;
}
