#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<stack>
#include<iomanip>
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
int n,m;
map<int,int>mp;
int num[SIZE];
int ansnum[SIZE];
int main()
{
    getprime();
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
        if(num[i]<=m)
            mp[num[i]]++;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=i;j<=m;j+=i)
            ansnum[j]+=mp[i];
    }
    int ans=1,tnum=mp[1];
    for(int i=2;i<=m;i++)
    {
        if(ansnum[i]>tnum)
        {
            tnum=ansnum[i];
            ans=i;
        }
    }
    printf("%d %d\n",ans,tnum);
    for(int i=0;i<n;i++)
    {
        if(ans%num[i]==0)
            printf("%d ",i+1);
    }
    printf("\n");
    return 0;
}
