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
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) (a<0?-a:a)
#define SIZE 1000005
#define INF 0x7fffffff
struct peo
{
    int a,b;
    int num;
};
bool cmp(peo aa,peo bb)
{
    return aa.num>bb.num;
}
int vis[805];
vector <peo> vec;

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<2*n;i++)
    {
        for(int j=0;j<i;j++)
        {
            peo tmp;
            scanf("%d",&tmp.num);
            tmp.a=i+1;
            tmp.b=j+1;
            vec.push_back(tmp);
        }
    }
    sort(vec.begin(),vec.end(),cmp);
    for(int i=0;i<vec.size();i++)
    {
        if(vis[vec[i].a]==0&&vis[vec[i].b]==0)
        {
            vis[vec[i].a]=vec[i].b;
            vis[vec[i].b]=vec[i].a;
        }
    }
    for(int i=1;i<=2*n;i++)
        printf("%d ",vis[i]);
    return 0;
}
