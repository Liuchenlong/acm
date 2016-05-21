#include<stdio.h>
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
int d[100005];
vector<int>road[100005];
long long topo()
{
    set<int>s;
    for(int i=0;i<n;i++)
    {
        if(d[i]==0)
            s.insert(-i);
    }
    long long tmp=1e9;
    long long ans=0;
    while(s.size())
    {
        int head=*s.begin();
        s.erase(s.begin());
        tmp=min((long long)(-head+1),tmp);
        ans+=tmp;
        for(int i=0;i<road[-head].size();i++)
        {
            d[road[-head][i]]--;
            if(d[road[-head][i]]==0)
                s.insert(-road[-head][i]);
        }
    }
    return ans;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(d,0,sizeof(d));
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)road[i].clear();
        for(int i=0;i<m;i++)
        {
            int f,t;
            scanf("%d%d",&f,&t);
            f--;
            t--;
            d[t]++;
            road[f].push_back(t);
        }
        printf("%I64d\n",topo());
    }
    return 0;
}
