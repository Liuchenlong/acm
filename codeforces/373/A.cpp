#include<stdio.h>
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
int a[22];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    if(n==1)
    {
        if(a[0]==15)puts("DOWN");
        else if(a[0]==0)puts("UP");
        else puts("-1");
    }
    else
    {
        if(a[n-1]==15)puts("DOWN");
        else if(a[n-1]==0)puts("UP");
        else
        {
            if(a[n-1]>a[n-2])puts("UP");
            else puts("DOWN");
        }
    }
    return 0;
}
