#include <cstdio>
#include <cstring>
#include <map>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
#define eps 1e-8
bool check(long long x)
{
    if(x<2)
        return true;
    for(long long i=2; i*i<=x; i++)
    {
        if(x%i==0)return true;
    }
    return false;
}
int main()
{
    vector<long long>ans;
    long long a,b;
    scanf("%I64d%I64d",&a,&b);
    if(a==2)
    {
        if(!check(b-2))
        {
            printf("2->%I64d\n",b);
        }
        else if(!check(b+2))
        {
            printf("2->%I64d->%I64d",b+2,b);
        }
        else
            puts("Unlucky Benny");
    }
    else
    {
        if(b==a+2)
        {
            printf("%I64d->%I64d\n",a,b);
        }
        else
        {
            if(b==a+4&&check(a+2)==0)
                printf("%I64d->%I64d->%I64d\n",a,a+2,b);
            else
            {
                if(!check(a-2)&&!check(b-2))printf("%I64d->2->%I64d\n",a,b);
                else if(!check(a+2)&&!check(b-2))printf("%I64d->%I64d->2->%I64d\n",a,a+2,b);
                else if(!check(a-2)&&!check(b+2))printf("%I64d->2->%I64d->%I64d\n",a,b+2,b);
                else if(!check(a+2)&&!check(b+2))printf("%I64d->%I64d->2->%I64d->%I64d\n",a,a+2,b+2,b);
                else printf("Unlucky Benny");
            }
        }
    }
    return 0;
}
