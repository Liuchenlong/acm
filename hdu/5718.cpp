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
#include<bitset>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
char str[10000005];
int num[10000005];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",str);
        int len=strlen(str);
        sort(str,str+len);
        int pos=len-1;
        int x;
        for(int i=0;i<len;i++)
        {
            if(str[i]!='0')
            {
                pos=i;
                x=str[i]-'0';
                break;
            }
        }
        if(pos==len-1)
            printf("Uncertain\n");
        else
        {
            for(int i=0;i<len;i++)
                num[i]=str[i]-'0';
            num[len]=0;
            if(num[0]==0)
            {
                for(int i=len-1;i>=0;i--)
                {
                    if(i==pos)continue;
                    if(i==0)printf("%d\n",x);
                    else
                        printf("%d",num[i]);
                }
            }
            else
            {
                num[1]+=x;
                for(int i=1;i<len;i++)
                {
                    num[i+1]+=num[i]/10;
                    num[i]%=10;
                }
                int head=len;
                if(num[head]==0)head--;
                for(int i=head;i>=1;i--)printf("%d",num[i]);
                printf("\n");
            }
        }
    }
    return 0;
}
