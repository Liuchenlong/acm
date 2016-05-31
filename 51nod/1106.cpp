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
#define SIZE 1001005
bool notprime[SIZE];
int prime[SIZE/5];
int prinum;
void getprime()
{
    notprime[1]=1;
    for(int i=2; i<SIZE; i++)
    {
        if(notprime[i])
            continue;
        prime[prinum++]=i;
        for(int j=2*i; j<SIZE; j+=i)
            notprime[j]=1;
    }
}
bool isprime(int x)
{
    if(x==1)
        return false;
    if(x==2||x==3)
        return true;
    for(int i=2; i*i<=x; i++)
        if(x%i==0)
            return false;
    return true;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        if(isprime(x))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
