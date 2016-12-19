#include <bits/stdc++.h>

using namespace std;
int num[100005];
int cnt[1000005];
int n,x;
int main()
{
    scanf("%d%d",&n,&x);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
        cnt[num[i]]++;
    }
    long long ans=0;
    for(int i=0;i<n;i++)
    {
        ans+=cnt[x^num[i]];
        if(x==0)ans--;
    }
    printf("%I64d\n",ans/2);
    return 0;
}
