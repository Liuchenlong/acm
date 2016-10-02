#include<stdio.h>
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
int num[105];
char str[1005];
int cal(char ch)
{
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='y')return 1;
    return 0;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&num[i]);
    bool flag=1;
    getchar();
    for(int i=0;i<n;i++)
    {
        gets(str);
        int len=strlen(str);
        int cnt=0;
        for(int j=0;j<len;j++)
        {
            cnt+=cal(str[j]);
        }
        if(cnt!=num[i])flag=0;
    }
    if(flag)printf("YES\n");
    else printf("NO\n");
    return 0;
}
