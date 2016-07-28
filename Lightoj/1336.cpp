#include<stdio.h>
#include<cmath>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<set>
#include<vector>
#include<map>
using namespace std;
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)<0?-(a):(a))
#define eps 1e-12
#define SIZE 1000005
bool isprime[SIZE];
int prime[SIZE],prinum;
void getprime()//prime
{
    isprime[0]=1;
    isprime[1]=1;
    for(int i=2; i<SIZE; i++)
    {
        if(!isprime[i])
        {
            prime[prinum++]=i;
        }
        for(int j=0; j<prinum; j++)
        {
            if(i*prime[j]>SIZE)
                break;
            isprime[i*prime[j]]=1;
            if(i%prime[j]==0)
                break;
        }
    }
}
vector <long long >ans;
void dfs(long long num,int pos)
{
    ans.push_back(num);
    if(pos==prinum)
    {
        return ;
    }
    long long tmp=num;
    for(int i=pos; i<prinum; i++)
    {
        if(i==0)
        {
            if(num<=1000000000000LL/2LL)
                dfs(num*2,i);
            else
                return ;
        }
        else
        {
            long long t=(long long)prime[i]*(long long)prime[i];
            if(num<=1000000000000LL/t)
                dfs(num*t,i);
            else return;
        }
    }
}
int main()
{
    getprime();
    dfs(1LL,0);
    sort(ans.begin(),ans.end());
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        long long n;
        scanf("%lld",&n);
        int pos=upper_bound(ans.begin(),ans.end(),n)-ans.begin();
        printf("Case %d: %lld\n",cas,n-pos);
    }
    return 0;
}
