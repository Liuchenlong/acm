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
char str[100005];
int len;
int main()
{
    scanf("%d",&len);
    scanf("%s",str);
    int ans=0;
    int wr=0,wb=0;
    for(int i=0;i<len;i++)
    {
        if(i&1)if(str[i]=='r')wr++;;
        if((i&1)==0)if(str[i]=='b')wb++;
    }
    ans=max(wr,wb);
    wr=0;
    wb=0;
    for(int i=0;i<len;i++)
    {
        if(i&1)if(str[i]=='b')wb++;
        if((i&1)==0)if(str[i]=='r')wr++;
    }
    ans=min(ans,max(wr,wb));
    printf("%d\n",ans);
    return 0;
}
