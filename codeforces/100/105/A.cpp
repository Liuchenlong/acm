#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
const double pi=acos(-1.0);
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
#define eps 1e-8

int num[100005];
int main()
{
    int k,l,m,n;
    scanf("%d%d%d%d",&k,&l,&m,&n);
    int d;
    scanf("%d",&d);
    int sum=d;
    for(int i=1;i<=d;i++)
    {
        if(num[i]==0&&(i%k==0||i%l==0||i%m==0||i%n==0))
        {
            num[i]=1;
            sum--;
        }
    }
    printf("%d\n",d-sum);
    return 0;
}
