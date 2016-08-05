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
#define eps 1e-14

int main()
{
    int n;
    scanf("%d",&n);
    int val1=0,val2=0;
    for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if(a>b)
            val1++;
        else if(a<b)
            val2++;
    }
    if(val1>val2)puts("Mishka");
    else if(val1<val2)puts("Chris");
    else puts("Friendship is magic!^^");
    return 0;
}
