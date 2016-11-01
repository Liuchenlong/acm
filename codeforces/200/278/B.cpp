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
#define LL long long
#define pii pair<int,int>
int n;
int a[10];
int vec[4];
bool check()
{
    for(int i=0;i<4;i++)vec[i]=a[i];
    sort(vec,vec+4);
    int ans=vec[3]-vec[0];
    int sum1=vec[0]+vec[1]+vec[2]+vec[3];
    int sum2=vec[1]+vec[2];
    if(sum1==ans*4&&sum2==ans*2)
        return true;
    return false;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    if(n==0)
    {
        printf("YES\n");
        printf("1\n1\n3\n3\n");
    }
    else if(n==1)
    {
        printf("YES\n");
        printf("%d\n%d\n%d\n",a[0],3*a[0],3*a[0]);
    }
    else if(n==2)
    {
        for(int i=1;i<=5000;i++)for(int j=1;j<=5000;j++)
        {
            a[2]=i;
            a[3]=j;
            if(check())
            {
                printf("YES\n");
                printf("%d\n%d\n",i,j);
                return 0;
            }
        }
        printf("NO\n");
    }
    else if(n==3)
    {
        for(int i=1;i<=100000;i++)
        {
            a[3]=i;
            if(check())
            {
                printf("YES\n");
                printf("%d\n",i);
                return 0;
            }
        }
        printf("NO\n");
    }
    else if(n==4)
    {
        if(check())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
