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
const int mod=1000000007;
int n=1001;
int a[1005][1005];
int lowbit(int x)
{
    return x&(-x);
}
void add(int x,int y,int info)
{
    for(int i=x;i<=n;i+=lowbit(i))
        for(int j=y;j<=n;j+=lowbit(j))
            a[i][j]+=info;
}
int qry(int x,int y)
{
    int sum=0;
    for(int i=x;i>0;i-=lowbit(i))
        for(int j=y;j>0;j-=lowbit(j))
            sum+=a[i][j];
    return sum;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        memset(a,0,sizeof(a));
        int q;
        scanf("%d",&q);
        printf("Case %d:\n",cas);
        for(int i=0;i<q;i++)
        {
            int type;
            scanf("%d",&type);
            if(type==0)
            {
                int x,y;
                scanf("%d%d",&x,&y);
                x++;
                y++;
                if(qry(x,y)-qry(x-1,y)-qry(x,y-1)+qry(x-1,y-1)==0)
                add(x,y,1);
            }
            else
            {
                int x1,y1,x2,y2;
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                x1++;y1++;x2++;y2++;
                printf("%d\n",qry(x2,y2)-qry(x1-1,y2)-qry(x2,y1-1)+qry(x1-1,y1-1));
            }
        }
    }
    return 0;
}
