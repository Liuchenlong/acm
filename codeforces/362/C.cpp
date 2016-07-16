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
map<long long,long long>cost;
void add(long long u,long long v,long long w)
{
    if(u==v)
        return ;
    if(u>v)
    {
        cost[u]+=w;
        add(u/2,v,w);
    }
    else
    {
        cost[v]+=w;
        add(u,v/2,w);
    }
}
long long query(long long u,long long v)
{
    if(u==v)
        return 0;
    else if(u>v)
    {
        return cost[u]+query(u/2,v);
    }
    else
    {
        return cost[v]+query(u,v/2);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        int type;
        scanf("%d",&type);
        if(type==1)
        {
            long long u,v,w;
            scanf("%I64d%I64d%I64d",&u,&v,&w);
            add(u,v,w);
        }
        else
        {
            long long u,v;
            scanf("%I64d%I64d",&u,&v);
            printf("%I64d\n",query(u,v));
        }
    }
    return 0;
}
