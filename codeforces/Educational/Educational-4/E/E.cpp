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

vector <vector<int> >vec[1000005];
int ans[1000005];
int num[1000005];
bool vis[1000005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&num[i]);
    for(int i=1;i<=n;i++)
    {
        int t=i;
        vector <int>tmp;
        while(vis[t]==0)
        {
            tmp.push_back(t);
            vis[t]=true;
            t=num[t];
        }
        int siz=tmp.size();
        if(siz%2==1)
        {
            int pos=0;
            for(int j=0;j<siz;j++)
            {
                ans[tmp[j]]=tmp[(j+(siz+1)/2)%siz];
            }
        }
        else
        vec[siz].push_back(tmp);
    }
    for(int i=0;i<=1000000;i+=2)
    {
        int siz=vec[i].size();
        if(siz>0)
        {
            if(siz%2==1)
            {
                printf("-1\n");
                return 0;
            }
            else
            {
                for(int j=0;j<siz;j+=2)
                {
                    for(int k=0;k<vec[i][j].size();k++)
                    {
                        ans[vec[i][j][k]]=vec[i][j+1][k];
                        ans[vec[i][j+1][k]]=vec[i][j][(k+1)%vec[i][j].size()];
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
        printf("%d ",ans[i]);
    printf("\n");
    return 0;
}
