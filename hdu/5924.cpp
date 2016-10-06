#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        long long a,b;
        scanf("%I64d%I64d",&a,&b);
        printf("Case #%d:\n",cas);
        if(a==b)
        {
            printf("1\n");
            printf("%I64d %I64d\n",a,b);
        }
        else
        {
            printf("2\n");
            printf("%I64d %I64d\n",a,b);
            printf("%I64d %I64d\n",b,a);
        }
    }
    return 0;
}
