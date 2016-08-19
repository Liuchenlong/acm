#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) (x>=0?x:-x)
#define INF 0x7fffffff
#define SIZE 1000005

char str[1000005];
int main()
{
    scanf("%s",str);
    int len=strlen(str);
    int tlen=1;
    long long ans=1;
    for(int i=1; i<len; i++)
    {
        if(str[i]+str[i-1]-'0'-'0'==9)
        {
            tlen++;
        }
        else
        {

            if(tlen%2==1&&tlen!=1)
            {
                ans=ans*(tlen+1)/2;
            }
            else
                ans=ans*1;
            tlen=1;
        }
    }
    if(tlen%2==1&&tlen!=1)
    {
        ans=ans*(tlen+1)/2;
    }
    else
        ans=ans*1;
    printf("%I64d\n",ans);
    return 0;
}
