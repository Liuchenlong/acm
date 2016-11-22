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
const long long inf=(1LL<<60);
int n,s;
int a[200005];
int cnt[200005];
int sum[200005];
int main()
{
    scanf("%d%d",&n,&s);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    int ans=100000000;
    int sbld=0;
    int sb=0;
    if(a[s]!=0)sbld=1;
    if(n==1)
    {
        printf("%d\n",min(ans,sbld));
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]==0&&i!=s)
            sb++;
    }
    for(int i=1;i<=n;i++)
    {
        if(i==s)continue;
        if(a[i]==0)continue;
        cnt[a[i]]++;
    }
    for(int i=1;i<n;i++)
        sum[i]=sum[i-1]+cnt[i];
    int need=0;
    for(int i=1;i<n;i++)
    {
        if(cnt[i]==0)
            need++;
        int sbnow=sum[n-1]-sum[i]+sb;
        if(sbnow>=need)
            ans=min(ans,sbnow+sbld);
        else
        {
            ans=min(ans,need+sbld);
        }
    }
    printf("%d\n",ans);
    return 0;
}
