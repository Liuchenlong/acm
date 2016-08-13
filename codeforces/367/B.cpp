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

int num[1000005];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        num[x]++;
    }
    for(int i=1;i<=1000000;i++)num[i]+=num[i-1];
    int q;
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int x;
        scanf("%d",&x);
        x=min(x,1000000);
        printf("%d\n",num[x]);
    }
    return 0;
}
