#include<stdio.h>
#include<cmath>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<set>
#include<vector>
#include<map>
using namespace std;
char str1[10000005];
int len;
int mod[2][2000];
bool check(int m)
{
    int res=0;
    for(int i=0; i<len; i++)
    {
        if(m==73)
            res=mod[0][(res*10+str1[i]-'0')];
        else
            res=mod[1][(res*10+str1[i]-'0')];
    }
    return res==0;
}
int main()
{
    for(int i=0; i<2000; i++)
    {
        mod[0][i]=i%73;
        mod[1][i]=i%137;
    }
    int n;
    int cas=0;
    while(scanf("%s",&str1)!=EOF)
    {
        len=strlen(str1);
        cas++;
        bool flag1=check(73);
        bool flag2=check(137);
        if(flag1&&flag2)
            printf("Case #%d: YES\n",cas);
        else
            printf("Case #%d: NO\n",cas);
    }
    return 0;
}
