#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    if(n==2)printf("-1\n");
    else
    {
        printf("%d\n%d\n%d\n",2*3,3*5,2*5);
        n-=3;
        long long val=2*3*5;
        for(int i=1;i<=n;i++)
            printf("%I64d\n",val*i);
    }
    return 0;
}
