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
#define eps 1e-12

int main()
{
    int n;
    scanf("%d",&n);
    long long a=1234567;
    long long b=123456;
    for(int i=0;i<1000;i++)
    {
        for(int j=0;j<100000;j++)
        {
            if(a*i+b*j>n)
                break;
            long long res=n-a*i-b*j;
            if(res%1234==0)
            {
                printf("YES\n");
                return 0;
            }
        }
    }
    printf("NO\n");
    return 0;
}
