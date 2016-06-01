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
vector<pair<int,int> >vecx[90005];
vector<pair<int,int> >vecy[90005];
int inf=1e8;
int siz[90005];
int dpx[2][90005];
int dpy[2][90005];
int n,m,p;
int num[305][305];
int dist(pair<int,int>a,pair<int,int>b)
{
    return abs(a.first-b.first)+abs(a.second-b.second);
}
int main()
{
    scanf("%d%d%d",&n,&m,&p);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            scanf("%d",&num[i][j]);
            vecx[num[i][j]].push_back(make_pair(i,j));
            vecy[num[i][j]].push_back(make_pair(j,i));
        }
    }
    for(int i=1;i<=p;i++)
        sort(vecx[i].begin(),vecx[i].end());
    for(int i=1;i<=p;i++)
        sort(vecy[i].begin(),vecy[i].end());
    for(int i=1; i<=p; i++)
        siz[i]=vecx[i].size();
    for(int i=0; i<siz[1]; i++)
        {
            dpx[0][i]=dist(make_pair(1,1),vecx[1][i]);
            dpy[0][i]=dist(make_pair(1,1),vecy[1][i]);
        }
    int now=0,next=1;
    for(int i=2; i<=p; i++)
    {
        for(int j=0; j<siz[i]; j++)
            dpx[next][j]=dpy[next][j]=inf;
        for(int j=0; j<siz[i]; j++)
        {
            int pos=lower_bound(vecx[i-1].begin(),vecx[i-1].end(),vecx[i][j])-vecx[i-1].begin();
            for(int k=max(0,pos-50);k<min(pos+50,siz[i-1]);k++)
                dpx[next][j]=min(dpx[next][j],dpx[now][k]+dist(vecx[i-1][k],vecx[i][j]));
            pos=lower_bound(vecy[i-1].begin(),vecy[i-1].end(),vecy[i][j])-vecy[i-1].begin();
            for(int k=max(0,pos-50);k<min(pos+50,siz[i-1]);k++)
                dpy[next][j]=min(dpy[next][j],dpy[now][k]+dist(vecy[i-1][k],vecy[i][j]));
        }
        swap(now,next);
    }
    printf("%d\n",min(dpx[now][0],dpy[now][0]));
    return 0;
}
