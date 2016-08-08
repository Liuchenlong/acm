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

int pre[100005];
int suf[100005];
int A[100005];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(pre,0,sizeof(pre));
        memset(suf,0,sizeof(suf));
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&A[i]);
        for(int i=2;i<=n;i++)pre[i]=max(pre[i-1],abs(A[i]-A[i-1]));
        for(int i=n-1;i>=1;i--)suf[i]=max(suf[i+1],abs(A[i+1]-A[i]));
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            if(i==1)ans+=suf[i+1];
            else if(i==n)ans+=pre[i-1];
            else ans+=max(pre[i-1],max(suf[i+1],abs(A[i+1]-A[i-1])));
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
