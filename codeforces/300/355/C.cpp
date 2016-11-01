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
long long mod=1e9+7;
long long num[64];
char str[1000005];
int getnum(char ch)
{
    if(ch>='0'&&ch<='9')
        return ch-'0';
    if(ch>='A'&&ch<='Z')
        return 10+ch-'A';
    if(ch>='a'&&ch<='z')
        return 36+ch-'a';
    if(ch=='-')
        return 62;
    if(ch=='_')
        return 63;
}
int main()
{
    for(int i=0;i<=63;i++)
    {
        for(int j=0;j<=63;j++)
        {
            num[i&j]++;
        }
    }
    long long ans=1;
    scanf("%s",str);
    for(int i=0;i<strlen(str);i++)
        ans=ans*num[getnum(str[i])]%mod;
    printf("%I64d\n",ans);
    return 0;
}
