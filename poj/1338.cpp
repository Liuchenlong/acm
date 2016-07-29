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
//const int maxn=1000000+100;

vector<long long>vec;
map<long long,bool>vis;
long long maxn=1e18;
int main()
{
    queue<long long>Q;
    Q.push(1);
    vis[1]=1;
    while(!Q.empty())
    {
        long long head=Q.front();
        Q.pop();
        vec.push_back(head);
        if(head*2<=maxn&&vis[head*2]==0)
        {
            vis[head*2]=1;
            Q.push(head*2);
        }
        if(head*3<=maxn&&vis[head*3]==0)
        {
            vis[head*3]=1;
            Q.push(head*3);
        }
        if(head*5<=maxn&&vis[head*5]==0)
        {
            vis[head*5]=1;
            Q.push(head*5);
        }
    }
    sort(vec.begin(),vec.end());
    int n;
    while(scanf("%d",&n),n)
    {
        printf("%I64d\n",vec[n-1]);
//        printf("The 1500'th ugly number is %lld.\n",vec[1500]);
    }
    return 0;
}
