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
int n,h;
int main()
{
    scanf("%d%d",&n,&h);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int t;
        scanf("%d",&t);
        if(t>h)
            ans+=2;
        else
            ans++;
    }
    printf("%d\n",ans);
    return 0;
}
