#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
int n;
int pre[200005];
int father[200005];
void init()
{
    for(int i=1;i<=n;i++)
        pre[i]=i;
}
int find(int x)
{
    if(x!=pre[x])
    {
        int fx=find(pre[x]);
        pre[x]=fx;
    }
    return pre[x];
}
void Union(int x,int y)
{
    int fx=find(x);
    int fy=find(y);
    pre[fx]=fy;
}
int chos;
vector<int>vec;
int main()
{
    scanf("%d",&n);
    init();
    chos=-1;
    bool flag=false;
    for(int i=1;i<=n;i++)
        scanf("%d",&father[i]);
    for(int i=1;i<=n;i++)
    {
//        for(int j=1;j<=n;j++)
//            printf("%d ",find(j));
//        printf("\n");
        if(father[i]==i)
        {
            chos=i;
            flag=true;
            vec.push_back(i);
        }
        else
        {
            if(find(i)==find(father[i]))
            {
                vec.push_back(i);
            }
            else
            {
                Union(i,father[i]);
            }
        }
    }
    int sum;
    if(flag)
    {
        sum=vec.size()-1;
        for(int i=0;i<vec.size();i++)
        {
            father[vec[i]]=chos;
        }
    }
    else
    {
        chos=vec[0];
        sum=vec.size();
        for(int i=0;i<vec.size();i++)
        {
            father[vec[i]]=chos;
        }
    }
    printf("%d\n",sum);
    for(int i=1;i<=n;i++)
        printf("%d ",father[i]);
    printf("\n");
    return 0;
}
