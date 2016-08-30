#include<stdio.h>
#include<math.h>
#include<vector>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)

int num[105];
int gao(int a,int num[],int n)
{
    int ans=999999;
    int t;
    int anspos=0;
    int w[105];
    for(int i=0;i<n;i++)
        w[i]=num[i];
    for(int i=0;i<n;i++)
    {
        int term=0;
        t=a;
        while(w[i]||t)
        {
            if((w[i]%2)!=(t%2))
            {
                term++;
            }
            w[i]/=2;
            t/=2;
        }
        if(term<=ans)
        {
            ans=term;
            anspos=i;
        }
    }
    return num[anspos];
}
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int t;
    int n,m;
    int a;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%d",&num[i]);
        sort(num,num+n,cmp);
        for(int i=0;i<m;i++)
        {
            scanf("%d",&a);
            printf("%d\n",gao(a,num,n));
        }
    }
    return 0;
}
