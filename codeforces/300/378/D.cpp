#include<bits/stdc++.h>
using namespace std;
#define eps 1e-8
int num[3];

struct obj
{
    pair<pair<int,int>,int>p[3];
    int d;
    int pos;
};
bool cmp1(obj a,obj b)
{
    return a.p[0]<b.p[0];
}
bool cmp2(obj a,obj b)
{
    return a.p[1]<b.p[1];
}
bool cmp3(obj a,obj b)
{
    return a.p[2]<b.p[2];
}
int n;
obj node[100005];
int type;
pair<int,int>chos;
int ans;
void run(int tp)
{
    int now=0;
    while(now<n)
    {
        while(now+1<n&&node[now+1].p[tp].first==node[now].p[tp].first)now++;
        if(node[now-1].p[tp].first==node[now].p[tp].first)
        {
            int dnow=min(node[now].p[tp].first.first,node[now].p[tp].first.second);
            dnow=min(dnow,node[now].p[tp].second+node[now-1].p[tp].second);
            if(dnow>ans)
            {
                ans=dnow;
                type=2;
                chos=make_pair(node[now-1].pos,node[now].pos);
            }
            now++;
        }
        else
            now++;
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<3; j++)
            scanf("%d",&num[j]);
        sort(num,num+3);
        node[i].p[0]=make_pair(make_pair(num[0],num[1]),num[2]);
        node[i].p[1]=make_pair(make_pair(num[1],num[2]),num[0]);
        node[i].p[2]=make_pair(make_pair(num[0],num[2]),num[1]);
        node[i].d=min(min(num[0],num[1]),num[2]);
        node[i].pos=i+1;
    }
    type=1;
    chos=make_pair(node[0].pos,node[0].pos);
    ans=node[0].d;
    for(int i=1; i<n; i++)
    {
        if(node[i].d>ans)
        {
            ans=node[i].d;
            chos=make_pair(node[i].pos,node[i].pos);
        }
    }
    sort(node,node+n,cmp1);
    run(0);
    sort(node,node+n,cmp2);
    run(1);
    sort(node,node+n,cmp3);
    run(2);
    printf("%d\n",type);
    if(type==1)printf("%d\n",chos.first);
    else printf("%d %d\n",chos.first,chos.second);
    return 0;
}
