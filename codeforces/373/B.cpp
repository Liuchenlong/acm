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
    for(int i=0;i<len;i++)
    {
        if(i&1)if(str[i]=='r')ans++;
        if((i&1)==0)if(str[i]=='b')ans++;
    }
    int ans2=0;
    for(int i=0;i<len;i++)
    {
        if(i&1)if(str[i]=='b')ans2++;
        if((i&1)==0)if(str[i]=='r')ans2++;
    }
    printf("%d\n",min(ans,ans2));
    return 0;
}
