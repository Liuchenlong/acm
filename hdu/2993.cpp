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
int n;
int m;
int num[1000005];
int sum[1000005];
int Q[5000005];
long long getup(int p1,int p2)
{
    return sum[p1]-sum[p2];
}
long long getdown(int p1,int p2)
{
    return p1-p2;
}
double getdp(int pos,int i)
{
    return (double)getup(pos,i)/getdown(pos,i);
}
int input()
{
    char ch=' ';
    while(ch<'0'||ch>'9')ch=getchar();
    int x=0;
    while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
    return x;
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1; i<=n; i++)num[i]=input();
        for(int i=1; i<=n; i++)sum[i]=sum[i-1]+num[i];
        int head=0,tail=0;
        double ans=0.0;
        for(int i=m; i<=n; i++)
        {
            int k=i-m;
            while(head+1<tail&&getup(k,Q[tail-1])*getdown(Q[tail-1],Q[tail-2])<=getup(Q[tail-1],Q[tail-2])*getdown(k,Q[tail-1]))
                tail--;
            Q[tail++]=k;
            while(head+1<tail&&getup(i,Q[head+1])*getdown(i,Q[head])>=getup(i,Q[head])*getdown(i,Q[head+1]))
                head++;
            ans=max(ans,getdp(i,Q[head]));
        }
        printf("%.2f\n",ans);
    }
    return 0;
}
