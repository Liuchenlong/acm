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
#define eps 1e-7
const int maxn=100005;

int num[52][maxn];
bool vis[52];
int getpos(char ch)
{
    if(ch<='z'&&ch>='a')
        return ch-'a';
    return ch-'A'+26;
}
int sum[52][maxn];
int n;
char str[maxn];
int main()
{
    scanf("%d",&n);
    scanf("%s",str+1);
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<52;j++)
            sum[j][i]+=sum[j][i-1];
        sum[getpos(str[i])][i]++;
        vis[getpos(str[i])]=1;
    }
    int ans=maxn;
    for(int i=0;i<=n;i++)
    {
        int tmp=0;
        int flag=0;
        for(int j=0;j<52;j++)
        {
            if(vis[j]==0)
                continue;
            if(sum[j][n]==sum[j][i])
            {
                flag=1;
                break;
            }
            int pos=lower_bound(sum[j],sum[j]+n+1,sum[j][i]+1)-sum[j];
            tmp=max(tmp,pos-i);
        }
        if(flag)
            break;
        ans=min(ans,tmp);
    }
    printf("%d\n",ans);
    return 0;
}
