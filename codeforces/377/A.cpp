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


int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    for(int i=1;i<=10;i++)
    {
        if(a*i%10==b||a*i%10==0)
        {
            printf("%d\n",i);
            return 0;
        }
    }
    return 0;
}
