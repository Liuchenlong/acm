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
char str[105];
int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",str);
    for(int i=0; i<n; i++)
    {
        if(str[i]=='o')
        {
            if(i+2<n)
            {

                if(str[i+1]=='g'&&str[i+2]=='o')
                {
                    printf("***");
                    while(i+2<n&&str[i+1]=='g'&&str[i+2]=='o')
                    {
                        i+=2;
                    }
                }
                else
                    printf("%c",str[i]);
            }
            else
            {
                printf("%c",str[i]);
            }
        }
        else
            printf("%c",str[i]);
    }
    printf("\n");
    return 0;
}
