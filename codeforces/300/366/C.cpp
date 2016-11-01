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
#define eps 1e-12
int n,q;
vector<int>vec[300005];
int tail[300005];
int last=0;
int N;
int a[300005];
int lowbit(int x)
{
    return x&(-x);
}
int add(int x,int info)
{
    for(int i=x;i<=N;i+=lowbit(i))
    {
        a[i]+=info;
    }
}
int qry(int x)
{
    int ans=0;
    for(int i=x;i>0;i-=lowbit(i))
        ans+=a[i];
    return ans;
}
int main()
{
    scanf("%d%d",&n,&q);
    int res=0;
    N=300000;
    int pos=0;
    for(int i=1;i<=q;i++)
    {
        int type;
        scanf("%d",&type);
        if(type==1)
        {
            pos++;
            int x;
            scanf("%d",&x);
            vec[x].push_back(pos);
            res++;
            add(pos,1);
        }
        if(type==2)
        {
            int x;
            scanf("%d",&x);
            int siz=vec[x].size();
            while(tail[x]<siz)
            {
                add(vec[x][tail[x]],-1);
                tail[x]++;
            }
            res=qry(N)-qry(last);
        }
        if(type==3)
        {
            int k;
            scanf("%d",&k);
            last=max(k,last);
            res=qry(N)-qry(last);
        }
        printf("%d\n",res);
    }
    return 0;
}
