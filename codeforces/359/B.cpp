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

int n;
int num[105];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&num[i]);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j+1+i<n;j++)
        {
            if(num[j]>num[j+1])
            {
                printf("%d %d\n",j+1,j+2);
                swap(num[j],num[j+1]);
            }

        }
    }
    return 0;
}
