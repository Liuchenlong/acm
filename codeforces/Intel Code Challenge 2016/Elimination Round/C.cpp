#include<stdio.h>
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
multiset<long long>ms;
set<int>s;
long long sum[100005];
long long num[100005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%I64d",&sum[i]);
        num[i]=sum[i];
        sum[i]+=sum[i-1];
    }
    sum[n+1]+=sum[n];
    s.insert(0);
    s.insert(n+1);
    ms.insert(-(sum[n+1]-sum[0]));
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        int r=*s.lower_bound(x);
        int l=*(--s.lower_bound(x));
        s.insert(x);
        ms.erase(ms.find(-(sum[r-1]-sum[l])));
        ms.insert(-(sum[r-1]-sum[x]));
        ms.insert(-(sum[x-1]-sum[l]));
        printf("%I64d\n",-(*ms.begin()));
    }
    return 0;
}
