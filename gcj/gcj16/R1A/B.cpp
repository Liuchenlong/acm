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
int num[3005];
int main()
{
//    freopen("B-small-practice.in","r",stdin);
//    freopen("B-small-practice.out","w",stdout);
//    freopen("B-large-practice.in","r",stdin);
//    freopen("B-large-practice.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        memset(num,0,sizeof(num));
        int n;
        scanf("%d",&n);
        for(int i=0;i<2*n-1;i++)
        {
            for(int j=0;j<n;j++)
            {
                int t;
                scanf("%d",&t);
                num[t]++;
            }
        }
        vector<int>ans;
        for(int i=0;i<=2500;i++)
        {
            if(num[i]&1)
                ans.push_back(i);
        }
        printf("Case #%d:",cas);
        for(int i=0;i<n;i++)
            printf(" %d",ans[i]);
        printf("\n");
    }
    return 0;
}
