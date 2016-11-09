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
int num[10]={6,2,5,5,4,5,6,3,7,6};
int getnum(int n)
{
    int ans=0;
    while(n)
    {
        ans+=num[n%10];
        n/=10;
    }
    return ans;
}
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    int ans=0;
    for(int i=a;i<=b;i++)
        ans+=getnum(i);
    printf("%d\n",ans);
    return 0;
}
