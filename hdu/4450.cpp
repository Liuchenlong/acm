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
#define maxn 105

int n;
int num[105];
int main()
{
    while(scanf("%d",&n),n)
    {
        int ans=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&num[i]);
            ans+=num[i]*num[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}
