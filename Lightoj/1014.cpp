#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(a) (a<0?-a:a)


int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        vector<int>ans;
        int L,P;
        scanf("%d%d",&P,&L);
        P-=L;
        for(int i=1;i<=P/i;i++)
        {
            if(P%i==0)
            {
                if(i>L)
                    ans.push_back(i);
                if(i*i==P)
                {
                    ;
                }
                else
                {
                    if(P/i>L)
                    ans.push_back(P/i);
                }
            }
        }
        sort(ans.begin(),ans.end());
        printf("Case %d:",cas);
        if(ans.size())
        {
            for(int i=0;i<ans.size();i++)
            printf(" %d",ans[i]);
        printf("\n");
        }
        else
            printf(" impossible\n");
    }
    return 0;
}
