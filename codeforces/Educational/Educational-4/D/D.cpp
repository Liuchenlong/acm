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
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)<0?-(a):(a))

vector <pair<int,int> >vec;

vector <pair<int,int> >seg;
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        vec.push_back(make_pair(l,-1));
        vec.push_back(make_pair(r,1));
    }
    sort(vec.begin(),vec.end());
    int l=0,r=0;
    int num=0;
    for(int i=0;i<vec.size();i++)
    {
        if(vec[i].second==-1)
        {
            num++;
            if(num==k)
                l=vec[i].first;
        }
        else
        {
            num--;
            if(num==k-1)
            {
                r=vec[i].first;
                seg.push_back(make_pair(l,r));
            }
        }
    }
    printf("%d\n",seg.size());
    for(int i=0;i<seg.size();i++)
        printf("%d %d\n",seg[i].first,seg[i].second);
    return 0;
}
