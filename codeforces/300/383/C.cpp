#include <bits/stdc++.h>
using namespace std;
int n;
int nxt[105];
bool vis[105];
int check(int f)
{
    int now=f;
    vis[now]=1;
    int ans=1;
    now=nxt[now];
    while(vis[now]==0)
    {
        vis[now]=1;
        ans++;
        now=nxt[now];
    }
    if(now!=f)return -1;
    return ans;
}
int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int lcm(int a,int b)
{
    return a/gcd(a,b)*b;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&nxt[i]);
    int ans=1;
    for(int i=1;i<=n;i++)
    {
        if(vis[i])continue;
        int len=check(i);
        if(len==-1)
        {
            printf("-1\n");
            return 0;
        }
        if(len%2==0)
            ans=lcm(ans,len/2);
        else
            ans=lcm(ans,len);
    }
    printf("%d\n",ans);
    return 0;
}
