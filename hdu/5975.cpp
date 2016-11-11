#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
#define eps 1e-8
long long n;
int q;
unsigned long long sum[66];
long long two[66];
unsigned long long qry(long long n)
{
    long long pre=0;
    unsigned long long ans=0;
    for(int i=60;i>=0;i--)
    {
        sum[i]=n/two[i]-pre;
        pre+=sum[i];
        ans+=sum[i]*two[i];
    }
    return ans;
}
unsigned long long qry(long long n,int pos)
{
    if(pos>=0&&n<two[pos])return 0;
    long long pre=0;
    unsigned long long ans=0;
    return n/two[pos]-n/two[pos+1];
    for(int i=60;i>=0;i--)
    {
        sum[i]=n/two[i]-pre;
        pre+=sum[i];
        if(i==pos)
            return sum[i];
    }
    return ans;
}
int main()
{
    two[0]=1;
    for(int i=1;i<=60;i++)two[i]=two[i-1]*2;
    while(scanf("%I64d%d",&n,&q)!=EOF)
    {
        for(int i=0;i<q;i++)
        {
            unsigned long long ans=0;
            int type;
            scanf("%d",&type);
            if(type==1)
            {
                long long L,R;
                scanf("%I64d%I64d",&L,&R);
                ans=qry(R)-qry(L-1);
            }
            else
            {
                long long x;
                scanf("%I64d",&x);
                for(int i=0;i<=60;i++)
                {
                    ans+=qry(min(x+two[i]-1,n),i);
                }
                ans-=(x-1);
            }
            printf("%I64u\n",ans);
        }
    }
    return 0;
}
