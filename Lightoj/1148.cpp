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
int num[1000005];
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        memset(num,0,sizeof(num));
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            int t;
            scanf("%d",&t);
            num[t+1]++;
        }
        int ans=0;
        for(int i=1;i<=1000001;i++)
        {
            if(num[i]==0)continue;
            ans=ans+num[i]/i*i+(num[i]%i!=0)*i;
        }
        printf("Case %d: %d\n",cas,ans);
    }
    return 0;
}
