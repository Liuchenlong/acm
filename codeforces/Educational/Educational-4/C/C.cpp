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

int pos(char ch)
{
    if(ch=='<'||ch=='>')
        return 0;
    if(ch=='['||ch==']')
        return 1;
    if(ch=='{'||ch=='}')
        return 2;
    if(ch=='('||ch==')')
        return 3;
}
int lr(char ch)
{
    if(ch=='<'||ch=='{'||ch=='['||ch=='(')
        return 1;
    return 0;
}
stack <char>stk;
char str[1000005];
int main()
{
    scanf("%s",str);
    int len=strlen(str);
    int ans=0;
    for(int i=0;i<len;i++)
    {
        if(lr(str[i]))
        stk.push(str[i]);
        else
        {
            if(stk.empty())
            {
                printf("Impossible\n");
                return 0;
            }

            if(pos(str[i])==pos(stk.top()))
                ;
            else
                ans++;
            stk.pop();
        }
    }
    if(!stk.empty())
        printf("Impossible\n");
    else
    printf("%d\n",ans);
    return 0;
}
