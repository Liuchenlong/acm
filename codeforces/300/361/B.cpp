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
#include<bitset>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
const int inf=1e8;
int n;
int a[2000005];
int d[2000005];
void bfs(int x)
{
    d[x]=0;
    queue<int>Q;
    Q.push(x);
    while(Q.size())
    {
        int head=Q.front();
        Q.pop();
        if(head>1)
        {
            if(d[head-1]>d[head]+1)
            {
                d[head-1]=d[head]+1;
                Q.push(head-1);
            }
        }
        if(head+1<=n)
        {
            if(d[head+1]>d[head]+1)
            {
                d[head+1]=d[head]+1;
                Q.push(head+1);
            }
        }
        if(d[a[head]]>d[head]+1)
        {
            d[a[head]]=d[head]+1;
            Q.push(a[head]);
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        d[i]=inf;
    bfs(1);
    for(int i=1;i<=n;i++)
        printf("%d ",d[i]);
    printf("\n");
    return 0;
}
