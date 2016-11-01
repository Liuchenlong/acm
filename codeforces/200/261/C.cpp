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
#define SIZE 1000005
long long n,d,k;
vector<int>vec[1005];
bool check()
{
    long long val=1;
    for(int i=1;i<=d;i++)
    {
        val*=k;
        if(val>=n)
            return true;
    }
    return false;
}
int main()
{
    scanf("%I64d%I64d%I64d",&n,&k,&d);
    if(check())
    {
        for(int i=0;i<n;i++)
        {
            int x=i;
            for(int j=0;j<d;j++)
            {
                vec[i].push_back(x%k+1);
                x/=k;
            }
        }
        for(int j=0;j<d;j++)
        {
            for(int i=0;i<n;i++)
                printf("%d ",vec[i][j]);
            printf("\n");
        }
    }
    else
    {
        printf("-1\n");
    }
    return 0;
}
