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

int getsg(int x)
{
    if(x%2==0)return 1;
    return 0;
}
int main()
{
    int n;
    scanf("%d",&n);
    int ans=0;
    for(int i=0; i<n; i++)
    {
        int x;
        scanf("%d",&x);
        ans^=getsg(x);
        if(!ans)
            printf("2\n");
        else
            printf("1\n");
    }

    return 0;
}
