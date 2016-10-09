#include <bits/stdc++.h>
using namespace std ;

char str1[12];
char str2[12];
int cal(char str[])
{
    if(str[0]=='m')return 0;
    if(str[0]=='t'&&str[1]=='u')return 1;
    if(str[0]=='w')return 2;
    if(str[0]=='t'&&str[1]=='h')return 3;
    if(str[0]=='f')return 4;
    if(str[0]=='s'&&str[1]=='a')return 5;
    return 6;
}
int mon[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main()
{
    scanf("%s%s",str1,str2);
    int now,next;
    now=cal(str1);
    next=cal(str2);
    for(int i=0;i<11;i++)
    {
        if((now+mon[i])%7==next)
        {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}
