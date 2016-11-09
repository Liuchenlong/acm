#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <fstream>
using namespace std;
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) (a<0?-a:a)

#define eps 1e-8
const double pi=acos(-1.0);


int dp[33][33][55];

int main()
{
    for(int i=0; i<33; i++)
    {
        for(int j=0; j<33; j++)
        {
            for(int k=1; k<55; k++)
                dp[i][j][k]=99999999;
        }
    }

    for(int i=1; i<=30; i++)
    {
        for(int j=1; j<=30; j++)
        {
            if(i*j<=50)
                dp[i][j][i*j]=0;
            for(int k=50; k>=0; k--)
            {
                for(int t=0; t<=i&&t*j<=k; t++)
                {
                    dp[i][j][k]=MIN(dp[i][j][k],dp[i-t][j][k-t*j]+j*j);

                }
                for(int t=0; t<=j&&t*i<=k; t++)
                {
                    dp[i][j][k]=MIN(dp[i][j][k],dp[i][j-t][k-t*i]+i*i);
                    dp[i][j][k]=MIN(dp[i][j][k],dp[i][j-t][k]+i*i);
                }
                for(int t=0; t<=i; t++)
                    dp[i][j][k]=MIN(dp[i][j][k],dp[i-t][j][k]+j*j);
                for(int t=0; t<=j; t++)
                    dp[i][j][k]=MIN(dp[i][j][k],dp[i][j-t][k]+i*i);

            }
        }
    }


    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        printf("%d\n",dp[n][m][k]);
    }
    return 0;
}
