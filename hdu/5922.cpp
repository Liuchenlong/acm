#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        long long n;
        scanf("%I64d",&n);
        printf("Case #%d: %I64d\n",cas,n*(n+1)/2-1);
    }
    return 0;
}
