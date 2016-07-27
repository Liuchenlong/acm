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
struct obj
{
    int num,a,b;
};
obj O[105];
vector<int>ans;
int n;
void solve()
{
    for(int i=0; i<10000; i++)
    {
        int numa[10]= {};
        int t=i;
        int flag=1;
        for(int j=0; j<4; j++)
        {
            numa[t%10]++;
            t/=10;
        }
        for(int j=0; j<n; j++)
        {
            int numb[10]= {};
            int A=0,B=0;
            t=i;
            int T=O[j].num;
            for(int k=0; k<4; k++)
            {
                numb[T%10]++;
                if(t%10==T%10)
                    B++;
                t/=10;
                T/=10;
            }
            for(int k=0; k<10; k++)
                A+=min(numa[k],numb[k]);
            if(!(A==O[j].a&&B==O[j].b))
            {
                flag=0;
                break;
            }

        }
        if(flag)
            ans.push_back(i);
    }
}
int main()
{
    while(scanf("%d",&n),n)
    {
        ans.clear();
        for(int i=0; i<n; i++)
            scanf("%d%d%d",&O[i].num,&O[i].a,&O[i].b);
        solve();
        if(ans.size()!=1)
            printf("Not sure\n");
        else
        {
            printf("%04d\n",ans[0]);
        }
    }
    return 0;
}
