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
const double pi=acos(-1.0);
char str[1005];
int main()
{
    int k;
    scanf("%s",str);
    scanf("%d",&k);
    int len=strlen(str);
    if(len%k!=0)
        printf("NO\n");
    else
    {
        int length=len/k;
        int pos=0;
        while(pos<len)
        {
            int flag=1;
            for(int i=0;i<length/2;i++)
            {
                if(str[pos+i]!=str[pos+length-1-i])
                {
                    flag=0;
                    break;
                }
            }
            if(flag==0)
            {
                printf("NO\n");
                return 0;
            }
            pos+=length;
        }
        printf("YES\n");
    }
    return 0;
}
