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
int two[10];
int main()
{
    two[0]=1;
    for(int i=1;i<=9;i++)
        two[i]=two[i-1]*2;
    int n,b,k;
    scanf("%d%d%d",&n,&b,&k);
    int ans1=0;
    int ans2=n*k;
    while(n>1)
    {
        int pos=upper_bound(two,two+10,n)-two-1;
        ans1+=b*two[pos]+two[pos-1];
        n-=two[pos]/2;
    }
    printf("%d %d\n",ans1,ans2);
    return 0;
}
