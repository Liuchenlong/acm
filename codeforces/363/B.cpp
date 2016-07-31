#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
int n,m;
char table[1005][1005];
int numx[1005];
int numy[1005];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%s",table[i]);
    int sum=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(table[i][j]=='*')
            {
                sum++;
                numx[i]++;
                numy[j]++;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int now=numx[i]+numy[j];
            if(table[i][j]=='*')
                now--;
            if(now==sum)
            {
                printf("YES\n");
                printf("%d %d\n",i+1,j+1);
                return 0;
            }
        }
    }
    printf("NO\n");
    return 0;
}
