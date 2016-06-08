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
pair<int,int>pr[1005];
pair<int,int>pp[1000005];
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d%d",&pr[i].first,&pr[i].second);
        int pos=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                pair<int,int>tp;
                tp.first=pr[i].first+pr[j].first;
                tp.second=pr[i].second+pr[j].second;
                pp[pos++]=tp;
            }
        }
        sort(pp,pp+pos);
        int num=1;
        for(int i=1;i<pos;i++)
        {
            if(pp[i]==pp[i-1])
                num++;
            else
            {
                ans+=num*(num-1)/2;
                num=1;
            }
        }
        ans+=num*(num-1)/2;
        printf("%d\n",ans);
    }
    return 0;
}
