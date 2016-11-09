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
#include<bitset>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
int N=4000000;
long long a[4000000+10];
int lowbit(int x)
{
    return x&(-x);
}
void add(int x,long long info)
{
    for(int i=x; i<=N; i+=lowbit(i))
        a[i]+=info;
}
long long sum(int x)
{
    long long ans=0;
    for(int i=x; i>0; i-=lowbit(i))
        ans+=a[i];
    return ans;
}
int n,m;
long long num[3000000+10];
int other[1000000+10],no;
int main()
{
    scanf("%d",&n);
    int mx=4000000;
    int sqt=(int)sqrt(mx);
    for(int i=0; i<n; i++)
    {
        int x;
        scanf("%d",&x);
        vec.push_back(x);
        num[x]++;
        if(x>sqt)
        {
            other[no++]=x;
        }
    }
    sort(other,other+no);
    int siz=unique(other,other+no)-other;
    for(int i=1; i<=sqt; i++)
    {
        if(num[i]==0)continue;
        for(int j=1; j<=sqt; j++)
        {
            if(num[j]==0)continue;
            if(i==j)
                add(i*j,num[i]*(num[i]-1));
            else
                add(i*j,num[i]*num[j]);
        }
    }
    for(int i=1; i<=sqt; i++)
    {
        if(num[i]==0)
            continue;
        int pos=0;
        while(pos<siz&&other[pos]*i<=mx)
        {
            add(i*other[pos],num[i]*num[other[pos]]*2);
            pos++;
        }
    }
    scanf("%d",&m);
    for(int i=0; i<m; i++)
    {
        int p;
        scanf("%d",&p);
        printf("%I64d\n",(long long)n*(n-1)-sum(p-1));
    }
    return 0;
}
