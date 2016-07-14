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

char another(char ch)
{
    if(ch=='A'||ch=='O'||ch=='o'||ch=='T'||ch=='H'||ch=='U'||ch=='V'||ch=='v'||ch=='I'
       ||ch=='W'||ch=='w'||ch=='X'||ch=='x'||ch=='M'||ch=='Y')
        return ch;
    if(ch=='b')return 'd';
    if(ch=='d')return 'b';
    if(ch=='p')return 'q';
    if(ch=='q')return 'p';
    return '#';
}

char str[1005];
int main()
{
    scanf("%s",str);
    int len=strlen(str);
    bool flag=true;
    for(int i=0;i<=len/2;i++)
        if(str[len-1-i]!=another(str[i]))
    {
        flag=false;
        break;
    }
    if(flag)
        printf("TAK\n");
    else
        printf("NIE\n");
    return 0;
}
