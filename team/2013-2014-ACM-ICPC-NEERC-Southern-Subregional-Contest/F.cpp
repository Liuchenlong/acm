#include<bits/stdc++.h>
using namespace std;
int n,m;
int cst[300005];
double p[300005];
int tim[300005];
set<pair<int,int> >s;
int main()
{
    double x;
    vector<int>vec;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)scanf("%d%lf",&cst[i],&p[i]);
    int tot=min(n,m);
    for(int i=0;i<min(n,m);i++)
    {
        tim[i]=cst[i];
        s.insert(make_pair(tim[i],i));
    }
    for(int i=tot;i<n;i++)
    {
        pair<int,int>head=*s.begin();
        s.erase(s.begin());
        tim[i]=cst[i]+head.first;
        vec.push_back(head.second);
        s.insert(make_pair(tim[i],i));
    }
    while(!s.empty())
    {
        pair<int,int>head=*s.begin();
        s.erase(s.begin());
        vec.push_back(head.second);
    }
    for(int i=1;i<n;i++)
    tim[i]=max(tim[i],tim[i-1]);
    double ans=0.0;
    double mul=0.0;
    for(int i=0;i<n;i++)
    {
        double now;
        if(i==n-1)
        now=mul+log(tim[i]);
        else
        now=mul+log(1-p[i])+log(tim[i]);
        ans+=exp(now);
        mul+=log(p[i]);
    }
    printf("%.10f\n",ans);
    return 0;
}
