#include<stdio.h>
#include<math.h>
#include<cmath>
#include<vector>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) (a<b?a:b)
#define ll long long
#define INF 9223372036854775807
long long f[222222],num1;
long long s[222222],num2;
int main()
{
    int n;
    long long a;
    long long sum=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%I64d",&a);
        if(a>0)
            f[num1++]=a;
        else if(a<0)
            s[num2++]=(long long)fabs(a);
        sum+=a;
    }
    if(sum>0)
        printf("first\n");
    else if(sum<0)
        printf("second\n");
    else
    {
        for(int i=0;i<max(num1,num2);i++)
        {
            if(f[i]>s[i])
            {
                printf("first\n");
                return 0;
            }
            else if(f[i]<s[i])
            {
                printf("second\n");
                return 0;
            }
        }
        if(a>0)
            printf("first\n");
        else if(a<0)
            printf("second\n");
    }
    return 0;
}
