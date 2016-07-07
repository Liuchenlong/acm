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
#define eps 1e-8
map<pair<int,int>,pair<int,int> >mp;
int n;
char str[22];
pair<int,int> getpos(int x)
{
    if(x==0)
        return make_pair(3,1);
    return make_pair((x-1)/3,(x-1)%3);
}
void init()
{
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            pair<int,int>pl,pr;
            pl=make_pair(i,j);
            pair<int,int>pi,pj;
            pi=getpos(i);
            pj=getpos(j);
            pr.first=pj.first-pi.first;
            pr.second=pj.second-pi.second;
            mp[pl]=pr;
        }
    }
}
bool intable(int x,int y)
{
    if(x==3&&y==1)return true;
    if(x>=0&&x<3&&y>=0&&y<3)return true;
    return false;
}
bool check(int x)
{
    pair<int,int>pos=getpos(x);
    for(int i=1;i<n;i++)
    {
        pair<int,int>det=mp[make_pair(str[i-1]-'0',str[i]-'0')];
        pos.first=pos.first+det.first;
        pos.second=pos.second+det.second;
        if(intable(pos.first,pos.second))
            ;
        else
            return false;
    }
    return true;
}
int main()
{
    init();
    scanf("%d",&n);
    scanf("%s",str);
    int ans=0;
    for(int i=0;i<10;i++)
    {
        if(check(i))
            ans++;
    }
    if(ans>1)
        printf("NO\n");
    else
        printf("YES\n");
    return 0;
}
