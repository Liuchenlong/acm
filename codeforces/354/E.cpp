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
int n,k;
int val[100005];
int main()
{
    int inf = 1e9;
    scanf("%d%d",&n,&k);
    int cnt=0;
    for(int i=0;i<=n;i++)
    {
        char str[10];
        scanf("%s",str);
        if(str[0]=='?')
        {
            cnt++;
            val[i]=inf;
        }
        else
        {
            if(str[0]=='-')
                val[i]=atoi(str+1)*-1;
            else
                val[i]=atoi(str);
        }
    }
    if(k==0)
    {
        if(val[0]==0||(val[0]==inf&&(n+1-cnt)%2==1))
            printf("Yes\n");
        else
            printf("No\n");
    }
    else
    {
        if(cnt==0)
        {
            long long ans=0;
            for(int i=n;i>=0&&abs(ans)<=1e12;i--)
            {
                ans=ans*k+val[i];
            }
            if(ans==0)
                printf("Yes\n");
            else
                printf("No\n");
        }
        else
        {
            if(n%2==0)
                printf("No\n");
            else
                printf("Yes\n");
        }
    }
    return 0;
}
