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

bool leaf(int x)
{
    if(x%400==0)
        return true;
    if(x%100==0)
        return false;
    if(x%4==0)
        return true;
    return false;
}

int main()
{
    int x;
    scanf("%d",&x);
    int res=0;
    for(int i=x+1;;i++)
    {
        if(leaf(i))
        {
            res=(res+366)%7;
        }
        else
            res=(res+365)%7;
        if(res==0)
        {
            if(leaf(i)&&leaf(x))
            {
                printf("%d\n",i);
                return 0;
            }
            if(!leaf(i)&&!leaf(x))
            {
                printf("%d\n",i);
                return 0;
            }
        }
    }
    return 0;
}
