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
#define SIZE 1000005
bool notprime[SIZE];
int prime[SIZE],prinum;
void getprime()
{
    for(int i=2;i<SIZE;i++)
    {
        if(notprime[i])
            continue;
        prime[prinum++]=i;
        for(int j=2*i;j<SIZE;j+=i)
            notprime[j]=1;
    }
}
int num[SIZE];
int tnum[SIZE];
int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int lcm(int a,int b)
{
    return a/gcd(a,b)*b;
}
void check(int x)
{
    for(int i=0;i<prinum;i++)
    {
        if(prime[i]*prime[i]>x)
            break;
        if(x%prime[i]==0)
        {
            int cnt=0;
            while(x%prime[i]==0)
            {
                cnt++;
                x/=prime[i];
            }
            tnum[prime[i]]=max(tnum[prime[i]],cnt);
        }
    }
    if(x!=1)
    {
        tnum[x]=max(tnum[x],1);
    }
}
int main()
{
    getprime();
    int n,k;
    scanf("%d%d",&n,&k);
    if(k==1)
    {
        printf("Yes\n");
        return 0;
    }
    int t=k;
    for(int i=0;i<prinum;i++)
    {
        if(prime[i]*prime[i]>t)
            break;
        if(t%prime[i]==0)
        {
            while(t%prime[i]==0)
            {
                num[prime[i]]++;
                t/=prime[i];
            }
        }
    }
    if(t!=1)
        num[t]++;
    int ans=1;
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        check(x);
    }
    for(int i=2;i<SIZE;i++)
    {
        if(tnum[i]<num[i])
        {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}
