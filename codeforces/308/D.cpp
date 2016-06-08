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
int x[2005],y[2005];
int n;
int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
map<pair<int,int>,int>mp;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&x[i],&y[i]);
    }
    long long ans=0;
    for(int i=0;i<n;i++)
    {
        mp.clear();
        for(int j=0;j<n;j++)
        {
            if(i==j)continue;
            int dx=x[j]-x[i];
            int dy=y[j]-y[i];
            if(dx<0)
            {
                dx*=-1;
                dy*=-1;
            }
            if(dx==0&&dy<0)
                dy*=-1;
            int gd=gcd(dx,abs(dy));
            dx/=gd;
            dy/=gd;
            mp[make_pair(dx,dy)]++;
        }
        for(map<pair<int,int>,int>::iterator iter=mp.begin();iter!=mp.end();++iter)
        {
            int num=iter->second;
            ans+=num*(n-1-num);
        }
    }
    printf("%I64d\n",ans/6);
    return 0;
}
