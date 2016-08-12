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

char str[100005];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        scanf("%s",str);
        if(strcmp(str,"()")==0)
        {
            printf("No\n");
            continue;
        }
        int lef=0,rit=0,sum=0;
        for(int i=0;i<strlen(str);i++)
        {
            if(str[i]=='(')
            {
                sum++;
            }
            else
            {
                if(sum==0)
                    rit++;
                else
                    sum--;
            }
        }
        lef=sum;
        if(lef!=rit)
        {
            printf("No\n");
            continue;
        }
        else
        {
            if(lef>2)printf("No\n");
            else printf("Yes\n");
        }
    }
    return 0;
}
