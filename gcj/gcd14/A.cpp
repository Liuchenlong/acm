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
int num[10005];
int main()
{
//    freopen("A-small-practice.in","r",stdin);
//    freopen("A-small-practice.out","w",stdout);
    freopen("A-large-practice.in","r",stdin);
    freopen("A-large-practice.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        int n,x;
        scanf("%d%d",&n,&x);
        for(int i=0; i<n; i++)
            scanf("%d",&num[i]);
        sort(num,num+n);
        int head=0,tail=n-1;
        int ans=0;
        while(head<=tail)
        {
            if(num[tail]+num[head]<=x)
            {
                ans++;
                tail--;
                head++;
            }
            else
            {
                ans++;
                tail--;
            }
        }
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}
