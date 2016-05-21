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
#define eps 1e-8
const int mod=9973;
char str[100005];
int pre[100005];
int d,x,y;
int inv[10005];
void getinv()
{
    inv[0]=1;
    inv[1]=1;
    for(int i=2;i<mod;i++)
    {
        inv[i]=(mod-mod/i)*inv[mod%i]%mod;
    }
}
int exgcd(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    else
    {
        int ret=exgcd(b,a%b,x,y);
        int temp=x;
        x=y;
        y=temp-a/b*y;
        return ret;
    }
}
int main()
{
    getinv();
    int m;
    while(scanf("%d",&m)!=EOF)
    {
        scanf("%s",str+1);
        pre[0]=1;
        int len=strlen(str+1);
        for(int i=1;i<=len;i++)
        {
            pre[i]=pre[i-1]*((int)str[i]-28)%mod;
        }
        for(int i=0;i<m;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            printf("%d\n",pre[b]*inv[pre[a-1]]%mod);
        }
    }
    return 0;
}
