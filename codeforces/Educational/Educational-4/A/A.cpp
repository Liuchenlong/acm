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
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)<0?-(a):(a))

char str[105];
int main()
{
    int n,p,q;
    scanf("%d%d%d",&n,&p,&q);
    scanf("%s",str);
    int len=strlen(str);
    for(int i=0;i<=len/p;i++)
    {
        if((len-i*p)%q==0)
        {
            printf("%d\n",i+(len-i*p)/q);
            for(int j=0;j<i;j++)
            {
                for(int k=0;k<p;k++)
                    printf("%c",str[k+j*p]);
                printf("\n");
            }
            for(int j=0;j<(len-i*p)/q;j++)
            {
                for(int k=0;k<q;k++)
                    printf("%c",str[i*p+k+q*j]);
                printf("\n");
            }
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
