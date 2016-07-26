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

//此为浮点型模板
//mod p 型需将除法改为乘逆元
int inv[3]= {1,1,2};
const int MAXN=1005;
int a[MAXN][MAXN];//增广矩阵
int x[MAXN];//解集
void output(int equ,int var)
{
    for(int i=0; i<equ; i++)
    {
        for(int j=0; j<=var; j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
}
int gauss(int equ,int var)
{
    memset(x,0,sizeof(x));
    int i,j,k;
    int max_r;// 当前这列绝对值最大的行.
    int col;//当前处理的列
    //转换为阶梯阵.
    col=0; // 当前处理的列
    for(k = 0; k < equ && col < var; k++,col++)
    {
        // 枚举当前处理的行.
        // 找到该col列元素绝对值最大的那行与第k行交换.(为了在除法时减小误差)
        max_r=k;
        for(i=k+1; i<equ; i++)
        {
            if(a[i][col]>a[max_r][col])
                max_r=i;
        }
        if(max_r!=k)
        {
            // 与第k行交换.
            for(j=k; j<var+1; j++)
                swap(a[k][j],a[max_r][j]);
        }
        if(a[k][col]==0)
        {
            // 说明该col列第k行以下全是0了，则处理当前行的下一列.
            k--;
            continue;
        }
        for(i=k+1; i<equ; i++)
        {
            // 枚举要删去的行.
            if(a[i][col]>0)
            {
                for(j=var; j>=col; j--)
                {
                    a[i][j]-=a[k][j]*(a[i][col]*inv[a[k][col]])%3;
                    a[i][j]=(a[i][j]%3+3)%3;
                }
            }
        }
    }
    for(int i=k; i<equ; i++)//无解
    {
        if(a[i][var]>0)
            return -1;
    }
    for(i=var-1; i>=0; i--)
    {
        x[i]=a[i][var]*inv[a[i][i]]%3;
        for(j=0; j<i; j++)
        {
            a[j][var]-=a[i][var]*(a[j][i]*inv[a[i][i]])%3;
            a[j][var]=(a[j][var]%3+3)%3;
        }
    }
    return 0;
}
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int n,m;
int get(int i,int j)
{
    return i*m+j;
}
bool intable(int x,int y)
{
    if(x>=0&&x<n&&y>=0&&y<m)
        return true;
    return false;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(a,0,sizeof(a));
        scanf("%d%d",&n,&m);
        int equ=n*m;
        int var=n*m;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                scanf("%d",&a[get(i,j)][var]);
                a[get(i,j)][var]%=3;
                a[get(i,j)][var]=(3-a[get(i,j)][var])%3;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int now=get(i,j);
                a[now][now]=2;
                for(int k=0;k<4;k++)
                {
                    int nx=i+dx[k];
                    int ny=j+dy[k];
                    if(intable(nx,ny))
                    {
                        a[now][get(nx,ny)]=1;
                    }
                }
            }
        }
        int flag=gauss(equ,var);
        int sum=0;
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)
            sum+=x[get(i,j)];
        printf("%d\n",sum);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                for(int k=0;k<x[get(i,j)];k++)
                printf("%d %d\n",i+1,j+1);
            }
        }
    }
    return 0;
}
