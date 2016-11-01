#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
int n;
char str[1005][10];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%s",str[i]);
    bool flag=0;
    for(int i=0;i<n;i++)
    {
        if(str[i][0]=='O'&&str[i][1]=='O')
        {
            flag=1;
            str[i][0]='+';
            str[i][1]='+';
            break;
        }
        if(str[i][3]=='O'&&str[i][4]=='O')
        {
            flag=1;
            str[i][3]='+';
            str[i][4]='+';
            break;
        }
    }
    if(flag)
    {
        printf("YES\n");
        for(int i=0;i<n;i++)printf("%s\n",str[i]);
    }
    else
        printf("NO\n");
    return 0;
}
