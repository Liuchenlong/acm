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

int n,m;
int num[10];
long long gcd(long long a,long long b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
long long lcm(long long a,long long b)
{
    return a/gcd(a,b)*b;
}
int main()
{
//    printf("%I64d\n",2LL*3*5*7*11*13*17*19);
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        n--;
        for(int i=0; i<m; i++)
        {
            scanf("%d",&num[i]);
            if(num[i]==0)
            {
                i--;
                m--;
            }
        }
        int sum=0;
        for(int i=0; i<(1<<m); i++)
        {
            int sig=1;
            long long v=1;
            for(int j=0; j<m; j++)
            {
                if(i&(1<<j))
                {
                    sig*=-1;
                    v=lcm(v,num[j]);
                }
            }
            sum+=sig*(n/v);
        }
        printf("%d\n",n-sum);
    }
    return 0;
}
