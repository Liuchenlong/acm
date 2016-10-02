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

int main()
{
    int type;
    scanf("%d",&type);
    int h,m;
    scanf("%d:%d",&h,&m);
    if(type==12)
    {
        if(h==0)
            h=1;
        if(h>12)
        {
            if(h%10==0)h=10;
            else h=h%10;
        }
        if(m>=60)m%=60;
        printf("%02d:%02d\n",h,m);
    }
    else
    {
        if(h>=24)h%=10;
        if(m>=60)m%=60;
        printf("%02d:%02d\n",h,m);
    }
    return 0;
}
