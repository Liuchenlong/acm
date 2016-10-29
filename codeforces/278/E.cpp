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
bool isprime(int n)
{
    for(int i=2; i*i<=n; i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}
int qpow(long long x,int k,int mod)
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
int a[100005];
int main()
{
    int n;
    scanf("%d",&n);
    if(n==1)
    {
        printf("YES\n");
        printf("1");
    }
    else if(n==2)
    {
        printf("YES\n");
        printf("1\n2\n");
    }
    else if(n==3)
    {
        printf("YES\n");
        printf("1\n2\n3\n");
    }
    else if(n==4)
    {
        printf("YES\n");
        printf("1\n3\n2\n4\n");
    }
    else
    {
        if(isprime(n))
        {
            printf("YES\n");
            a[1]=1;
            for(int i=2;i<n;i++)
                a[i]=1LL*i*qpow(i-1,n-2,n)%n;
            a[n]=n;
            for(int i=1;i<=n;i++)
                printf("%d\n",a[i]);
        }
        else
            printf("NO\n");
    }
    return 0;
}
