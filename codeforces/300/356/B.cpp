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
int num[105];
int main()
{
    int n,a;
    scanf("%d%d",&n,&a);
    for(int i=1;i<=n;i++)
        scanf("%d",&num[i]);
    int ans=0;
    for(int i=0;i<=100;i++)
    {
        if(a-i<1&&a+i>n)
            break;
        if(a-i<1)if(num[a+i]==1){ans++;continue;}
        if(a+i>n)if(num[a-i]==1){ans++;continue;}
        if(num[a+i]==1&&num[a-i]==1){ans+=(1+(i!=0));continue;}

    }
    printf("%d\n",ans);
    return 0;
}
