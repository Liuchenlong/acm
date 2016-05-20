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

int n;
int a[100005];
int lowbit(int x)
{
    return x&(-x);
}
int add(int x,int info)
{
    for(int i=x;i<=n;i+=lowbit(i))
        a[i]+=info;
}
int sum(int x)
{
    int ans=0;
    for(int i=x;i>=1;i-=lowbit(i))
        ans+=a[i];
    return ans;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        memset(a,0,sizeof(a));
        int q;
        scanf("%d%d",&n,&q);
        for(int i=1;i<=n;i++)
        {
            int data;
            scanf("%d",&data);
            add(i,data);
        }
        printf("Case %d:\n",cas);
        for(int i=0;i<q;i++)
        {
            int type;
            scanf("%d",&type);
            if(type==1)
            {
                int pos;
                scanf("%d",&pos);
                pos++;
                int det=sum(pos)-sum(pos-1);
                add(pos,-det);
                printf("%d\n",det);
            }
            if(type==2)
            {
                int pos,det;
                scanf("%d%d",&pos,&det);
                add(pos+1,det);
            }
            if(type==3)
            {
                int l,r;
                scanf("%d%d",&l,&r);
                printf("%d\n",sum(r+1)-sum(l));
            }
        }
    }
    return 0;
}
