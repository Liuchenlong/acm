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

struct obj
{
    int type;
    int x,y;
};
obj king;
vector<obj>vec1,vec2;
bool cmp(obj a,obj b)
{
    long long da=(long long)abs(a.x-king.x)+abs(a.y-king.y);
    long long db=(long long)abs(b.x-king.x)+abs(b.y-king.y);
    return da<db;
}
map<pair<int,int>,int>mp;
int main()
{
    int n;
    scanf("%d",&n);
    scanf("%d%d",&king.x,&king.y);
    for(int i=0;i<n;i++)
    {
        char str[3];scanf("%s",str);
        obj tmp;
        if(str[0]=='R')tmp.type=0;
        else if(str[0]=='B')tmp.type=1;
        else tmp.type=2;
        scanf("%d%d",&tmp.x,&tmp.y);
        if(tmp.x==king.x||tmp.y==king.y)vec1.push_back(tmp);
        else if(abs(tmp.x-king.x)==abs(tmp.y-king.y))vec2.push_back(tmp);
    }
    sort(vec1.begin(),vec1.end(),cmp);
    sort(vec2.begin(),vec2.end(),cmp);
    for(int i=0;i<vec1.size();i++)
    {
        obj tmp=vec1[i];
        tmp.x-=king.x;
        tmp.y-=king.y;
        if(tmp.x!=0)tmp.x/=abs(tmp.x);
        if(tmp.y!=0)tmp.y/=abs(tmp.y);
        if(mp[make_pair(tmp.x,tmp.y)]==0)
        {
            if(tmp.type!=1)
            {
                printf("YES\n");
                return 0;
            }
        }
        mp[make_pair(tmp.x,tmp.y)]=1;
    }
    for(int i=0;i<vec2.size();i++)
    {
        obj tmp=vec2[i];
        tmp.x-=king.x;
        tmp.y-=king.y;
        if(tmp.x!=0)tmp.x/=abs(tmp.x);
        if(tmp.y!=0)tmp.y/=abs(tmp.y);
        if(mp[make_pair(tmp.x,tmp.y)]==0)
        {
            if(tmp.type!=0)
            {
                printf("YES\n");
                return 0;
            }
        }
        mp[make_pair(tmp.x,tmp.y)]=1;
    }
    printf("NO\n");
    return 0;
}
