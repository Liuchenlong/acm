#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
int siz;
struct matrix
{
    long long num[105][105];
    matrix()
    {
        memset(num,0,sizeof(num));
    }
}E;
matrix mult(matrix a,matrix b)
{
    matrix c;
    for(int i=0;i<siz;i++)
    {
        for(int k=0;k<siz;k++)
        {
            if(a.num[i][k])
            {
                for(int j=0;j<siz;j++)
                {
                    c.num[i][j]+=a.num[i][k]*b.num[k][j];
                }
            }
        }
    }
    return c;
}
matrix qpow(matrix X,int k)
{
    matrix ans=E;
    while(k)
    {
        if(k&1)
        {
            ans=mult(ans,X);
        }
        k>>=1;
        X=mult(X,X);
    }
    return ans;
}
int n,m,k;
int main()
{
    for(int i=0;i<105;i++)E.num[i][i]=1;
    while(1)
    {
        scanf("%d%d%d",&n,&m,&k);
        if(n==0&&m==0&&k==0)
            break;
        siz=n+1;
        matrix X;
        X.num[siz-1][0]=1;
        matrix A=E;
        for(int i=0;i<k;i++)
        {
            char str[10];
            scanf("%s",str);
            if(str[0]=='g')
            {
                int x;
                scanf("%d",&x);
                x--;
                matrix B=E;
                B.num[x][siz-1]=1;
                A=mult(B,A);
            }
            if(str[0]=='e')
            {
                int x;
                scanf("%d",&x);
                x--;
                matrix B=E;
                B.num[x][x]=0;
                A=mult(B,A);
            }
            if(str[0]=='s')
            {
                int x,y;
                scanf("%d%d",&x,&y);
                x--;
                y--;
                matrix B=E;
                B.num[x][x]=0;
                B.num[y][y]=0;
                B.num[x][y]=1;
                B.num[y][x]=1;
                A=mult(B,A);
            }
        }
        A=qpow(A,m);
        matrix ans=mult(A,X);
        for(int i=0;i<siz-1;i++)
        {
            if(i)printf(" ");
            printf("%lld",ans.num[i][0]);
        }
        printf("\n");
    }
    return 0;
}
