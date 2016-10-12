#include<bits/stdc++.h>
using namespace std;
int n,a,b;
long long d;
long long cost[100005];
int main()
{
    scanf("%d%I64d%d%d",&n,&d,&a,&b);
    for(int i=0;i<n;i++)scanf("%I64d",&cost[i]);
    int up=0;
    int down=0;
    int flag=0;
    long long has=0;
    for(int i=1;i<n;i++)
    {
        if(cost[i]>cost[i-1])
        {
            if(flag==1)up++;
            else up=1;
            flag=1;
            down=0;
            long long buy=min(1LL*a*up,d/cost[i]);
            has+=buy;
            d-=buy*cost[i];
        }
        else if(cost[i]==cost[i-1])
        {
            flag=0;
            up=0;
            down=0;
        }
        else
        {
            if(flag==-1)down++;
            else down=1;
            up=0;
            flag=-1;
            long long sell=min(has,1LL*b*down);
            d+=sell*cost[i];
            has-=sell;
        }
    }
    printf("%I64d %I64d\n",d,has);
    return 0;
}
