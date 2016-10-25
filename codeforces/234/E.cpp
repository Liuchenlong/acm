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
#define LL long long
#define pii pair<int,int>

int n,m;
int a[100005];
set<int>s[22];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
        for(int j=0; j<20; j++)
        {
            if((a[i]&(1<<j))==0)
                s[j].insert(i);
        }
    }
    for(int i=0; i<20; i++)
    {
        s[i].insert(0);
        s[i].insert(n+1);
    }
    long long ans=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<20; j++)
        {
            if(a[i]&(1<<j))
            {
                set<int>::iterator it=s[j].lower_bound(i);
                int r=*it;
                ans+=1LL*(r-i)*(1<<j);
            }
        }
    }
    while(m--)
    {
        int pos,val;
        scanf("%d%d",&pos,&val);
        for(int i=0; i<20; i++)
        {
            if(a[pos]&(1<<i))
            {
                set<int>::iterator it=s[i].lower_bound(pos);
                int r=*it;
                int l=*--it;
                ans-=1LL*(r-pos)*(pos-l)*(1<<i);
            }
            else
                s[i].erase(s[i].find(pos));
        }
        a[pos]=val;
        for(int i=0; i<20; i++)
        {
            if(a[pos]&(1<<i))
            {
                set<int>::iterator it=s[i].lower_bound(pos);
                int r=*it;
                int l=*--it;
                ans+=1LL*(r-pos)*(pos-l)*(1<<i);
            }
            else
            {
                s[i].insert(pos);
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
