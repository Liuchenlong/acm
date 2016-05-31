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
#define SIZE 1001005
int bita[32];
int bitb[32];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        for(int j=0;j<32;j++)
        {
            if(a&(1<<j))
                bita[j]++;
        }
    }
    for(int i=0;i<n;i++)
    {
        int b;
        scanf("%d",&b);
        for(int j=0;j<32;j++)
        {
            if(b&(1<<j))
                bitb[j]++;
        }
    }
    int ans=0;
    for(int i=0;i<32;i++)
    {
        if(bita[i]==bitb[i])
            ;
        else if(bita[i]+bitb[i]==n)
            ans|=(1<<i);
        else
        {
            printf("-1\n");
            return 0;
        }
    }
    printf("%d\n",ans);
    return 0;
}
