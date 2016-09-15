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
int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
#define SIZE 100005
//素数,欧拉函数
bool notprime[SIZE];
int prime[SIZE],prinum;
void getprime()//prime
{
    notprime[0]=1;
    notprime[1]=1;
    for(int i=2; i<SIZE; i++)
    {
        if(!notprime[i])
        {
            prime[prinum++]=i;
        }
        for(int j=0; j<prinum; j++)
        {
            if(i*prime[j]>SIZE)
                break;
            notprime[i*prime[j]]=1;
            if(i%prime[j]==0)
                break;
        }
    }
}
int getphi(int x)//get phi(x)
{
    if(x==0)
        return 0;
    int res=1,t=x;
    for(int i=0; i<prinum; i++)
    {
        if(prime[i]*prime[i]>x)
            break;
        if(t%prime[i]==0)
        {
            res*=(prime[i]-1);
            t/=prime[i];
            while(t%prime[i]==0)
            {
                res*=prime[i];
                t/=prime[i];
            }
        }
    }
    if(t>1)
    {
        res*=(t-1);
    }
    return res;
}
int a[10005];
vector<int>vec;
int siz;
bool check(int x)
{
    for(int i=0;i<siz;i++)
    {
        if(x%vec[i]==0)return true;
        if(x<vec[i])break;
    }
    return false;
}
int main()
{
    getprime();
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        vec.clear();
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
            if(a[i]%m!=0)
                vec.push_back(gcd(a[i],m));
        }
        sort(vec.begin(),vec.end());
        siz=unique(vec.begin(),vec.end())-vec.begin();
        long long ans=0;
        for(int i=1; i*i<=m; i++)
        {
            if(m%i==0)
            {
                if(check(i))ans=ans+(long long)m*getphi(m/i)/2;
                if(i*i==m);
                else if(i>1&&check(m/i))ans=ans+(long long)m*getphi(i)/2;
            }
        }
        printf("Case #%d: %I64d\n",cas,ans);
    }
    return 0;
}
