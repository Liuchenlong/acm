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
int n;
int a[100005];
int lowbit(int x)
{
    return x&(-x);
}
void add(int x,int info)
{
    for(int i=x; i<=n; i+=lowbit(i))
        a[i]^=1;
}
int qry(int x)
{
    int ans=0;
    for(int i=x; i>=1; i-=lowbit(i))
        ans^=a[i];
    return ans;
}
char str[100005];
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        memset(a,0,sizeof(a));
        int m;
        scanf("%s",str+1);
        scanf("%d",&m);
        int len=strlen(str+1);
        n=len;
        printf("Case %d:\n",cas);
        for(int i=0;i<m;i++)
        {
            char type[3];
            scanf("%s",type);
            if(type[0]=='I')
            {
                int l,r;
                scanf("%d%d",&l,&r);
                add(l,1);
                add(r+1,-1);
            }
            else
            {
                int pos;
                scanf("%d",&pos);
                int res=qry(pos);
                printf("%d\n",res^(str[pos]-'0'));
            }
        }
    }
    return 0;
}
