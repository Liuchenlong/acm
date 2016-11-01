#include <cstdio>
#include <cstring>
#include <map>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
#define eps 1e-8
char str[105];
int main()
{
    scanf("%s",str);
    int ans=0;
    int len=strlen(str);
    int pre=-1;
    for(int i=0;i<len;i++)
    {
        if(str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U'||str[i]=='Y')
        {
            ans=max(ans,i-pre);
            pre=i;
        }
    }
    ans=max(ans,len-pre);
    printf("%d\n",ans);
    return 0;
}
