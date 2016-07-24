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
#include<bitset>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-7
int x[105];
bool vis[105];
int num[105];
int main()
{
    int n;
    scanf("%d",&n);
    int sum=0;
    for(int i=0; i<n; i++)
    {
        scanf("%d",&x[i]);
        sum+=x[i];
    }
    n/=2;
    sum/=n;
    for(int j=0; j<2*n; j++)
    {
        for(int k=0; k<2*n; k++)
        {
            if(j==k)continue;
            if(vis[j]||vis[k])continue;
            if(x[j]+x[k]==sum)
            {
                printf("%d %d\n",j+1,k+1);
                vis[j]=true;
                vis[k]=true;
                break;
            }
        }
    }
    return 0;
}
