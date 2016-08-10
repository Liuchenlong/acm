#include<stdio.h>
#include<cmath>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<set>
#include<vector>
#include<map>
using namespace std;

struct city
{
    int pos;
    int d;
    bool operator < (const city &a)const
    {
        return d<a.d;
    }
};
city p[1005];
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&p[i].d);
            p[i].pos=i+1;
        }
        sort(p,p+n);
        bool ok=true;
        vector<pair<int,int> >ans;
        for(int i=0;i<n;i++)
        {
            if(p[i].d>i)
            {
                ok=false;
                break;
            }
            for(int j=0;j<p[i].d;j++)
                ans.push_back(make_pair(p[i].pos,p[j].pos));
        }
        printf("Case #%d: ",cas);
        if(ok)
        {
            printf("Yes\n");
            printf("%d\n",ans.size());
            for(int i=0;i<ans.size();i++)
            {
                printf("%d %d\n",ans[i].first,ans[i].second);
            }
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
