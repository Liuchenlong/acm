#include<stdio.h>
#include<cmath>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<set>
#include<vector>
#include<map>
using namespace std;
#define eps 1e-12

int main()
{
    int n;
    scanf("%d",&n);
    if(n==1)
    {
        puts("I hate it");
        return 0;
    }
    if(n==2)
    {
        puts("I hate that I love it");
        return 0;
    }
    n--;
    printf("I hate ");
    int res=n%2;
    int tim=n/2;
    for(int i=0;i<tim;i++)
        printf("that I love that I hate ");
    if(res==0)
        printf("it\n");
    else
        printf("that I love it\n");
    return 0;
}
