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
char str[200005];
int len,k;
int num[200005];
int main()
{
    scanf("%d%d",&len,&k);
    scanf("%s",str);
    for(int i=0;i<len;i++)
    {
        if(str[i]=='.')num[i]=-1;
        else num[i]=str[i]-'0';
    }
    bool flag=false;
    int tail=0;
    for(int i=0;i<len;i++)
    {
        if(num[i]==-1)flag=true;
        if(flag&&num[i]>=5)
        {
            tail=i;
            break;
        }
    }
    if(!flag||tail==0)
    {
        printf("%s\n",str);
        return 0;
    }
    while(1)
    {
        if(num[tail]>=5)
        {
            if(num[tail-1]==-1)
            {
                num[tail-2]++;
                tail=tail-2;
                break;
            }
            else
            {
                num[tail-1]++;
                tail--;
                k--;
            }
        }
        else
            break;
        if(k==0)break;
    }
    for(int i=tail;i>0;i--)
    {
        if(num[i]>=10)
        {
            num[i-1]+=num[i]/10;
            num[i]%=10;
        }
    }
    for(int i=0;i<=tail;i++)
    {
        if(num[i]==-1)printf(".");
        else printf("%d",num[i]);
    }
    printf("\n");
    return 0;
}
