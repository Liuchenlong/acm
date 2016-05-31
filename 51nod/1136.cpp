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
int main()
{
    getprime();
    int x;
    scanf("%d",&x);
    int ans=x;
    for(int i=0; i<prinum; i++)
    {
        if(prime[i]>x/prime[i])
            break;
        if(x%prime[i]==0)
        {
            ans=ans/prime[i]*(prime[i]-1);
            while(x%prime[i]==0)
                x/=prime[i];
        }
    }
    if(x!=1)
        ans=ans/x*(x-1);
    printf("%d\n",ans);
    return 0;
}
