#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
using namespace std;
int a,b,c,d;
int sumz,sumo;
bool dfs(int zero,int one,int reszo,int resoz)
{
    if(zero==0&&one==0&&reszo==0&&resoz==0)
        return true;
    bool ans=0;
    if(zero>0)
    {
        if(resoz>=one)
            ans|=dfs(zero-1,one,reszo,resoz-one);
    }
    if(ans){
        printf("0");return true;
    }
    if(one>0)
    {
        if(reszo>=zero)
            ans|=dfs(zero,one-1,reszo-zero,resoz);
    }
    if(ans)
    {
        printf("1");return true;
    }
    return false;
}
int main()
{
    scanf("%d%d%d%d",&a,&b,&c,&d);
    int zeros=0,ones=0;
    for(int i=0;i<=1000000;i++)
    {
        if(i*(i-1)/2==a)
        {
            zeros=i;
            break;
        }
        else if(i*(i-1)/2>a)
        {
            zeros=-1;
            break;
        }
    }
    for(int i=0;i<=1000000;i++)
    {
        if(i*(i-1)/2==d)
        {
            ones=i;
            break;
        }
        else if(i*(i-1)/2>d)
        {
            ones=-1;
            break;
        }
    }
    if(b>0||c>0)
    {
        zeros=max(zeros,1);
        ones=max(ones,1);
    }
    if(zeros==0&&ones==0)
    {
        printf("0\n");
        return 0;
    }
    if(zeros==-1||ones==-1||zeros+ones>1000000||(long long)zeros*ones!=b+c)
    {
        printf("Impossible\n");
        return 0;
    }
    sumz=zeros;
    sumo=ones;
    bool ans=dfs(zeros,ones,b,c);
    if(ans);
    else
        printf("Impossible\n");
    return 0;
}
