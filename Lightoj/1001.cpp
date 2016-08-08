#include<stdio.h>
#include<cmath>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<set>
#include<vector>
#include<map>
using namespace std;
#define eps 1e-9
const double pi=acos(-1.0);

int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        int n;
        scanf("%d",&n);
        int num1,num2;
        if(n>10)
        {
            num1=10;
            num2=n-10;
        }
        else
        {
            num1=0;
            num2=n;
        }
        printf("%d %d\n",num1,num2);
    }
    return 0;
}
