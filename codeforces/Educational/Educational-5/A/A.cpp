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

char str1[1000005],str2[1000005];
int main()
{
    scanf("%s",str1);
    scanf("%s",str2);
    int len1=strlen(str1);
    int len2=strlen(str2);
    int pos1=0;
    int pos2=0;
    while(str1[pos1]=='0'&&pos1<len1-1)
        pos1++;
    while(str2[pos2]=='0'&&pos2<len2-1)
        pos2++;
    int tlen1=len1-pos1;
    int tlen2=len2-pos2;
    if(tlen1>tlen2)
        puts(">");
    else if(tlen1<tlen2)
        puts("<");
    else
    {
        for(int i=0;i<tlen1;i++)
        {
            if(str1[pos1+i]>str2[pos2+i])
            {
                puts(">");
                return 0;
            }
            else if(str1[pos1+i]<str2[pos2+i])
            {
                puts("<");
                return 0;
            }
        }
        puts("=");
    }
    return 0;
}
