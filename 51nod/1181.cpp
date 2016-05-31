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
    int pnum=1;
    notprime[1]=1;
    for(int i=2;i<SIZE;i++)
    {
        if(notprime[i])
            continue;
        if(notprime[pnum])
            ;
        else
            prime[prinum++]=i;
        pnum++;
        for(int j=2*i;j<SIZE;j+=i)
            notprime[j]=1;
    }
}
int main()
{
    getprime();
    int n;
    scanf("%d",&n);
    int pos=lower_bound(prime,prime+prinum,n)-prime;
    printf("%d\n",prime[pos]);
    return 0;
}
