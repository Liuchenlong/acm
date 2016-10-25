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
#define LL long long
#define pii pair<int,int>
char str[200005];
int len;
int main()
{
    scanf("%d",&len);
    scanf("%s",str);
    int ans=0;
    for(int i=0;i<len;i++)
    {
        if(str[i]=='<')
            ans++;
        else
            break;
    }
    for(int i=len-1;i>=0;i--)
    {
        if(str[i]=='>')
            ans++;
        else
            break;
    }
    printf("%d\n",ans);
    return 0;
}
