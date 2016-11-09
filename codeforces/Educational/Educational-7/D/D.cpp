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
    int odd,even;
    int n;
    scanf("%d",&n);
    if(n&1)
    {
        odd=n;
        even=n-1;
        for(int i=1; i<=odd; i+=2)
            printf("%d ",i);
        for(int i=odd-2; i>=1; i-=2)
            printf("%d ",i);
        for(int i=2; i<=even; i+=2)
            printf("%d ",i);
        for(int i=even; i>=2; i-=2)
            printf("%d ",i);
        printf("%d\n",n);
    }
    else
    {
        odd=n-1;
        even=n;
        for(int i=1; i<=odd; i+=2)
            printf("%d ",i);
        for(int i=odd; i>=1; i-=2)
            printf("%d ",i);
        for(int i=2; i<=even; i+=2)
            printf("%d ",i);
        for(int i=even-2; i>=2; i-=2)
            printf("%d ",i);
        printf("%d\n",n);
    }
    return 0;
}
