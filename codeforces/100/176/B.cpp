#include <bits/stdc++.h>

using namespace std;
long long n,k;
int main()
{
    scanf("%I64d%I64d",&n,&k);
    k--;
    long long mx=k*(k+1)/2+1;
    if(n>mx)
        printf("-1");
    else if(n==mx)
    {
        printf("%I64d\n",k);
    }
    else if(n==1)
    {
        printf("0\n");
    }
    else
    {
        long long l=1,r=k;
        while(l<r)
        {
            long long mid=(l+r)/2;
            long long val=mid*(mid+1)/2;
            if(mx-val>=n)
                l=mid+1;
            else
                r=mid;
        }
        printf("%I64d\n",k-l+1);
    }
    return 0;
}
