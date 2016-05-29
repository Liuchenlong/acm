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
double v[12][12];
int n,t;
int main()
{
    scanf("%d%d",&n,&t);
    v[0][0]=t;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(v[i][j]>=1)
            {
                double det=v[i][j]-1;
                v[i+1][j]+=det/2;
                v[i+1][j+1]+=det/2;
                ans++;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
