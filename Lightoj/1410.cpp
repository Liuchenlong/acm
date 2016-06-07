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
int x[707],y[707];
int n;
vector<int>vec;
int sqr(int x)
{
    return x*x;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        vec.clear();
        scanf("%d",&n);
        for(int i=0; i<n; i++)scanf("%d%d",&x[i],&y[i]);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                int d=sqr(x[i]-x[j])+sqr(y[i]-y[j]);
                vec.push_back(d);
            }
        }
        sort(vec.begin(),vec.end());
        ans=unique(vec.begin(),vec.end())-vec.begin();
        printf("Case %d: %d\n",cas,ans);
    }
    return 0;
}
