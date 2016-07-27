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
#define abs(a) (a<0?-a:a)
#define SIZE 2000005
const long long mod=1e9+7;
bool notprime[SIZE];
int prime[SIZE],prinum;
void getprime()
{
    for(int i=2;i<SIZE;i++)
    {
        if(notprime[i])continue;
        prime[prinum++]=i;
        for(int j=i*2;j<SIZE;j+=i)
            notprime[j]=1;
    }
}
long long t;
long long a,b;
long long fac[30][2];
int facnum;
long long ans;
void dfs(int pos,long long val)
{
    if(pos==facnum)
    {
        if(val<=t/val&&val*val!=t)
        {
            ans++;
        }
        return ;
    }
    for(int j=0;j<=fac[pos][1];j++)
    {
        dfs(pos+1,val);
        if(val/fac[pos][0]<b)
            break;
        val/=fac[pos][0];
    }
}
int main()
{
    getprime();
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        scanf("%lld%lld",&a,&b);
        facnum=0;
        ans=0;
        t=a;
        memset(fac,0,sizeof(fac));
        for(int i=0;i<prinum;i++)
        {
            if(prime[i]>a/prime[i])
                break;
            if(a%prime[i]==0)
            {
                fac[facnum][0]=prime[i];
                while(a%prime[i]==0)
                {
                    fac[facnum][1]++;
                    a/=prime[i];
                }
                facnum++;
            }
        }
        if(a!=1)
        {
            fac[facnum][0]=a;
            fac[facnum][1]=1;
            facnum++;
        }
        dfs(0,t);
        printf("Case %d: %lld\n",cas,ans);
    }
    return 0;
}
