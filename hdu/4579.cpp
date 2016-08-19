#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<stack>
#include<iomanip>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
int n,m;
int c[50005][6];
int sumc[50005];
double mat[50005][12];//0~10 && 11
void output()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<12;j++)
            printf("%.2f ",mat[i][j]);
        printf("\n");
    }
    printf("\n");
}
int main()
{
    while(1)
    {
        memset(sumc,0,sizeof(sumc));
        memset(mat,0,sizeof(mat));
        scanf("%d%d",&n,&m);
        if(n==0&&m==0)
            break;
        for(int i=0; i<n; i++)
            for(int j=1; j<=m; j++)
                scanf("%d",&c[i][j]);
        for(int i=0; i<n; i++)
            for(int j=1; j<=m; j++)
                sumc[i]+=c[i][j];
        for(int i=0;i<n;i++)
        {
            mat[i][11]=-1.0;
            for(int j=-m;j<=m;j++)
            {
                if(j==0)
                    continue;
                if(i+j>=0&&i+j<n)
                {
                    if(j>0)
                        mat[i][5+j]=0.7*c[i][j]/(1.0+sumc[i]);
                    else
                        mat[i][5+j]=0.3*c[i][-j]/(1.0+sumc[i]);
                    mat[i][5]-=mat[i][5+j];
//                    printf("%f %d %d\n",mat[i][5+j],i,5+j);
                }
            }
            for(int i=0;i<12;i++)
                mat[n-1][i]=0.0;
            mat[n-1][5]=1.0;
            mat[n-1][11]=0.0;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<=m&&i+j<n;j++)
            {
                double d=mat[i+j][5-j]/mat[i][5];
                for(int k=0;k<=m;k++)
                    mat[i+j][5-j+k]-=d*mat[i][5+k];
                mat[i+j][11]-=d*mat[i][11];
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int j=1;j<=m&&i-j>=0;j++)
            {
                double d=mat[i-j][5+j]/mat[i][5];
                mat[i-j][5+j]-=d*mat[i][5];
                mat[i-j][11]-=d*mat[i][11];
            }
        }
        printf("%.2f\n",mat[0][11]/mat[0][5]);
    }
    return 0;
}
