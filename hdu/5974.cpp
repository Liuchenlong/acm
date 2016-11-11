#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
#define eps 1e-8

const int maxn=100005;
bool notprime[maxn];
int prime[maxn],prinum;
void init()
{
    for(int i=2;i<maxn;i++)
    {
        if(notprime[i])
            continue;
        prime[prinum++]=i;
        for(int j=2*i;j<maxn;j+=i)
            notprime[j]=1;
    }
}
int fac[10][2];
int fnum;
void getfac(int x)
{
    fnum=0;
    for(int i=0;i<prinum;i++)
    {
        if(prime[i]*prime[i]>x)break;
        if(x%prime[i]==0)
        {
            fac[fnum][0]=prime[i];
            fac[fnum][1]=1;
            x/=prime[i];
            while(x%prime[i]==0)
            {
                fac[fnum][1]++;
                x/=prime[i];
            }
            fnum++;
        }
    }
    if(x!=1)
    {
        fac[fnum][0]=x;
        fac[fnum][1]=1;
        fnum++;
    }
}
int factors[10005];
int fsnum;
void dfs(int pos,int val)
{
    if(pos==fnum)
    {
        factors[fsnum++]=val;
        return ;
    }
    for(int i=0;i<=fac[pos][1];i++)
    {
        dfs(pos+1,val);
        val*=fac[pos][0];
    }
}
int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int lcm(int a,int b)
{
    return a/gcd(a,b)*b;
}
int main()
{
    init();
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        getfac(b);
        fsnum=0;
        dfs(0,1);
        bool flag=false;
        int ans=1000000000;
        for(int i=0;i<fsnum;i++)
        {
            if(factors[i]>=a)continue;
            if(lcm(factors[i],a-factors[i])==b)
            {
                ans=min(ans,factors[i]);
                flag=true;
            }
        }
        if(!flag)
            printf("No Solution\n");
        else
            printf("%d %d\n",ans,a-ans);
    }
    return 0;
}
