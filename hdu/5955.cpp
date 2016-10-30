#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
#define eps 1e-12

struct trie
{
    int nxt[6];
    int fail;
    bool bad;
    trie()
    {
        for(int i=0; i<6; i++)nxt[i]=-1;
        fail=-1;
        bad=false;
    }
};
trie node[1005];
int tot;
void insert(int str[],int len)
{
    int k;
    int rt=0;
    for(k=0; k<len; k++)
    {
        int nt=str[k]-1;
        if(node[rt].nxt[nt]==-1)
            node[rt].nxt[nt]=++tot;
        rt=node[rt].nxt[nt];
    }
    node[rt].bad=true;
}
void getfail()
{
    int rt=0,son,tmp;
    queue<int>Q;
    for(int i=0; i<6; i++)
    {
        if(node[rt].nxt[i]==-1)
            node[rt].nxt[i]=rt;
        else
        {
            node[node[rt].nxt[i]].fail=rt;
            Q.push(node[rt].nxt[i]);
        }
    }
    while(!Q.empty())
    {
        tmp=Q.front();
        Q.pop();
        for(int i=0; i<6; i++)
        {
            son=node[tmp].nxt[i];
            if(son!=-1)
            {
                node[son].fail=node[node[tmp].fail].nxt[i];
                Q.push(son);
            }
            else
            {
                node[tmp].nxt[i]=node[node[tmp].fail].nxt[i];
            }
        }
    }
}
const int MAXN=1005;
double a[MAXN][MAXN];//增广矩阵
double x[MAXN];//解集
void output(int equ,int var)
{
    for(int i=0; i<equ; i++)
    {
        for(int j=0; j<=var; j++)
            printf("%.2f ",(double)a[i][j]);
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
            if(fabs(a[i][col])>fabs(a[max_r][col]))
                max_r=i;
        }
        if(max_r!=k)
        {
            // 与第k行交换.
            for(j=k; j<var+1; j++)
                swap(a[k][j],a[max_r][j]);
        }
        if(fabs(a[k][col])<=eps)
        {
            // 说明该col列第k行以下全是0了，则处理当前行的下一列.
            k--;
            continue;
        }
        for(i=k+1; i<equ; i++)
        {
            // 枚举要删去的行.
            if(fabs(a[i][col])>eps)
            {
                for(j=var; j>=col; j--)
                {
                    a[i][j]-=(a[k][j]*a[i][col]/a[k][col]);
                }
            }
        }
    }
    for(int i=k; i<equ; i++)//无解
    {
        if(fabs(a[i][var])>eps)
            return -1;
    }
    for(i=var-1; i>=0; i--)
    {
        x[i]=a[i][var]/a[i][i];
        for(j=0; j<i; j++)
        {
            a[j][var]-=(a[i][var]*a[j][i]/a[i][i]);
        }
    }
    return 0;
}
void run()
{
    int var=tot+1;
    int equ=var;
    memset(a,0,sizeof(a));
    for(int i=0; i<var; i++)
    {
        a[i][i]=-1;
        for(int j=0; j<6; j++)
        {
            if(!node[i].bad)
                a[node[i].nxt[j]][i]+=1.0/6;
        }
    }
    for(int i=0; i<var; i++)
    {
        if(node[i].bad)
            a[0][i]=1;
        else
            a[0][i]=0;
    }
    a[0][var]=1;
    gauss(equ,var);
    bool flag=false;
    for(int i=0; i<var; i++)
        if(node[i].bad)
        {
            if(flag)printf(" ");
            flag=true;
            printf("%.6f",x[i]);
        }
    puts("");
}
int n,l;
int num[12];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        for(int i=0; i<=1000; i++)
        {
            for(int j=0; j<6; j++)node[i].nxt[j]=-1;
            node[i].fail=-1;
            node[i].bad=false;
        }
        tot=0;
        scanf("%d%d",&n,&l);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<l; j++)scanf("%d",&num[j]);
            insert(num,l);
        }
        getfail();
        run();
    }
    return 0;
}
