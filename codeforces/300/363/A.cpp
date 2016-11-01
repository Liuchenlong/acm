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
#include<bitset>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-7
const int maxn=200005;
int n;
int num[maxn];
char str[maxn];
int main()
{
    scanf("%d",&n);
    scanf("%s",str);
    for(int i=0;i<n;i++)
        scanf("%d",&num[i]);
    int ans=-1;
    for(int i=0;i<n-1;i++)
    {
        if(str[i]=='R'&&str[i+1]=='L')
        {
            if(ans==-1)
            {
                ans=(num[i+1]-num[i])/2;
            }
            else
                ans=min(ans,(num[i+1]-num[i])/2);
        }
    }
    printf("%d\n",ans);
    return 0;
}
