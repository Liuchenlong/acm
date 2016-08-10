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
#define SIZE 100005
bool isprime[SIZE];
int prime[SIZE],prinum;
void getprime()
{
    for(int i=2;i<SIZE;i++)
    {
        if(isprime[i])
            continue;
        prime[prinum++]=i;
        for(int j=2*i;j<SIZE;j+=i)
            isprime[j]=1;
    }
}
int qpow(int n,int k)
{
    if(k==0)
        return 1;
    if(k%2==0)
    {
        int t=qpow(n,k/2);
        return t*t;
    }
    else
    {
        int t=qpow(n,(k-1)/2);
        return t*t*n;
    }
}
struct pri
{
    int num;
    int shu;
}res[1005];
int resnum;
int main()
{
    getprime();
    int n,k;
    char ch;
    int ans=1;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)
            break;
        scanf("%d",&k);
        ch=getchar();
        ans*=qpow(n,k);
        if(ch=='\n')
        {
            memset(res,0,sizeof(res));
            resnum=0;
            ans--;
            for(int i=0;prime[i]<=ans;i++)
            {
                int ternum=0;
                if(ans%prime[i]==0)
                {
                    while(ans%prime[i]==0)
                    {
                        ternum++;
                        ans/=prime[i];
                    }
                    res[resnum].num=prime[i];
                    res[resnum++].shu=ternum;
                }
            }
            if(ans>1)
            {
                res[resnum].num=ans;
                res[resnum++].shu=1;
            }
            for(int i=resnum-1;i>=0;i--)
            {
                printf("%d %d ",res[i].num,res[i].shu);
            }
            printf("\n");
            ans=1;
        }
    }
    return 0;
}
