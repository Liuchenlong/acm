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
#define eps 1e-9
const double pi=acos(-1.0);

int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int n;
int x[707],y[707];
int cnt;
pair<int,int>pr[707];
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d%d",&x[i],&y[i]);
        int ans=1;
        for(int i=0;i<n;i++)
        {
            cnt=0;
            for(int j=i+1;j<n;j++)
            {
                int dx=x[j]-x[i];
                int dy=y[j]-y[i];
                if(dx==0)
                {
                    pr[cnt++]=make_pair(0,1);
                }
                else
                {
                    if(dx<0){dx*=-1;dy*=-1;}
                    int GD=gcd(dx,abs(dy));
                    dx/=GD;dy/=GD;
                    pr[cnt++]=make_pair(dx,dy);
                }
            }
            sort(pr,pr+cnt);
            int now=1;
            for(int j=1;j<=cnt;j++)
            {
                if(j==cnt)
                {
                    ans=max(ans,now+1);
                    break;
                }
                if(pr[j]==pr[j-1])now++;
                else
                {
                    ans=max(ans,now+1);
                    now=1;
                }
            }
        }
        printf("Case %d: %d\n",cas,ans);
    }
    return 0;
}
