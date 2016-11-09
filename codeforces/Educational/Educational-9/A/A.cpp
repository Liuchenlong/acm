#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<stack>
#include<iomanip>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
char str[55][55];
int main()
{
    int n;
    long long p;
    scanf("%d%I64d",&n,&p);
    for(int i=0;i<n;i++)
        scanf("%s",str[i]);
    long long num=0;
    for(int i=n-1;i>=0;i--)
    {
        if(strlen(str[i])==4)
            num*=2;
        else
            num=(num+1)*2;
    }
    long long ans=0;
    for(int i=0;i<n;i++)
    {
        if(strlen(str[i])==4)
        {
            ans=ans+num/2*p;
            num/=2;
        }
        else
        {
            ans=ans+num/2*p;
            num/=2;
            num--;
        }
    }
    printf("%I64d\n",ans/2);
    return 0;
}
