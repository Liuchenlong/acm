#include<cstdio>
//#include<cmath>
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
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) (x>=0?x:-x)
#define INF 0x7fffffff
#define SIZE 100005
#define mod 100000007



int main()
{
    int n,m,i,j,a,b;
    scanf("%d%d%d%d%d%d",&n,&m,&i,&j,&a,&b);
    int ans=INF;

    if(i==1&&j==i)
    {
        printf("0\n");
        return 0;
    }
    else if(i==1&&j==m)
    {
        printf("0\n");
        return 0;
    }
    else if(j==1&&i==n)
    {
        printf("0\n");
        return 0;
    }
    else if(i==n&&j==m)
    {
        printf("0\n");
        return 0;
    }

    if(i+a>n&&i-a<1||j+b>m&&j-b<1)
    {
        printf("Poor Inna and pony!\n");
        return 0;
    }


    if(((i-1)%a==0)&&((j-1)%b==0))
    {
        int t1=(i-1)/a;
        int t2=(j-1)/b;
        if(abs(t2-t1)%2==0)
        {
            ans=min(ans,max(t1,t2));
        }
    }

    if((i-1)%a==0&&(m-j)%b==0)
    {
        int t1=(i-1)/a;
        int t2=(m-j)/b;
        if(abs(t2-t1)%2==0)
        {
            ans=min(ans,max(t1,t2));
        }
    }

    if((n-i)%a==0&&(j-1)%b==0)
    {
        int t1=(n-i)/a;
        int t2=(j-1)/b;
        if(abs(t2-t1)%2==0)
        {
            ans=min(ans,max(t1,t2));
        }
    }

    if((n-i)%a==0&&(m-j)%b==0)
    {
        int t1=(n-i)/a;
        int t2=(m-j)/b;
        if(abs(t2-t1)%2==0)
        {
            ans=min(ans,max(t1,t2));
        }
    }

    if(ans==INF)
    {
        printf("Poor Inna and pony!\n");
    }
    else
        printf("%d\n",ans);
    return 0;
}
