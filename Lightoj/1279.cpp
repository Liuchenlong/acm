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
long long mod=1e9+7;
const int MAXN=105;
long long a[MAXN][MAXN];//增广矩阵
long long x[MAXN];//解集
void output(int equ,int var)
{
    for(int i=0;i<equ;i++)
    {
        for(int j=0;j<=var;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
}
long long qpow(long long x,long long k,long long mod)
{
    long long ans=1;
    while(k)
    {
        if(k&1)
            ans=ans*x%mod;
        k>>=1;
        x=x*x%mod;
    }
    return ans;
}
long long inv(long long x,long long mod)
{
    return qpow(x,mod-2,mod);
}
int gauss(int equ,int var,int mod)
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
            if((a[i][col])>(a[max_r][col]))
                max_r=i;
        }
        if(max_r!=k)
        {
            // 与第k行交换.
            for(j=k; j<var+1; j++)
                swap(a[k][j],a[max_r][j]);
        }
        if((a[k][col])==0)
        {
            // 说明该col列第k行以下全是0了，则处理当前行的下一列.
            k--;
            continue;
        }
        for(i=k+1; i<equ; i++)
        {
            // 枚举要删去的行.
            if((a[i][col])>0)
            {
                for(j=var; j>=col; j--)
                {
                    a[i][j]-=a[k][j]*(a[i][col]*inv(a[k][col],mod)%mod)%mod;
                    a[i][j]=(a[i][j]%mod+mod)%mod;
                }
            }
        }
    }
    for(int i=k; i<equ; i++)//无解
    {
        if((a[i][var])>0)
            return -1;
    }
    if(k<var)//无穷解,返回自由变元个数//会改变解的顺序
    {
        for(int i=0; i<equ; i++)
        {
            if(a[i][i]!=0)
                continue;
            else
            {
                int flag=0;
                for(int j=i+1; j<var; j++)
                {
                    if(a[i][j]!=0)
                    {
                        flag=1;
                        for(int k=0; k<=i; k++)
                        {
                            swap(a[k][i],a[i][j]);
                        }
                        break;
                    }
                }
                if(!flag)
                    return var-i;
            }
        }
        return var-equ;
    }
    return 0;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        memset(a,0,sizeof(a));
        int n,m,K;
        scanf("%d%d%d",&n,&m,&K);
        int equ=n,var=n;
        for(int i=0;i<equ;i++)
            a[i][i]=1;
        for(int i=0;i<m;i++)
        {
            int A,B;
            scanf("%d%d",&A,&B);
            A--;
            B--;
            a[A][B]=K-1;
            a[B][A]=K-1;
        }
        int num=gauss(equ,var,K);
        printf("Case %d: %lld\n",cas,qpow(K,num,mod));
    }
    return 0;
}
