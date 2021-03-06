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

struct node
{
    int pos;
    int dir;
    long long beg;
    long long now;
};
bool cmp(node a,node b)
{
    return a.beg<b.beg;
}
long long now[300005];
long long ans[300005];
node p[300005];
int n;
long long m,t;
int main()
{
    scanf("%d%I64d%I64d",&n,&m,&t);
    for(int i=0;i<n;i++)
    {
        char str[3];
        scanf("%I64d%s",&p[i].beg,str);
        p[i].beg--;
        if(str[0]=='L')
            p[i].dir=-1;
        else
            p[i].dir=1;
        now[i]=((p[i].beg+t*p[i].dir)%m+m)%m;
        p[i].pos=i;
    }
    sort(p,p+n,cmp);
    sort(now,now+n);
    long long add=0;
    for(int i=0;i<n;i++)
    {
        add=add+((p[i].beg+t*p[i].dir-now[i]))%(n*m);
        add%=(n*m);
    }
    add=add/m;
    add=(add%n+n)%n;
    for(int i=0;i<n;i++)
        ans[p[i].pos]=now[(i+add)%n]+1LL;
    for(int i=0;i<n;i++)
        printf("%I64d ",ans[i]);
    printf("\n");
    return 0;
}
