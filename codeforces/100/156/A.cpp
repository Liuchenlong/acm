#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<time.h>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

int num[105];
int main()
{
    int n;
    scanf("%d",&n);
    int num1=0,num2=0,num3=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
        if(i%3==0)
            num1+=num[i];
        else if(i%3==1)
            num2+=num[i];
        else num3+=num[i];
    }
    if(num1==max(num1,max(num2,num3)))
    {
        printf("chest\n");

    }
    else if(num2==max(num1,max(num2,num3)))
    {
        printf("biceps\n");
    }
    else
        printf("back\n");
    return 0;
}
