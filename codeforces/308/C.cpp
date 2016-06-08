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
long long pw[25];
long long sum[25];
int pos=0;
bool dfs(int now,long long sum,int state)
{
    if(sum==0)
        return true;
    if(sum<0)
        return false;
    if(sum<pw[now])
        return false;
    if(now>pos)
        return false;
    if((1<<now)&state)
        return dfs(now+1,sum,state);
    if(dfs(now+1,sum-pw[now],state))
        return true;
    if(dfs(now+1,sum,state))
        return true;
    return false;
}
int main()
{
    int w,m;
    scanf("%d%d",&w,&m);
    if(w==2||w==3)
        printf("YES\n");
    else
    {
        pw[0]=1;
        sum[0]=1;
        for(int i=1;i<=22;i++)
        {
            pw[i]=pw[i-1]*w;
            sum[i]=sum[i-1]+pw[i];
        }

        for(int i=0;i<=22;i++)
        {
            if(sum[i]+m<pw[i+1])
            {
                pos=i+1;
                break;
            }
        }
        pos++;
        for(int i=0;i<(1<<pos);i++)
        {
            long long sum=m;
            for(int j=0;j<pos;j++)
            {
                if(i&(1<<j))
                    sum+=pw[j];
            }
            if(dfs(0,sum,i))
            {
                printf("YES\n");
                return 0;
            }
        }
        printf("NO\n");
    }
    return 0;
}
