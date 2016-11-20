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
int n,m;
pair<int,int>pr[300005];
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0;i<n;i++)scanf("%d%d",&pr[i].first,&pr[i].second);
        sort(pr,pr+n);
        multiset<int>s;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            while(!s.empty())
            {
                int head=*s.begin();
                s.erase(s.begin());
                if(pr[i].first<=head)
                {
                    s.insert(head);
                    break;
                }
                else if(pr[i].first<=head+m+1)
                {
                    ans++;
                    break;
                }
                else
                    ;
            }
            s.insert(pr[i].first+pr[i].second-1);
        }
        printf("%d\n",ans);
    }
    return 0;
}
