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
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
long long n;
unsigned long long a,b;
long long len[1005];
int fib[1005][6666];
unsigned long long qpow(unsigned long long x,unsigned long long k,long long len)
{
    if(k==0)
        return 1;
    if(k%2==0)
    {
        long long t=qpow(x,k/2,len);
        return t*t%len;
    }
    else
    {
        long long t=qpow(x,(k-1)/2,len);
        return t*t%len*x%len;
    }
}
int main()
{
    for(int i=1; i<1005; i++)
    {
        fib[i][0]=0;
        fib[i][1]=1%i;
        for(int j=2;; j++)
        {
            fib[i][j]=(fib[i][j-1]+fib[i][j-2])%i;
            if(fib[i][j]==fib[i][1]&&fib[i][j-1]==fib[i][0])
            {
                len[i]=j-1;
                break;
            }
        }
    }
    int t;
    scanf("%d",&t);
    for(int i=0; i<t; i++)
    {
        scanf("%llu%llu%lld",&a,&b,&n);
        if(a==0||n==1)
            printf("0\n");
        else printf("%d\n",fib[n][qpow(a%len[n],b,len[n])]);
    }
    return 0;
}
