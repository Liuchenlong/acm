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
int num[4][101];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++)
    {
        if(m)
        {
            num[0][i]=1;
            m--;
        }
        if(m)
        {
            num[3][i]=1;
            m--;
        }
        if(m==0)
            break;
    }
    for(int i=0; i<n; i++)
    {
        if(m)
        {
            num[1][i]=1;
            m--;
        }
        if(m)
        {
            num[2][i]=1;
            m--;
        }
        if(m==0)
            break;
    }
    for(int i=0; i<n; i++)
    {
        if(num[1][i])
            printf("%d ",2*n+1+2*i);
        if(num[0][i])
            printf("%d ",1+2*i);
        if(num[2][i])
            printf("%d ",2*n+2+2*i);
        if(num[3][i])
            printf("%d ",2+2*i);
    }
    printf("\n");
    return 0;
}
