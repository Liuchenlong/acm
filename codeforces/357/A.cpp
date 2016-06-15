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
#define eps 1e-12

int main()
{
    int flag=0;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        char str[22];
        scanf("%s",str);
        int bef,las;
        scanf("%d%d",&bef,&las);
        if(bef>=2400&&las>bef)
            flag=1;
    }
    if(flag)printf("YES\n");
    else printf("NO\n");
    return 0;
}
