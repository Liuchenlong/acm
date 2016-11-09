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
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)<0?-(a):(a))

int num[100005];
int main()
{
    int n;
    scanf("%d",&n);
    int sum=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
        sum+=num[i];
    }
    if(sum%n==0)
    {
        sum/=n;
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            if(num[i]>sum)
            {
                ans=ans+num[i]-sum;
            }
        }
        printf("%I64d\n",ans);
    }
    else
    {
        long long ans=0;
        int num1=sum%n;
        sum=sum/n+1;
        int tnum1=0;
        for(int i=0;i<n;i++)
        {
            if(num[i]>=sum)
            {
                tnum1++;
                ans=ans+num[i]-sum;
            }
        }
        if(tnum1>num1)
        ans=ans+tnum1-num1;
        printf("%I64d\n",ans);
    }
    return 0;
}
