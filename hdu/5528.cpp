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
#define SIZE 100005
bool notprime[SIZE];
int prime[SIZE],prinum;
void getprime()
{
    for(int i=2; i<SIZE; i++)
    {
        if(notprime[i])
            continue;
        prime[prinum++]=i;
        for(int j=2*i; j<SIZE; j+=i)
            notprime[j]=1;
    }
}
unsigned long long g(int p,int k)
{
    unsigned long long ans=1;
    unsigned long long fk=1;
    unsigned long long phi=p-1;
    for(int i=1; i<=k; i++)
    {
        fk=fk*p+phi;
        phi=phi*p;
        ans=ans+fk;
    }
    return ans;
}
unsigned long long cal(int n)
{
    unsigned long long ans=1;
    for(int i=0; i<prinum; i++)
    {
        if(prime[i]>n/prime[i])
            break;
        if(n%prime[i]==0)
        {
            int p=prime[i];
            int k=0;
            while(n%prime[i]==0)
            {
                k++;
                n/=prime[i];
            }
            ans=ans*g(p,k);
        }
    }
    if(n!=1)
        ans=ans*g(n,1);
    return ans;
}
int factor[22][2];
int facnum;
void getfac(int n)
{
    facnum=0;
    memset(factor,0,sizeof(factor));
    for(int i=0; i<prinum; i++)
    {
        if(prime[i]>n/prime[i])
            break;
        if(n%prime[i]==0)
        {
            factor[facnum][0]=prime[i];
            while(n%prime[i]==0)
            {
                factor[facnum][1]++;
                n/=prime[i];
            }
            facnum++;
        }
    }
    if(n!=1)
    {
        factor[facnum][0]=n;
        factor[facnum][1]=1;
        facnum++;
    }
}
int n;
unsigned long long ans1;
void dfs(int pos,unsigned long long num)
{
    if(pos==facnum)
    {
        ans1+=num*num;
        return ;
    }
    for(int i=0; i<=factor[pos][1]; i++)
    {
        dfs(pos+1,num);
        num*=factor[pos][0];
    }
}
int main()
{
    getprime();
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        ans1=0;
        unsigned long long ans2=0;
        getfac(n);
        dfs(0,1);
        ans2=cal(n);
        printf("%I64u\n",ans1-ans2);
    }
    return 0;
}
